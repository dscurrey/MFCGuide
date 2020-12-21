
// NotepadMinusMinusView.cpp : implementation of the CNotepadMinusMinusView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NotepadMinusMinus.h"
#endif

#include "NotepadMinusMinusDoc.h"
#include "NotepadMinusMinusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadMinusMinusView

IMPLEMENT_DYNCREATE(CNotepadMinusMinusView, CEditView)

BEGIN_MESSAGE_MAP(CNotepadMinusMinusView, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNotepadMinusMinusView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CNotepadMinusMinusView construction/destruction

CNotepadMinusMinusView::CNotepadMinusMinusView()
{
	// TODO: add construction code here

}

CNotepadMinusMinusView::~CNotepadMinusMinusView()
{
}

BOOL CNotepadMinusMinusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CNotepadMinusMinusView printing


void CNotepadMinusMinusView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CNotepadMinusMinusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CNotepadMinusMinusView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CNotepadMinusMinusView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

void CNotepadMinusMinusView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CNotepadMinusMinusView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CNotepadMinusMinusView diagnostics

#ifdef _DEBUG
void CNotepadMinusMinusView::AssertValid() const
{
	CEditView::AssertValid();
}

void CNotepadMinusMinusView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CNotepadMinusMinusDoc* CNotepadMinusMinusView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNotepadMinusMinusDoc)));
	return (CNotepadMinusMinusDoc*)m_pDocument;
}
#endif //_DEBUG


// CNotepadMinusMinusView message handlers
