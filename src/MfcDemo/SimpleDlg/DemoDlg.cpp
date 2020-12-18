// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleDlg.h"
#include "DemoDlg.h"
#include "afxdialogex.h"


// DemoDlg dialog

IMPLEMENT_DYNAMIC(DemoDlg, CDialogEx)

DemoDlg::DemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DemoDlg::IDD, pParent)
{

}

DemoDlg::~DemoDlg()
{
}

void DemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DemoDlg, CDialogEx)
END_MESSAGE_MAP()


// DemoDlg message handlers
