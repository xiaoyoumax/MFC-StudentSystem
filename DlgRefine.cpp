// DlgRefine.cpp : implementation file
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "DlgRefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRefine dialog


CDlgRefine::CDlgRefine(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRefine::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRefine)
	m_num = _T("");
	m_name = _T("");
	m_math = _T("");
	m_phy = _T("");
	m_Eng = _T("");
	//}}AFX_DATA_INIT
}


void CDlgRefine::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRefine)
	DDX_Text(pDX, IDC_EDIT1, m_num);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_math);
	DDX_Text(pDX, IDC_EDIT4, m_phy);
	DDX_Text(pDX, IDC_EDIT5, m_Eng);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRefine, CDialog)
	//{{AFX_MSG_MAP(CDlgRefine)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRefine message handlers
