
// MfcDemoDlg.h : header file
//

#pragma once


// CMfcDemoDlg dialog
class CMfcDemoDlg : public CDialogEx
{
// Construction
public:
	CMfcDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedDemoBtn();
private:
  CString StaticTextDemo;
};
