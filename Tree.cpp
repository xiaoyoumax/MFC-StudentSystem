// Tree.cpp : implementation file
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "Tree.h"
#include "StudentSystemDlg.h" 
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTree dialog


CTree::CTree(CWnd* pParent /*=NULL*/)
	: CDialog(CTree::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTree)
	m_x1 = _T("");
	m_x2 = _T("");
	m_x3 = _T("");
	m_x4 = _T("");
	m_x5 = _T("");
	//}}AFX_DATA_INIT
}


void CTree::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTree)
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	DDX_Text(pDX, IDC_EDIT1, m_x1);
	DDX_Text(pDX, IDC_EDIT2, m_x2);
	DDX_Text(pDX, IDC_EDIT3, m_x3);
	DDX_Text(pDX, IDC_EDIT4, m_x4);
	DDX_Text(pDX, IDC_EDIT5, m_x5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTree, CDialog)
	//{{AFX_MSG_MAP(CTree)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, OnDblclkTree1)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTree message handlers

BOOL CTree::OnInitDialog()
{	
	CDialog::OnInitDialog();
	HICON icon[3];
	int i;
	icon[0]=AfxGetApp()->LoadIcon(IDI_ICON1);
	icon[1]=AfxGetApp()->LoadIcon(IDI_ICON2);
	icon[2]=AfxGetApp()->LoadIcon(IDI_ICON3);

	m_imageList.Create(32,32,0,8,8);
	for(i=0;i<3;i++)
	{
		m_imageList.Add(icon[i]);
	}
	m_Tree.SetImageList(&m_imageList,TVSIL_NORMAL);
	TV_INSERTSTRUCT tvInsert;
	iParam=0;
	HTREEITEM hItem1;
	tvInsert.hParent=TVI_ROOT;
	tvInsert.hInsertAfter=TVI_LAST;
	tvInsert.item.mask=TVIF_TEXT|TVIF_SELECTEDIMAGE|TVIF_IMAGE|TVIF_HANDLE;
	tvInsert.item.iImage=0;
	tvInsert.item.iSelectedImage=0;
	tvInsert.item.pszText="图表";
	tvInsert.item.lParam=iParam++;
	hItem1=m_Tree.InsertItem(&tvInsert);
	
	k1=m_Tree.InsertItem(_T("直方图"),1,1,hItem1,TVI_LAST);
	m_Tree.SetItemData(k1,1);

	
	k2=m_Tree.InsertItem(_T("饼形图"),2,2,hItem1,TVI_LAST);
	m_Tree.SetItemData(k2,2);
	
	k3=m_Tree.InsertItem(_T("折线图"),2,2,hItem1,TVI_LAST);
	m_Tree.SetItemData(k3,3);

	k4=m_Tree.InsertItem(_T("数学"),2,2,hItem1,TVI_LAST);
	m_Tree.SetItemData(k4,4);
	k=0;
	return TRUE;
}

void CTree::OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	HTREEITEM hItem=m_Tree.GetSelectedItem();
	k=m_Tree.GetItemData(hItem);
	Invalidate();

	*pResult = 0;
}

