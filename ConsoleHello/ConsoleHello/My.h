#pragma once
#include "CObject.h"

class MyWinApp :
	public CWinAPP
{
public:
	MyWinApp();
	~MyWinApp();
	virtual bool InitInstance();
};

class MyFrame :public CFrameWnd
{
	MyFrame()
	{
		std::cout << " MyFrame Constructor\n";
		Create();
	}

	~MyFrame()
	{
		std::cout << " MyFrame Destructor\n";
	}
};
