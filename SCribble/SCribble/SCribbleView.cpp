
// SCribbleView.cpp : implementation of the CSCribbleView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SCribble.h"
#endif

#include "SCribbleDoc.h"
#include "SCribbleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSCribbleView

IMPLEMENT_DYNCREATE(CSCribbleView, CView)

BEGIN_MESSAGE_MAP(CSCribbleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSCribbleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSCribbleView construction/destruction

CSCribbleView::CSCribbleView() noexcept
{
	// TODO: add construction code here

}

CSCribbleView::~CSCribbleView()
{
}

BOOL CSCribbleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSCribbleView drawing

void CSCribbleView::OnDraw(CDC* /*pDC*/)
{
	CSCribbleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSCribbleView printing


void CSCribbleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSCribbleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSCribbleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSCribbleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSCribbleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSCribbleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSCribbleView diagnostics

#ifdef _DEBUG
void CSCribbleView::AssertValid() const
{
	CView::AssertValid();
}

void CSCribbleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSCribbleDoc* CSCribbleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSCribbleDoc)));
	return (CSCribbleDoc*)m_pDocument;
}
#endif //_DEBUG


// CSCribbleView message handlers
