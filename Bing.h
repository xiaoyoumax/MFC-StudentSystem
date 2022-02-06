#if !defined(AFX_BING_H__46EC044B_78F9_4A5D_936A_F0A3A7E9A96F__INCLUDED_)
#define AFX_BING_H__46EC044B_78F9_4A5D_936A_F0A3A7E9A96F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Bing.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBing dialog

class CBing : public CDialog
{
// Construction
public:
	CBing(CWnd* pParent = NULL);   // standard constructor
	float percentage[5];
// Dialog Data
	//{{AFX_DATA(CBing)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBing)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBing)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BING_H__46EC044B_78F9_4A5D_936A_F0A3A7E9A96F__INCLUDED_)
