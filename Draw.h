#if !defined(AFX_DRAW_H__71F798E7_7F1D_44F2_86D0_7B172528A356__INCLUDED_)
#define AFX_DRAW_H__71F798E7_7F1D_44F2_86D0_7B172528A356__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Draw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDraw dialog

class CDraw : public CDialog
{
// Construction
public:
	CDraw(CWnd* pParent = NULL);   // standard constructor
private:
	double max_height;
	int* stu_num;
	double* stu_score;
	double* stu_score_draw;
// Dialog Data
	//{{AFX_DATA(CDraw)
	enum { IDD = IDD_DRAW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDraw)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDraw)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAW_H__71F798E7_7F1D_44F2_86D0_7B172528A356__INCLUDED_)
