
// RichNotepadMinusMinusView.cpp : implementation of the CRichNotepadMinusMinusView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RichNotepadMinusMinus.h"
#endif

#include "RichNotepadMinusMinusDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "RichNotepadMinusMinusView.h"

#include "UtilityFunctions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRichNotepadMinusMinusView

IMPLEMENT_DYNCREATE(CRichNotepadMinusMinusView, CRichEditView)

BEGIN_MESSAGE_MAP(CRichNotepadMinusMinusView, CRichEditView)
	ON_WM_DESTROY()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRichNotepadMinusMinusView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CRichNotepadMinusMinusView construction/destruction

CRichNotepadMinusMinusView::CRichNotepadMinusMinusView()
{
	// TODO: add construction code here

}

CRichNotepadMinusMinusView::~CRichNotepadMinusMinusView()
{
}

BOOL CRichNotepadMinusMinusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CRichNotepadMinusMinusView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Set the printing margins (720 twips = 1/2 inch)
	SetMargins(CRect(720, 720, 720, 720));
}


// CRichNotepadMinusMinusView printing


void CRichNotepadMinusMinusView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRichNotepadMinusMinusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CRichNotepadMinusMinusView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}


void CRichNotepadMinusMinusView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRichNotepadMinusMinusView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRichNotepadMinusMinusView diagnostics

#ifdef _DEBUG
void CRichNotepadMinusMinusView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CRichNotepadMinusMinusView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CRichNotepadMinusMinusDoc* CRichNotepadMinusMinusView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRichNotepadMinusMinusDoc)));
	return (CRichNotepadMinusMinusDoc*)m_pDocument;
}
#endif //_DEBUG


// CRichNotepadMinusMinusView message handlers


void CRichNotepadMinusMinusView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
  CRichNotepadMinusMinusDoc* pDoc = GetDocument();
  auto lines = pDoc->GetLines();

  dispTxt = "";

  if (lines.size() > 0)
  {
    for (int i = 0; i < lines.size(); i++)
    {
      dispTxt += lines[i] + "\r\n";
    }
    SetWindowText(ToCString(dispTxt));
  }
}
