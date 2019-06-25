
// Static.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CStaticApp:
// See Static.cpp for the implementation of this class
//

class CStaticApp : public CWinApp
{
public:
	CStaticApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CStaticApp theApp;
