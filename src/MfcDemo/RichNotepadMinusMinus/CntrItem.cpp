
// CntrItem.cpp : implementation of the CRichNotepadMinusMinusCntrItem class
//

#include "stdafx.h"
#include "RichNotepadMinusMinus.h"

#include "RichNotepadMinusMinusDoc.h"
#include "RichNotepadMinusMinusView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRichNotepadMinusMinusCntrItem implementation

IMPLEMENT_SERIAL(CRichNotepadMinusMinusCntrItem, CRichEditCntrItem, 0)

CRichNotepadMinusMinusCntrItem::CRichNotepadMinusMinusCntrItem(REOBJECT* preo, CRichNotepadMinusMinusDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
}

CRichNotepadMinusMinusCntrItem::~CRichNotepadMinusMinusCntrItem()
{
	// TODO: add cleanup code here
}


// CRichNotepadMinusMinusCntrItem diagnostics

#ifdef _DEBUG
void CRichNotepadMinusMinusCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CRichNotepadMinusMinusCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

