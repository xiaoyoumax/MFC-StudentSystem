#if !defined(AFX_ADDDLG_H__31366BF6_D3DE_494E_B53A_747DE726FC78__INCLUDED_)
#define AFX_ADDDLG_H__31366BF6_D3DE_494E_B53A_747DE726FC78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddDlg dialog

class CAddDlg : public CDialog
{
// Construction
public:
	CAddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddDlg)
	enum { IDD = IDD_ADD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__31366BF6_D3DE_494E_B53A_747DE726FC78__INCLUDED_)
