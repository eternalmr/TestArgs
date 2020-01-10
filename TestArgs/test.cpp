#include "pch.h"

// 项目需求:写一个解释器,能够正确解析输入的参数
// 首先要定义一个合理的参数结构
// -I 形式的只有标记没有参数的是bool型的参数
// -p 8800形式的是port对应的8800参数
// 对于没有输入的参数应该有默认值
// 若输入的参数错误应该有错误提示
// 应该具有良好的可扩展性
// 当一个标记对应多个值的时候,要把这些值用列表的形式存下来
#include <string>
#include <vector>
#include <regex>

using std::string;
using std::vector;

class Schema {
public:
	Schema() : param_num(3),I(false),p(8800),d("desktop\cr") {
		param_vector.push_back("-I");
		param_vector.push_back("-p");
		param_vector.push_back("-d");
	}
	
	bool operator==(const Schema &schema) const{
		if (d == schema.d && I == schema.I&& p == schema.p)
			return true;
		return false;
	}

public:
	vector<string> param_vector;
	int param_num;
	bool I;
	int p;
	std::string d;
};

bool find_s_in_string(std::string &s, std::string &string)
{
	return string.find(s) != std::string::npos;
}

Schema my_parse(std::string str)
{
	Schema schema;

	for (auto s : schema.param_vector) {
		if (find_s_in_string(s, str)) {
			if (s == "-I") schema.I = true;
			if (s == "-p") schema.p = 1217;
			if (s == "-d") schema.d = "desktop\zlm";
		}
	}

	return schema;
}

std::vector<string> split_string(const string& in, const string& delim)
{
	//用delim指定的正则表达式将字符串in分割，返回分割后的字符串数组
	//delim 分割字符串的正则表达式
	std::regex re{ delim };
	return std::vector<string> {
		std::sregex_token_iterator(in.begin(), in.end(), re, -1),
			std::sregex_token_iterator()
	};
}

//1. 解析器会首先验证参数列表是否与参数结构相匹配。
//2. 然后，程序就可以向参数解析器查询每个参数的值（根据参数的标记名）。
//3. 返回值的类型应该与参数结构中规定的类型相一致。

// 感觉还是要用一个正则表达式来做，先将输入进行分割，再判断输出vector中是啥
// 或者用循环的方式来做，找到“-”，再判断后面的字母

Schema schema;

TEST(seperate_string_with_seperators) {
	std::vector<string> result = split_string("-I -p 8800 -d desktop\cr", " ");
	EXPECT_EQ(result[0], "-I");
	EXPECT_EQ(result[1], "-p");
	EXPECT_EQ(result[2], "8800");
}


TEST(if_input_contain_d_schema_d_should_equal_d_parameter) {
	std::string input = "-d";
	EXPECT_EQ(my_parse(input).d, "desktop\zlm");
}


TEST(if_input_contain_p_schema_p_should_equal_p_parameter) {
	std::string input = "-p";
	EXPECT_EQ(my_parse(input).p, 1217);
}


TEST(if_input_contain_I_schema_I_should_be_true) {
	std::string input = "-I";
	EXPECT_TRUE(my_parse(input).I);
}

TEST(my_parse_should_return_a_schema_according_to_input) {
	EXPECT_EQ(my_parse("test string"), schema);
}


TEST(schema_should_have_3_parameters) {
	EXPECT_EQ(schema.param_num, 3);
}

TEST(schema,I) {
	EXPECT_EQ(typeid(schema.I), typeid(bool));
	EXPECT_EQ(schema.I, false);
}

TEST(schema,p) {
	EXPECT_EQ(typeid(schema.p), typeid(int));
	EXPECT_EQ(schema.p, 8800);
}

TEST(schema, d)
{
	EXPECT_EQ(typeid(schema.d), typeid(std::string));
	EXPECT_EQ(schema.d, "desktop\cr");
}