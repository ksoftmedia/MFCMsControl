
// HotKey.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CHotKeyApp:
// See HotKey.cpp for the implementation of this class
//

class CHotKeyApp : public CWinApp
{
public:
	CHotKeyApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CHotKeyApp theApp;
