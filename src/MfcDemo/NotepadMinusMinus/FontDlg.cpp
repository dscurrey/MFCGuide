// FontDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NotepadMinusMinus.h"
#include "FontDlg.h"
#include "afxdialogex.h"


// CFontDlg dialog

IMPLEMENT_DYNAMIC(CFontDlg, CDialogEx)

CFontDlg::CFontDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFontDlg::IDD, pParent)
  , edtFontSize(14)
{

}

CFontDlg::~CFontDlg()
{
}

void CFontDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Text(pDX, IDC_FONTSIZE_EDT, edtFontSize);
	DDV_MinMaxInt(pDX, edtFontSize, 1, 100);
}


BEGIN_MESSAGE_MAP(CFontDlg, CDialogEx)
END_MESSAGE_MAP()


// CFontDlg message handlers
