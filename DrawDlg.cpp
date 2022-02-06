// DrawDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "DrawDlg.h"
#include "StudentSystemDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawDlg dialog


CDrawDlg::CDrawDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDrawDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDrawDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDrawDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDrawDlg, CDialog)
	//{{AFX_MSG_MAP(CDrawDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawDlg message handlers

void CDrawDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	int i;
	CStudentSystemDlg dlg1;
	stu_score=new double[5];

	stu_score[0]=d1;
	stu_score[1]=d2;
	stu_score[2]=d3;
	stu_score[3]=d4;
	stu_score[4]=d5;

	max_height=stu_score[0];
	for(i=0;i<5;i++)
	{
		if(stu_score[i]>max_height)
			max_height=stu_score[i];
	}

	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(80,20);
	int nSegWidth=rc.Width()/5;

	int count=0;
	while(rc.Height()<(int)max_height)
	{
		max_height/=2;
		count++;
	}
	int nSegHeight=(int)(rc.Height()/max_height);

	for(i=0;i<5;i++)
	{
		for(int j=0;j<count;j++)
		{
			stu_score[i]=stu_score[i]/2;
		}
	}

	COLORREF crSeg=RGB(0,0,192);
	CBrush brush1(HS_FDIAGONAL,crSeg);
	CBrush brush2(HS_BDIAGONAL,crSeg);
	CPen pen(PS_INSIDEFRAME,2,crSeg);
	CBrush* oldBrush=dc.SelectObject(&brush1);
	CPen* oldPen=dc.SelectObject(&pen);
	CRect rcSeg(rc);
	rcSeg.right=rcSeg.left+nSegWidth;

	CString strSeg[]={"ะกำฺ60","60-70","71-80","81-90","91-100"};

	CRect rcStr;
	for(i=0;i<5;i++)
	{
		if(i%2)
			dc.SelectObject(&brush1);
		else
			dc.SelectObject(&brush2);
		rcSeg.top=rcSeg.bottom-(int)(stu_score[i]*nSegHeight)-2;
		dc.Rectangle(rcSeg);
		if(stu_score[i]>0)
		{
			CString str;
			str.Format(_T("%0.2lf"),stu_score[i]);
			dc.DrawText(str,rcSeg,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		}
		rcStr=rcSeg;
		rcStr.top=rcStr.bottom+2;
		rcStr.bottom+=20;
		dc.DrawText(strSeg[i],rcStr,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		rcSeg.OffsetRect(nSegWidth,0);
	}
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);
	delete [] stu_score;

	CDialog::OnPaint();

	// Do not call CDialog::OnPaint() for painting messages
}
