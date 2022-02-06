// Bing.cpp : implementation file
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "Bing.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBing dialog


CBing::CBing(CWnd* pParent /*=NULL*/)
	: CDialog(CBing::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBing)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBing)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBing, CDialog)
	//{{AFX_MSG_MAP(CBing)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBing message handlers

void CBing::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBrush br1=RGB(0,0,0);
	CBrush br2=RGB(255,0,0);
	CBrush br3=RGB(0,0,255);
	CBrush br4=RGB(255,255,0);
	CBrush br5=RGB(255,0,255);
	
	int r=100;
	SetViewportOrgEx(dc,200,200,NULL);
	CRect pieRect(-r,-r,r,r);
	dc.Ellipse(&pieRect);

	int i=0;
	POINT pt_start,pt_end,pt_Orignal;
	int single=0;
	const double PI=3.1415926;
	pt_start.x=r;
	pt_start.y=0;
	for(i=0;i<5;i++)
	{
		single+=percentage[i]*360;
		pt_end.x=(int)r*cos(single*PI/180);
		pt_end.y=(int)(-r)*sin(single*PI/180);
		if(i==0)
		{
			dc.SelectObject(&br1);
			dc.Pie(&pieRect,pt_start,pt_end);
			pt_Orignal=pt_start;
			pt_start=pt_end;
			
		}
		if(i==1)
		{
			dc.SelectObject(&br2);
			dc.Pie(&pieRect,pt_start,pt_end);
		//	dc.TextOut(pt_start.x+1,pt_end.y,"60-70");
			pt_start=pt_end;
			//dc.Rectangle();
		}
		if(i==2)
		{
			dc.SelectObject(&br3);
			dc.Pie(&pieRect,pt_start,pt_end);
			pt_start=pt_end;
		}
		if(i==3)
		{
			dc.SelectObject(&br4);
			dc.Pie(&pieRect,pt_start,pt_end);
			pt_start=pt_end;
		}
		if(i==4)
		{
			dc.SelectObject(&br5);
			dc.Pie(&pieRect,pt_start,pt_Orignal);
			pt_start=pt_end;
		}
		
	}
	for(i=0;i<5;i++)
	{
		if(i==0)
		{
			CRect r1(390,100,410,80);
			dc.FillRect(r1,&br1);
			dc.TextOut(440,90,"60-70");
		}
	}
	

	
	
	// Do not call CDialog::OnPaint() for painting messages
}
