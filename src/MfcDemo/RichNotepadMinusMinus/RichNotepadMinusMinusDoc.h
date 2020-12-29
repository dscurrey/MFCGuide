
// RichNotepadMinusMinusDoc.h : interface of the CRichNotepadMinusMinusDoc class
//


#pragma once

#include <vector>


class CRichNotepadMinusMinusDoc : public CRichEditDoc
{
protected: // create from serialization only
	CRichNotepadMinusMinusDoc();
	DECLARE_DYNCREATE(CRichNotepadMinusMinusDoc)

// Attributes
public:

private:
  std::vector<std::string> m_lines;

// Operations
public:
  std::vector<std::string> GetLines() { return m_lines; }

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CRichNotepadMinusMinusDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
  virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};
