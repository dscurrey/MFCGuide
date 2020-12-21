#pragma once



// CDisplayTextView form view

class CDisplayTextView : public CFormView
{
	DECLARE_DYNCREATE(CDisplayTextView)

protected:
	CDisplayTextView();           // protected constructor used by dynamic creation
	virtual ~CDisplayTextView();

public:
	enum { IDD = IDD_DISPTXT_DLG };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};


