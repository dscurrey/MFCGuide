
// SimpleDlgView.h : interface of the CSimpleDlgView class
//

#pragma once


class CSimpleDlgView : public CView
{
protected: // create from serialization only
	CSimpleDlgView();
	DECLARE_DYNCREATE(CSimpleDlgView)

// Attributes
public:
	CSimpleDlgDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSimpleDlgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnToolsDemodialog();
};

#ifndef _DEBUG  // debug version in SimpleDlgView.cpp
inline CSimpleDlgDoc* CSimpleDlgView::GetDocument() const
   { return reinterpret_cast<CSimpleDlgDoc*>(m_pDocument); }
#endif

