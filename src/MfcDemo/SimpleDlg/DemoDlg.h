#pragma once


// DemoDlg dialog

class DemoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DemoDlg)

public:
	DemoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~DemoDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
