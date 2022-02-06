// StudentSystemDlg.h : header file
//

#if !defined(AFX_STUDENTSYSTEMDLG_H__B65D369B_2A7F_4715_B2DA_AB8F447BE394__INCLUDED_)
#define AFX_STUDENTSYSTEMDLG_H__B65D369B_2A7F_4715_B2DA_AB8F447BE394__INCLUDED_

#include<afxtempl.h>     
#include"Student.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStudentSystemDlg dialog

class CStudentSystemDlg : public CDialog
{
// Construction
public:
	CStudentSystemDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL PartitionStringByCompart(const CString &sOriginal,char cDivider,CStringArray &saField );
	int num_rect;
	int x1,x2,x3,x4,x5;

private:
	int n;
	int s,t,stt[100],sst[100];
	CString st,sstt;
// Dialog Data
	//{{AFX_DATA(CStudentSystemDlg)
	enum { IDD = IDD_STUDENTSYSTEM_DIALOG };
	CListCtrl	m_SList2;
	CListCtrl	m_SList;
	CString	m_name;
	CString	m_num;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentSystemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CArray<Student,Student&> m_stuArr;
	// Generated message map functions
	//{{AFX_MSG(CStudentSystemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnRefine();
	afx_msg void OnSort();
	afx_msg void OnCount();
	afx_msg void OnSearch();
	afx_msg void OnClear();
	afx_msg void OnWriterin();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTSYSTEMDLG_H__B65D369B_2A7F_4715_B2DA_AB8F447BE394__INCLUDED_)
