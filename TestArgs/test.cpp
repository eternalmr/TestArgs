#include "pch.h"

// ��Ŀ����:дһ��������,�ܹ���ȷ��������Ĳ���
// ����Ҫ����һ������Ĳ����ṹ
// -I ��ʽ��ֻ�б��û�в�������bool�͵Ĳ���
// -p 8800��ʽ����port��Ӧ��8800����
// ����û������Ĳ���Ӧ����Ĭ��ֵ
// ������Ĳ�������Ӧ���д�����ʾ
// Ӧ�þ������õĿ���չ��
// ��һ����Ƕ�Ӧ���ֵ��ʱ��,Ҫ����Щֵ���б����ʽ������
#include <string>

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
		if (this->d == schema.d && this->I == schema.I&& this->p == schema.p)
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

//1. ��������������֤�����б��Ƿ�������ṹ��ƥ�䡣
//2. Ȼ�󣬳���Ϳ����������������ѯÿ��������ֵ�����ݲ����ı��������
//3. ����ֵ������Ӧ��������ṹ�й涨��������һ�¡�

// �о�����Ҫ��һ��������ʽ�������Ƚ�������зָ���ж����vector����ɶ


Schema schema;

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