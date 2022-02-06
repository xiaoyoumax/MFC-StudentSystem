#if !defined(AFX_DLGADD_H__D08B3B30_9806_412A_B54A_374AA3A73C4A__INCLUDED_)
#define AFX_DLGADD_H__D08B3B30_9806_412A_B54A_374AA3A73C4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAdd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAdd dialog

class CDlgAdd : public CDialog
{
// Construction
public:
	CDlgAdd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAdd)
	enum { IDD = IDD_ADD };
	CString	m_num;
	CString	m_name;
	CString	m_math;
	CString	m_phy;
	CString	m_Eng;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAdd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAdd)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADD_H__D08B3B30_9806_412A_B54A_374AA3A73C4A__INCLUDED_)
