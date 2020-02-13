
// MFCLearnSpeedDlgView.cpp: CMFCLearnSpeedDlgView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCLearnSpeedDlg.h"
#endif

#include "MFCLearnSpeedDlgDoc.h"
#include "MFCLearnSpeedDlgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCLearnSpeedDlgView

IMPLEMENT_DYNCREATE(CMFCLearnSpeedDlgView, CView)

BEGIN_MESSAGE_MAP(CMFCLearnSpeedDlgView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCLearnSpeedDlgView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCLearnSpeedDlgView 构造/析构

CMFCLearnSpeedDlgView::CMFCLearnSpeedDlgView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCLearnSpeedDlgView::~CMFCLearnSpeedDlgView()
{
}

BOOL CMFCLearnSpeedDlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCLearnSpeedDlgView 绘图

void CMFCLearnSpeedDlgView::OnDraw(CDC* /*pDC*/)
{
	CMFCLearnSpeedDlgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCLearnSpeedDlgView 打印


void CMFCLearnSpeedDlgView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCLearnSpeedDlgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCLearnSpeedDlgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCLearnSpeedDlgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCLearnSpeedDlgView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCLearnSpeedDlgView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCLearnSpeedDlgView 诊断

#ifdef _DEBUG
void CMFCLearnSpeedDlgView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCLearnSpeedDlgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCLearnSpeedDlgDoc* CMFCLearnSpeedDlgView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCLearnSpeedDlgDoc)));
	return (CMFCLearnSpeedDlgDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCLearnSpeedDlgView 消息处理程序
