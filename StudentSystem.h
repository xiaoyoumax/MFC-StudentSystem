// StudentSystem.h : main header file for the STUDENTSYSTEM application
//

#if !defined(AFX_STUDENTSYSTEM_H__41EA9408_7133_4C21_9CB7_B682B8C9BD08__INCLUDED_)
#define AFX_STUDENTSYSTEM_H__41EA9408_7133_4C21_9CB7_B682B8C9BD08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStudentSystemApp:
// See StudentSystem.cpp for the implementation of this class
//

class CStudentSystemApp : public CWinApp
{
public:
	CStudentSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStudentSystemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTSYSTEM_H__41EA9408_7133_4C21_9CB7_B682B8C9BD08__INCLUDED_)
