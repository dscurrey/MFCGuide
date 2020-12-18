
// SimpleDlgView.cpp : implementation of the CSimpleDlgView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SimpleDlg.h"
#endif

#include "SimpleDlgDoc.h"
#include "SimpleDlgView.h"
#include "DemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimpleDlgView

IMPLEMENT_DYNCREATE(CSimpleDlgView, CView)

BEGIN_MESSAGE_MAP(CSimpleDlgView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
  ON_COMMAND(ID_TOOLS_DEMODIALOG, &CSimpleDlgView::OnToolsDemodialog)
END_MESSAGE_MAP()

// CSimpleDlgView construction/destruction

CSimpleDlgView::CSimpleDlgView()
{
	// TODO: add construction code here

}

CSimpleDlgView::~CSimpleDlgView()
{
}

BOOL CSimpleDlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSimpleDlgView drawing

void CSimpleDlgView::OnDraw(CDC* /*pDC*/)
{
	CSimpleDlgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CSimpleDlgView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSimpleDlgView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSimpleDlgView diagnostics

#ifdef _DEBUG
void CSimpleDlgView::AssertValid() const
{
	CView::AssertValid();
}

void CSimpleDlgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimpleDlgDoc* CSimpleDlgView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimpleDlgDoc)));
	return (CSimpleDlgDoc*)m_pDocument;
}
#endif //_DEBUG


// CSimpleDlgView message handlers


void CSimpleDlgView::OnToolsDemodialog()
{
  DemoDlg dlgDemo;
  dlgDemo.DoModal();
}
