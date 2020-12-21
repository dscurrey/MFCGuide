
// NotepadMinusView.cpp : implementation of the CNotepadMinusView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NotepadMinus.h"
#endif

#include "NotepadMinusDoc.h"
#include "NotepadMinusView.h"

#include "UtilityFunctions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadMinusView

IMPLEMENT_DYNCREATE(CNotepadMinusView, CView)

BEGIN_MESSAGE_MAP(CNotepadMinusView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNotepadMinusView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
  ON_WM_CREATE()
END_MESSAGE_MAP()

// CNotepadMinusView construction/destruction

CNotepadMinusView::CNotepadMinusView()
{
	// TODO: add construction code here

}

CNotepadMinusView::~CNotepadMinusView()
{
}

BOOL CNotepadMinusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CNotepadMinusView drawing

void CNotepadMinusView::OnDraw(CDC* pDC)
{
	CNotepadMinusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
  auto lines = pDoc->GetLines();
  int nextY = 0;
  for (int i = 0; i < lines.size(); i++)
  {    
    pDC->TextOutW(0, nextY, toCString(lines[i]));
    nextY += 20;
  }
}


// CNotepadMinusView printing


void CNotepadMinusView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CNotepadMinusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNotepadMinusView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNotepadMinusView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CNotepadMinusView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CNotepadMinusView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CNotepadMinusView diagnostics

#ifdef _DEBUG
void CNotepadMinusView::AssertValid() const
{
	CView::AssertValid();
}

void CNotepadMinusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNotepadMinusDoc* CNotepadMinusView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNotepadMinusDoc)));
	return (CNotepadMinusDoc*)m_pDocument;
}
#endif //_DEBUG


// CNotepadMinusView message handlers


int CNotepadMinusView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  if (CView::OnCreate(lpCreateStruct) == -1)
    return -1;

  // TODO:  Add your specialized creation code here


  return 0;
}
