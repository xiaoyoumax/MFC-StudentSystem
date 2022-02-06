#if !defined(AFX_DRAWDLG_H__24F2E1B2_744D_4D5F_9628_948603107D94__INCLUDED_)
#define AFX_DRAWDLG_H__24F2E1B2_744D_4D5F_9628_948603107D94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrawDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrawDlg dialog

class CDrawDlg : public CDialog
{
// Construction
public:
	CDrawDlg(CWnd* pParent = NULL);   // standard constructor
	int d1,d2,d3,d4,d5;
// Dialog Data
	//{{AFX_DATA(CDrawDlg)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDrawDlg)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	double max_height;
//	int* stu_num;
	double* stu_score;
	//* stu_score_draw;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWDLG_H__24F2E1B2_744D_4D5F_9628_948603107D94__INCLUDED_)
