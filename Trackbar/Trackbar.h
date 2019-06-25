
// Trackbar.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTrackbarApp:
// See Trackbar.cpp for the implementation of this class
//

class CTrackbarApp : public CWinApp
{
public:
	CTrackbarApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTrackbarApp theApp;
