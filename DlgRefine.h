#if !defined(AFX_DLGREFINE_H__6879C8D2_27F8_4C30_9958_7B249377FBDB__INCLUDED_)
#define AFX_DLGREFINE_H__6879C8D2_27F8_4C30_9958_7B249377FBDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRefine.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRefine dialog

class CDlgRefine : public CDialog
{
// Construction
public:
	CDlgRefine(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgRefine)
	enum { IDD = IDD_DIALOG1 };
	CString	m_num;
	CString	m_name;
	CString	m_math;
	CString	m_phy;
	CString	m_Eng;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRefine)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRefine)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGREFINE_H__6879C8D2_27F8_4C30_9958_7B249377FBDB__INCLUDED_)
