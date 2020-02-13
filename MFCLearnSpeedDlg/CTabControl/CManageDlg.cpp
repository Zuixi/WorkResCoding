// CManageDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "CTabControl.h"
#include "CManageDlg.h"
#include "afxdialogex.h"


// CManageDlg 对话框

IMPLEMENT_DYNAMIC(CManageDlg, CDialogEx)

CManageDlg::CManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CManageDlg::~CManageDlg()
{
}

void CManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CManageDlg, CDialogEx)
END_MESSAGE_MAP()


// CManageDlg 消息处理程序
