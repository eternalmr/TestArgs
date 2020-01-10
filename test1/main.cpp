#include <vector>
#include <iostream>
#include <thread>

void fun1(int &x)
{
	x = 2;
	std::cout << "set x = 2 in fun1" << std::endl;
}


void fun2(int &x)
{
	x = 3;
	std::cout << "set x = 3 in fun2" << std::endl;
}

int main()
{
	int x = 0;
	std::cout << "set x = 0 in main"<<std::endl;

	std::thread t1 = std::thread(fun1, std::ref(x));
	std::cout << "after call fun1, x = "<< x <<" in main"<<std::endl;

	std::thread t2 = std::thread(fun2, std::ref(x));
	std::cout << "after call fun2, x = " << x << " in main"<<std::endl;

	t1.join();
	t2.join();
	system("pause");
	return 0;
}