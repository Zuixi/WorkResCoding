// ConsoleHello.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CEployee.h"
#include "My.h"
#include "CObject.h"

MyWinApp theApp;   // global values

#pragma warning(disable:4996)

int main()
{

	CWinAPP* pApp = AfxGetApp();
	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();


    std::cout << "Hello World!\n"; 
	// 使用父类指针来使用继承类
	Employee* pemployee;

	CManger manger("程美静");
	CSales saleMan("李梅");
	CWage aWager("小明");
	pemployee = &manger;
	pemployee = &saleMan;
	pemployee = &aWager;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
