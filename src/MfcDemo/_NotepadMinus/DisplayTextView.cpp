// DisplayTextView.cpp : implementation file
//

#include "stdafx.h"
#include "NotepadMinus.h"
#include "DisplayTextView.h"


// CDisplayTextView

IMPLEMENT_DYNCREATE(CDisplayTextView, CFormView)

CDisplayTextView::CDisplayTextView()
	: CFormView(CDisplayTextView::IDD)
{

}

CDisplayTextView::~CDisplayTextView()
{
}

void CDisplayTextView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDisplayTextView, CFormView)
END_MESSAGE_MAP()


// CDisplayTextView diagnostics

#ifdef _DEBUG
void CDisplayTextView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDisplayTextView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDisplayTextView message handlers
