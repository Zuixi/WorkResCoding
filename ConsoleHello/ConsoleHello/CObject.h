#pragma once
#include <iostream>

#define BOOL int
#define TRUE 1
#define FALSE 0
#define LPCSTR LPSTR
typedef char* LPSTR;
#define UINT int
#define PASCAL _stdcall


class CObject;
struct CRuntimeClass
{
	LPSTR m_lpszClassName;
	int m_nObjecSize;
};

class CObject
{
public:
	CObject();
	~CObject();
};

class CCmdTarget :public CObject
{
public:
	CCmdTarget();
	~CCmdTarget();
};

class CWinThread :public CCmdTarget
{
public:
	CWinThread();
	~CWinThread();

	virtual bool InitInstance()
	{
		std::cout << "CWinThread Initstance\n";
		return true;
	}

	virtual int Run()
	{
		std::cout << "CWinThread Run\n";
		return 1;
	}


};

class CWinAPP :public CWinThread
{
public:
	CWinAPP* m_pCurrentWinApp;
	CWnd* m_pMainnd;

public:
	CWinAPP();
	~CWinAPP();

	virtual bool InitApplication()
	{
		std::cout << " CWinApp InitApplication\n";
		return true;
	}

	virtual bool InitInstance()
	{
		std::cout << " CWinApp InitInstance\n";
		return true;
	}

	virtual int Run()
	{
		std::cout << "CWinApp Run\n";
		return CWinThread::Run();
	}
};

class CDocument :public CCmdTarget
{
public:
	CDocument()
	{
		std::cout << "CDocument Constructor\n";
	}

	~CDocument()
	{
		std::cout << "CDocument Destructor\n";
	}
};

class CWnd :public CCmdTarget
{
public:
	CWnd()
	{
		std::cout << "CWnd Constructor\n";
	}

	~CWnd()
	{
		std::cout << " CWnd Destructor\n";
	}

	virtual bool Create();
	bool CreateEx();
	virtual bool PreCreateWindow();
		
};

class CFrameWnd :public CWnd
{
public:
	CFrameWnd()
	{
		std::cout << "CFrameWnd Construcotr\n";
	}

	~CFrameWnd()
	{
		std::cout << "CFrameWnd Destructor\n";
	}

	bool Create();
	virtual bool PreCreateWindow();
};

class CView :public CWnd
{
public:
	CView()
	{
		std::cout << "CView Constructor\n";
	}

	~CView()
	{
		std::cout << "CView Destructor\n";
	}
};


// global values
CWinAPP* AfxGetApp();
