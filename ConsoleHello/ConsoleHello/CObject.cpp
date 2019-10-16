#include "pch.h"
#include "CObject.h"
#include "My.h"
#include <iostream>

extern MyWinApp theApp;

CObject::CObject()
{
	std::cout << "CObject Constructor" << std::endl;
}


CObject::~CObject()
{
	std::cout << "COject Destructor\n";
}

CCmdTarget::CCmdTarget()
{
	std::cout << "CCmdTarget Constructor\n";
}

CCmdTarget::~CCmdTarget()
{
	std::cout << "CCmdTarget Destructor\n";
}

CWinThread::CWinThread()
{
	std::cout << "CWinThread Constructor\n";
}

CWinThread::~CWinThread()
{
	std::cout << "CWinThread Destructor\n";
}

CWinAPP::CWinAPP()
{
	m_pCurrentWinApp = this;
	std::cout << "CWinApp Constructor\n";
}
CWinAPP::~CWinAPP()
{
	delete m_pCurrentWinApp;
	std::cout << "CWinApp Destructor\n";
}

bool CWnd::Create()
{
	std::cout << " CWnd Create\n";
	return true;
}

bool CWnd::CreateEx()
{
	std::cout << " CWnd CreateEx\n";
	PreCreateWindow();
	return true;
}

bool CWnd::PreCreateWindow()
{
	std::cout << " CWnd PreCreateWindow\n";
	return true;
}

bool CFrameWnd::Create()
{
	std::cout << " CFrameWnd Create\n";
	CreateEx();
	return true;
}

bool CFrameWnd::PreCreateWindow()
{
	std::cout << " CFrameWnd PreCreateWindow\n";
	return true;
}
CWinAPP* AfxGetApp()
{
	return  theApp.m_pCurrentWinApp;
}
