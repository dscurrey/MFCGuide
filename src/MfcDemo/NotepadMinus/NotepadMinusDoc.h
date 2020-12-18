
// NotepadMinusDoc.h : interface of the CNotepadMinusDoc class
//


#pragma once

#include <vector>
#include <string>


class CNotepadMinusDoc : public CDocument
{
protected: // create from serialization only
	CNotepadMinusDoc();
	DECLARE_DYNCREATE(CNotepadMinusDoc)

// Attributes
public:

private:
  std::vector<std::string> m_lines;

// Operations
public:
  BOOL OnOpenDocument(LPCTSTR lpszPathName);
  const std::vector<std::string>& GetLines() const { return m_lines; }


// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CNotepadMinusDoc();
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
};
