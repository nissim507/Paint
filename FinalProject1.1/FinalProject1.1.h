
// FinalProject1.1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFinalProject11App:
// See FinalProject1.1.cpp for the implementation of this class
//

class CFinalProject11App : public CWinApp
{
public:
	CFinalProject11App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFinalProject11App theApp;
