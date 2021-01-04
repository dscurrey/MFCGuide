#pragma once


// CFontDlg dialog

class CFontDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFontDlg)

public:
	CFontDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFontDlg();

// Dialog Data
	enum { IDD = IDD_FONTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  int edtFontSize;
};
