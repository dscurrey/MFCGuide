
// RichNotepadMinusMinusDoc.cpp : implementation of the CRichNotepadMinusMinusDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RichNotepadMinusMinus.h"
#endif

#include "RichNotepadMinusMinusDoc.h"
#include "CntrItem.h"

#include <propkey.h>

#include "UtilityFunctions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CRichNotepadMinusMinusDoc

IMPLEMENT_DYNCREATE(CRichNotepadMinusMinusDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CRichNotepadMinusMinusDoc, CRichEditDoc)
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_POPUP, &CRichNotepadMinusMinusDoc::OnUpdateObjectVerbPopup)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()


// CRichNotepadMinusMinusDoc construction/destruction

CRichNotepadMinusMinusDoc::CRichNotepadMinusMinusDoc()
{
	// TODO: add one-time construction code here

}

CRichNotepadMinusMinusDoc::~CRichNotepadMinusMinusDoc()
{
}

BOOL CRichNotepadMinusMinusDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

CRichEditCntrItem* CRichNotepadMinusMinusDoc::CreateClientItem(REOBJECT* preo) const
{
	return new CRichNotepadMinusMinusCntrItem(preo, const_cast<CRichNotepadMinusMinusDoc*>(this));
}




// CRichNotepadMinusMinusDoc serialization

void CRichNotepadMinusMinusDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class CRichEditDoc enables serialization
	//  of the container document's COleClientItem objects.
	// TODO: set CRichEditDoc::m_bRTF = FALSE if you are serializing as text
	CRichEditDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CRichNotepadMinusMinusDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CRichNotepadMinusMinusDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CRichNotepadMinusMinusDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CRichNotepadMinusMinusDoc diagnostics

#ifdef _DEBUG
void CRichNotepadMinusMinusDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CRichNotepadMinusMinusDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// CRichNotepadMinusMinusDoc commands


BOOL CRichNotepadMinusMinusDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
  if (!CRichEditDoc::OnOpenDocument(lpszPathName))
    return FALSE;

  std::string filename{ToStdString(CString(lpszPathName))};
  ReadLinesFromFile(m_lines, filename);

  UpdateAllViews(NULL);

  return TRUE;
}
