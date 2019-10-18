#pragma once
#include <iostream>

#define BOOL int
#define TRUE 1
#define FALSE 0
#define LPCSTR LPSTR
typedef char* LPSTR;
#define UINT int
#define PASCAL _stdcall

/* 
关于宏定义的一些说明：

	## 表示连接两个符号，从而产生新的符号， eg X##Y => XY 
	#@x 表示给x加上单引号 返回一个char
	#x 表示给x加上双引号,返回一个string

	\ 表示宏体需要换行 ，相当于宏函数
    ; 分号在宏定义中存在分号吞噬问题；
	
	#undef 宏名 取消宏定义


	#ifdef
	#else
	#elig
	#endif



*/


class CObject;
struct CRuntimeClass
{
	LPSTR m_lpszClassName;
	int m_nObjecSize;
	UINT m_wSchema;    // schema number of the load class
	CObject* (PASCAL* m_pfnCreateObject)();    // NULL => abstract class
	CRuntimeClass* m_pBaseClass;

	// CRuntimeClass Object linked together in simple list
	static CRuntimeClass* pFirstClass;    // start of the class list
	CRuntimeClass* m_pNextClass;    // linked list of register classes
};

struct AFX_CLASSINIT
{
	AFX_CLASSINIT(CRuntimeClass* pNewClass);
};

#define RUNTIME_CLASS(className) \
	(&className::class##className)

#define DECLARE_DYNAMIC(className) \
public: \
	static CRuntimeClass class##className; \
	virtual CRuntimeClass* GetRunTimeClass() const;

#define _IMPLEMENT_RUNTIMECLASS(className,baseClassName,cShema,pfnNew) \
	static char _lpsz##className[] = #className; \	
	CRuntimeClass className::class##className ={ \
		lpszclassName , sizeof(className) , cSchema , pfnNew, RUNTIME_CLASS(baseClassName) , NULL};\
		static AFX_CLASSINIT _init_##className(&className::class##className); \
	CRuntimeClass* className::GetRunTimeClass() const\
		{
		    return &className::class##className;
	    }\
	

#define IMPLEMENT_DYNAMIC(className,baseClassName) \  
	_IMPLEMENT_RUNTIMECLASS(className,baseClassName,0xFFFF,NULL)



class CObject
{
public:
	CObject();
	~CObject();
	virtual CRuntimeClass* GetRunTimeClass() const;  

public:
	static CRuntimeClass classCObject;
};

class CCmdTarget :public CObject
{
	DECLARE_DYNAMIC(CCmdTarget)
public:
	CCmdTarget();
	~CCmdTarget();

};

class CWinThread :public CCmdTarget
{
	DECLARE_DYNAMIC(CWinThread)
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
	DECLARE_DYNAMIC(CWinAPP)
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
	DECLARE_DYNAMIC(CDocment)
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
	DECLARE_DYNAMIC(CWnd)
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
	DECLARE_DYNAMIC(CFrameWnd)
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
	DECLARE_DYNAMIC(CView)
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
