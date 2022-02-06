#if !defined(AFX_TREE_H__5921BFB8_5E85_4E40_B87E_E19743DCBA95__INCLUDED_)
#define AFX_TREE_H__5921BFB8_5E85_4E40_B87E_E19743DCBA95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTree dialog

class CTree : public CDialog
{
// Construction
public:
	CTree(CWnd* pParent = NULL);   // standard constructor
	int d1,d2,d3,d4,d5;
	float percentage[5];
private:
	CImageList m_imageList;
	HTREEITEM k1,k2,k3,k4;
	long iParam;
	int k;
	int* stu_score;
	double max_height;
// Dialog Data
	//{{AFX_DATA(CTree)
	enum { IDD = IDD_DIALOG4 };
	CTreeCtrl	m_Tree;
	CString	m_x1;
	CString	m_x2;
	CString	m_x3;
	CString	m_x4;
	CString	m_x5;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTree)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTree)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREE_H__5921BFB8_5E85_4E40_B87E_E19743DCBA95__INCLUDED_)
