
// RichNotepadMinusMinusView.h : interface of the CRichNotepadMinusMinusView class
//

#pragma once

class CRichNotepadMinusMinusCntrItem;

class CRichNotepadMinusMinusView : public CRichEditView
{
protected: // create from serialization only
	CRichNotepadMinusMinusView();
	DECLARE_DYNCREATE(CRichNotepadMinusMinusView)

// Attributes
public:
	CRichNotepadMinusMinusDoc* GetDocument() const;
  std::vector<std::string> GetLines() { return m_lines; }

private:
  std::vector<std::string> m_lines;
  std::string dispTxt;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CRichNotepadMinusMinusView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
  virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // debug version in RichNotepadMinusMinusView.cpp
inline CRichNotepadMinusMinusDoc* CRichNotepadMinusMinusView::GetDocument() const
   { return reinterpret_cast<CRichNotepadMinusMinusDoc*>(m_pDocument); }
#endif

