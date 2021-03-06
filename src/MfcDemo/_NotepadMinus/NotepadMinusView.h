
// NotepadMinusView.h : interface of the CNotepadMinusView class
//

#pragma once


class CNotepadMinusView : public CView
{
protected: // create from serialization only
	CNotepadMinusView();
	DECLARE_DYNCREATE(CNotepadMinusView)

// Attributes
public:
	CNotepadMinusDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CNotepadMinusView();
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
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // debug version in NotepadMinusView.cpp
inline CNotepadMinusDoc* CNotepadMinusView::GetDocument() const
   { return reinterpret_cast<CNotepadMinusDoc*>(m_pDocument); }
#endif

