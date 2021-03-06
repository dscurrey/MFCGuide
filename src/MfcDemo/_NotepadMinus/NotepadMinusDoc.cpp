
// NotepadMinusDoc.cpp : implementation of the CNotepadMinusDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NotepadMinus.h"
#endif

#include "NotepadMinusDoc.h"

#include "UtilityFunctions.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CNotepadMinusDoc

IMPLEMENT_DYNCREATE(CNotepadMinusDoc, CDocument)

BEGIN_MESSAGE_MAP(CNotepadMinusDoc, CDocument)
END_MESSAGE_MAP()


// CNotepadMinusDoc construction/destruction

CNotepadMinusDoc::CNotepadMinusDoc()
{
	// TODO: add one-time construction code here

}

CNotepadMinusDoc::~CNotepadMinusDoc()
{
}

BOOL CNotepadMinusDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CNotepadMinusDoc serialization

void CNotepadMinusDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CNotepadMinusDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CNotepadMinusDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CNotepadMinusDoc::SetSearchContent(const CString& value)
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

// CNotepadMinusDoc diagnostics

#ifdef _DEBUG
void CNotepadMinusDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNotepadMinusDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

// CNotepadMinusDoc commands

BOOL CNotepadMinusDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
  if (!CDocument::OnOpenDocument(lpszPathName)) return FALSE;

  std::string filename{toStdString(CString(lpszPathName))};
  readLinesFromFile(m_lines, filename);

  // All views using CNotepadMinusDoc need to repaint
  UpdateAllViews(NULL);

  return TRUE;
}
