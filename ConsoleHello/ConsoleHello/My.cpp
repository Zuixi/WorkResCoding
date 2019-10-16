#include "pch.h"
#include "My.h"
#include <iostream>


MyWinApp::MyWinApp()
{
	std::cout << " MyWinApp Constructor\n";
}


MyWinApp::~MyWinApp()
{
	std::cout << " MyWinApp Destructor\n";
}

bool MyWinApp::InitInstance()
{
	std::cout << " MyWinApp InitInstance\n";
	m_pMainnd = new CFrameWnd;
	return true;

}
