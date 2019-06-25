
// IPAddress.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIPAddressApp:
// See IPAddress.cpp for the implementation of this class
//

class CIPAddressApp : public CWinApp
{
public:
	CIPAddressApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CIPAddressApp theApp;
