
// CntrItem.h : interface of the CRichNotepadMinusMinusCntrItem class
//

#pragma once

class CRichNotepadMinusMinusDoc;
class CRichNotepadMinusMinusView;

class CRichNotepadMinusMinusCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CRichNotepadMinusMinusCntrItem)

// Constructors
public:
	CRichNotepadMinusMinusCntrItem(REOBJECT* preo = NULL, CRichNotepadMinusMinusDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer

// Attributes
public:
	CRichNotepadMinusMinusDoc* GetDocument()
		{ return reinterpret_cast<CRichNotepadMinusMinusDoc*>(CRichEditCntrItem::GetDocument()); }
	CRichNotepadMinusMinusView* GetActiveView()
		{ return reinterpret_cast<CRichNotepadMinusMinusView*>(CRichEditCntrItem::GetActiveView()); }

// Implementation
public:
	~CRichNotepadMinusMinusCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