void CTree::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CStudentSystemDlg dlg1;
	stu_score=new int[10];

	for(int j=0;j<5;j++)stu_score[j]=0;
	stu_score[5]=d1;
	stu_score[6]=d2;
	stu_score[7]=d3;
	stu_score[8]=d4;
	stu_score[9]=d5;

	if(k==1)
	{
	int i;
	
	
	max_height=stu_score[0];
	for(i=0;i<10;i++)
	{
		if(stu_score[i]>max_height)
			max_height=stu_score[i];
	}

/*	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(150,80,40,40);
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

	CString strSeg[]={"小于60","60-70","71-80","81-90","91-100"};

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
	delete [] stu_score;*/
	CPen pen(PS_SOLID,1,RGB(0,0,0));
	dc.SelectObject(&pen);

	
/*	dc.MoveTo(400,450);
	dc.LineTo(50,450);
	dc.LineTo(50,0);
	dc.MoveTo(50+300,450);
	dc.LineTo(50+300,445);*/

	dc.MoveTo(400,450);
	dc.LineTo(50,450);
	dc.LineTo(50,20);
	//dc.MoveTo(50+350,450);
	//dc.LineTo(50+350,445);
	dc.MoveTo(50,20);
	dc.LineTo(60,30);
	dc.MoveTo(50,20);
	dc.LineTo(40,30);
	dc.MoveTo(400,450);
	dc.LineTo(390,460);
	dc.MoveTo(400,450);
	dc.LineTo(390,440);

	CString str;
	for(i=0;i<29;i++)
	{
		str.Format("%d",i);
		dc.MoveTo(50,450-15*i);
		dc.LineTo(55,450-15*i);
		dc.TextOut(30,443-15*i,str);
	}
	for(i=0;i<10;i++)
	{
		str.Format("%d",i*10);
		dc.MoveTo(50+30*i,450);
		dc.LineTo(50+30*i,445);
		dc.TextOut(45+30*i,455,str);
		str.Empty();
		if(stu_score[i]>0)
		{
			str.Format(_T("%d"),(int)stu_score[i]);
			dc.TextOut(55+30*i,450-stu_score[i]*15-15,str);
		}
		dc.Rectangle(50+30*i,450-stu_score[i]*15,50+(i+1)*30,450);
		str.Empty();
	}
	//	dc.TextOut(50+30*i,450-stu_score[i]*15-10,str);
	
	dc.TextOut(345,455,"100");
	}
	else if(k==2)
	{
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
	CString str1="";
	CString str2="";
	for(i=0;i<5;i++)
	{
		if(i==0)
		{
			str2.Format(_T("%d"),stu_score[5]);
			dc.TextOut(130,-70,str2);
			str2.Empty();
			CRect r1(150,-70,170,-50);
			dc.FillRect(r1,&br1);
		//	str1.Format("%lf",1+percentage[0]);
			dc.TextOut(175,-70,"<60");
		//	dc.TextOut(210,-70,str1);
			str1.Empty();
		}
		if(i==1)
		{
			str2.Format(_T("%d"),stu_score[6]);
			dc.TextOut(130,-40,str2);
			str2.Empty();
			CRect r1(150,-40,170,-20);
			dc.FillRect(r1,&br2);
		//	str1.Format(_T("%lf"),1+percentage[1]);
			dc.TextOut(175,-40,"60-70");
		//	dc.TextOut(210,-40,str1);
			str1.Empty();
		}
		
		if(i==2)
		{
		
			str2.Format(_T("%d"),stu_score[7]);
			dc.TextOut(130,-10,str2);
			str2.Empty();
			CRect r1(150,-10,170,10);
			dc.FillRect(r1,&br3);
			dc.TextOut(175,-10,"71-80");
		}
		if(i==3)
		{
			str2.Format(_T("%d"),stu_score[8]);
			dc.TextOut(130,20,str2);
			str2.Empty();
			CRect r1(150,20,170,40);
			dc.FillRect(r1,&br4);
			dc.TextOut(175,20,"81-90");
		}
		if(i==4)
		{
			str2.Format(_T("%d"),stu_score[9]);
			dc.TextOut(130,50,str2);
			str2.Empty();
			CRect r1(150,50,170,70);
			dc.FillRect(r1,&br5);
			dc.TextOut(175,50,">90");
		}
		
		
	}
	}else if(k==3)
	{
	int i;
	CStudentSystemDlg dlg1;
	stu_score=new int[10];

	for(int j=0;j<5;j++)stu_score[j]=0;
	stu_score[5]=d1;
	stu_score[6]=d2;
	stu_score[7]=d3;
	stu_score[8]=d4;
	stu_score[9]=d5;

	CPen pen(PS_SOLID,1,RGB(0,0,0));
	CPen pen1(PS_DASH,1,RGB(0,0,0));
	dc.SelectObject(&pen);

	
	dc.MoveTo(400,450);
	dc.LineTo(50,450);
	dc.LineTo(50,100);
	dc.MoveTo(50+350-35,450);
	dc.LineTo(50+350-35,445);
	dc.MoveTo(50,100);
	dc.LineTo(60,110);
	dc.MoveTo(50,100);
	dc.LineTo(40,110);

	CString str;
	for(i=0;i<7;i++)
	{
		if(i==0)
		dc.SelectObject(&pen);
		else dc.SelectObject(&pen1);
		str.Format("%d",i*5);
		dc.MoveTo(50,450-40*i);
		dc.LineTo(385,450-40*i);
		dc.TextOut(30,443-40*i,str);
	}
	CPoint pt_m1,pt_m2;
	POINT pt[6];
	CPoint pt_m0;
	pt[0].x=67;
	pt[0].y=450;
	for(i=0;i<9;i++)
	{
		
		str.Format("%d",i*5+60);
		dc.MoveTo(50+35*i,450);
		dc.LineTo(50+35*i,445);
		dc.TextOut(35+45+35*i,455,str);
		//str.Empty();
		
		if(i<5){
		pt[i+1].x=50+70*i;
		pt[i+1].y=450-(int)(stu_score[i+5]*(40/5.));
		}
		
	}
	
	//dc.TextOut(445,455,"100");
	//dc.SelectObject(&pen);
	dc.SelectObject(&pen);
	dc.MoveTo(400,450);
	dc.LineTo(390,460);
	dc.MoveTo(400,450);
	dc.LineTo(390,440);
	dc.Polyline(pt,6);
	}else if(k==4)
	{
		CString str;
		UpdateData(TRUE);
		str.Format(_T("%d"),stu_score[5]);
		m_x1=str;
		str.Empty();
		str.Format(_T("%d"),stu_score[6]);
		m_x2=str;
		str.Empty();
		str.Format(_T("%d"),stu_score[7]);
		m_x3=str;
		str.Empty();
		str.Format(_T("%d"),stu_score[8]);
		m_x4=str;
		str.Empty();
		str.Format(_T("%d"),stu_score[9]);
		m_x5=str;
		str.Empty();
		UpdateData(FALSE);
	}
	delete [] stu_score;
	CDialog::OnPaint();
	// Do not call CDialog::OnPaint() for painting messages
}
