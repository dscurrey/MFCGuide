
// NotepadMinus.h : main header file for the NotepadMinus application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CNotepadMinusApp:
// See NotepadMinus.cpp for the implementation of this class
//

class CNotepadMinusApp : public CWinAppEx
{
public:
	CNotepadMinusApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNotepadMinusApp theApp;
