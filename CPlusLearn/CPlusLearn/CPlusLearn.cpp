// CPlusLearn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>  
#include <thread>
#include "Shape.h"
#include "Mytime.h"

void doSomeWork()
{
	std::cout << "hello world\n";
}

void do_something()
{
	std::cout << "do something" << std::endl;
}

void do_somethingelse()
{
	std::cout << "do something else" << std::endl;
}
class back_ground_task
{
public:
	void operator() ()
	{
		do_something();;
		do_somethingelse();
	}
};

int main()
{
	back_ground_task f;
	std::thread((back_ground_task()));
    std::cout << "Hello World!\n"; 
	std::thread t(doSomeWork);
	t.join();

	Shape myshape;

	MyTime planing;
	MyTime coding(2, 23, 12);
	MyTime fixing(3, 43, 12);
	MyTime total;

	std::cout << "planing time = ";
	planing.show();
	std::cout << std::endl;

	std::cout << "coding time = ";
	coding.show();
	std::cout << std::endl;

	std::cout << "fixing time = ";
	fixing.show();
	std::cout << std::endl;

	total = coding.Sum(fixing);
	std::cout << "total time = ";
	total.show();
	std::cout << std::endl;

	std::cout << "use opetator * with time" << std::endl;
	MyTime newTime(3, 23, 12);
	newTime = 4 * newTime;
	newTime.show();

	return 0;
}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
