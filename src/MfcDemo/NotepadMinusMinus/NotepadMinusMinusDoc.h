
// NotepadMinusMinusDoc.h : interface of the CNotepadMinusMinusDoc class
//


#pragma once

#include <vector>
#include <string>


class CNotepadMinusMinusDoc : public CDocument
{
protected: // create from serialization only
	CNotepadMinusMinusDoc();
	DECLARE_DYNCREATE(CNotepadMinusMinusDoc)

// Attributes
public:

private:
  std::vector<std::string> m_lines;
  int m_fontSize;

// Operations
public:
  std::vector<std::string> GetLines() { return m_lines; }
  int GetFontSize() {return m_fontSize; }

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
	virtual ~CNotepadMinusMinusDoc();
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

#ifdef SHARED_HANDLERS
private:
	CString m_strSearchContent;
	CString m_strThumbnailContent;
#endif // SHARED_HANDLERS
public:
  virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
  virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
  afx_msg void OnViewFont();
};
