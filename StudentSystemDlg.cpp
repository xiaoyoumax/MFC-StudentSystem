// StudentSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "StudentSystemDlg.h"
#include "DlgAdd.h"
#include "DlgRefine.h"
#include "DrawDlg.h"
#include "Bing.h"
#include "Tree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentSystemDlg dialog

CStudentSystemDlg::CStudentSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentSystemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentSystemDlg)
	m_name = _T("");
	m_num = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentSystemDlg)
	DDX_Control(pDX, IDC_LIST2, m_SList2);
	DDX_Control(pDX, IDC_LIST1, m_SList);
	DDX_Text(pDX, IDC_name, m_name);
	DDX_Text(pDX, IDC_num, m_num);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStudentSystemDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentSystemDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_REFINE, OnRefine)
	ON_BN_CLICKED(IDC_SORT, OnSort)
	ON_BN_CLICKED(IDC_COUNT, OnCount)
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_BN_CLICKED(IDC_WRITERIN, OnWriterin)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentSystemDlg message handlers

BOOL CStudentSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	DWORD dwStyle=m_SList.GetExtendedStyle();
	dwStyle |=LVS_EX_FULLROWSELECT;
	dwStyle |=LVS_EX_GRIDLINES;

	m_SList.SetExtendedStyle(dwStyle);
	m_SList.InsertColumn(0,"学号",LVCFMT_LEFT,100);
	m_SList.InsertColumn(1,"姓名",LVCFMT_LEFT,66);
	m_SList.InsertColumn(2,"数学",LVCFMT_LEFT,76);
	m_SList.InsertColumn(3,"物理",LVCFMT_LEFT,76);
	m_SList.InsertColumn(4,"英语",LVCFMT_LEFT,76);
	m_SList.InsertColumn(5,"总分",LVCFMT_LEFT,90);

	DWORD dwStyle2=m_SList2.GetExtendedStyle();
	dwStyle2 |=LVS_EX_FULLROWSELECT;
	dwStyle2 |=LVS_EX_GRIDLINES;

	m_SList2.SetExtendedStyle(dwStyle);
	m_SList2.InsertColumn(0,"学号",LVCFMT_LEFT,100);
	m_SList2.InsertColumn(1,"姓名",LVCFMT_LEFT,66);
	m_SList2.InsertColumn(2,"数学",LVCFMT_LEFT,76);
	m_SList2.InsertColumn(3,"物理",LVCFMT_LEFT,76);
	m_SList2.InsertColumn(4,"英语",LVCFMT_LEFT,76);
	m_SList2.InsertColumn(5,"总分",LVCFMT_LEFT,90);
	n=0;
	t=0;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStudentSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStudentSystemDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStudentSystemDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStudentSystemDlg::OnOpen() 
{
	// TODO: Add your control notification handler code here
	t=0;
	m_SList2.DeleteAllItems();
	CString FilePathName;
	CFileDialog dlg(TRUE);
	if(dlg.DoModal()==IDOK)
		FilePathName=dlg.GetPathName();
	else 
		return;
	CStdioFile file;
	file.Open(FilePathName,CFile::modeRead);
	CString strLine;
		m_stuArr.RemoveAll();
	while(file.ReadString(strLine))
	{
		CStringArray strarray;
		PartitionStringByCompart(strLine,' ',strarray);
		CString id=strarray.GetAt(0);
		CString name=strarray.GetAt(1);
		double math=atof(strarray.GetAt(2));
		double physical=atof(strarray.GetAt(3));
		double English=atof(strarray.GetAt(4));
		Student temp(id,name,math,physical,English);
		m_stuArr.Add(temp);
	}
	file.Close();

	CString str;
	int i;
	n=m_stuArr.GetSize();
	m_SList.DeleteAllItems();
	for(i=0;i<m_stuArr.GetSize();i++)
	{
		Student stu=m_stuArr.GetAt(i);
		
		m_SList.SetItemText(i,1,stu.CName);

		str.Format("%lf",stu.CMath);
		m_SList.SetItemText(i,2,str);
		str.Empty();m_SList.InsertItem(i,"");
		m_SList.SetItemText(i,0,stu.CId);

		str.Format("%lf",stu.CPhysical);
		m_SList.SetItemText(i,3,str);
		str.Empty();

		str.Format("%lf",stu.CEnglish);
		m_SList.SetItemText(i,4,str);
		str.Empty();

		str.Format("%lf",stu.CMath+stu.CPhysical+stu.CEnglish);
		m_SList.SetItemText(i,5,str);
		str.Empty();
	}
}

//分离字符串（注意函数名称的对话框名称）
BOOL CStudentSystemDlg::PartitionStringByCompart(const CString &sOriginal,char cDivider,CStringArray &saField )
{
	saField.RemoveAll();
	int len=sOriginal.GetLength();
	CString sTmp("");
	for(int i=0;i<len;i++)
	{
		if(sOriginal[i]!=cDivider)
			sTmp+=sOriginal[i];
		else
		{
			saField.Add(sTmp);
			sTmp=_T("");
		}
	}
	saField.Add(sTmp);
	if(saField.GetSize()==1)
		return false;
	return true;

}

void CStudentSystemDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here

		CDlgAdd dlg;
		dlg.m_num="0";
		dlg.m_name="0";
		dlg.m_math="0";
		dlg.m_phy="0";
		dlg.m_Eng="0";
		if(dlg.DoModal()==IDOK)
		{
			double a,b,c;
			CString str;
			a=atof(dlg.m_math);
			b=atof(dlg.m_phy);
			c=atof(dlg.m_Eng);
			m_SList.InsertItem(n,"");
			m_SList.SetItemText(n,0,dlg.m_num);
			m_SList.SetItemText(n,1,dlg.m_name);

			str.Format(_T("%lf"),a);
			m_SList.SetItemText(n,2,str);
			str.Empty();

			str.Format(_T("%lf"),b);
			m_SList.SetItemText(n,3,str);
			str.Empty();

			str.Format(_T("%lf"),c);
			m_SList.SetItemText(n,4,str);
			str.Empty();

			str.Format(_T("%lf"),a+b+c);
			m_SList.SetItemText(n,5,str);
			str.Empty();
			n++;
		}
	
	
}

void CStudentSystemDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int s=m_SList.GetNextItem(-1,LVIS_SELECTED);
	if(s<0)
	{
		MessageBox("请选择一行!");
	}else
	{
		int i=m_SList.GetSelectionMark();
		m_SList.DeleteItem(i);
		n--;
	}
}

void CStudentSystemDlg::OnRefine() 
{
	// TODO: Add your control notification handler code here
	int s=m_SList.GetNextItem(-1,LVIS_SELECTED);
	if(s<0)
	{
		MessageBox("请选择一行!");
	}else
	{
		int i=m_SList.GetSelectionMark();
		CDlgRefine dlg;
		dlg.m_num=m_SList.GetItemText(i,0);
		dlg.m_name=m_SList.GetItemText(i,1);
		dlg.m_math=m_SList.GetItemText(i,2);
		dlg.m_phy=m_SList.GetItemText(i,3);
		dlg.m_Eng=m_SList.GetItemText(i,4);
		if(dlg.DoModal()==IDOK)
		{	
			m_SList.SetItemText(i,0,dlg.m_num);
			m_SList.SetItemText(i,1,dlg.m_name);
			m_SList.SetItemText(i,2,dlg.m_math);
			m_SList.SetItemText(i,3,dlg.m_phy);
			m_SList.SetItemText(i,4,dlg.m_Eng);
			double a,b,c;
			a=atof(dlg.m_math);
			b=atof(dlg.m_phy);
			c=atof(dlg.m_Eng);
			CString str;
			str.Format(_T("%f"),a+b+c);
			m_SList.SetItemText(i,5,str);
		}
	}
}

void CStudentSystemDlg::OnSort() 
{
	// TODO: Add your control notification handler code here
		if(n==0)
	{
		MessageBox("请先读取数据!");
	}else
	{
	int i,j;
	int k1,k2;
	double a1,a2,a3,c1;
	double b1,b2,b3,c2;
	CString str0,str1,str2,str3,str4,str5,str6;
	for(j=0;j<=n-2;j++)
	{
	for(i=n-1;i>j;i--)
	{
		k1=_ttoi(m_SList.GetItemText(i,0));
		a1=atof(m_SList.GetItemText(i,2));
		a2=atof(m_SList.GetItemText(i,3));
		a3=atof(m_SList.GetItemText(i,4));
		c1=atof(m_SList.GetItemText(i,5));

		k2=_ttoi(m_SList.GetItemText(i-1,0));
		b1=atof(m_SList.GetItemText(i-1,2));
		b2=atof(m_SList.GetItemText(i-1,3));
		b3=atof(m_SList.GetItemText(i-1,4));
		c2=atof(m_SList.GetItemText(i-1,5));
		if(c1>c2 || c1==c2 && a1>b1 || c1==c2 && a1==b1 && a2>b2 || c1==c2 && a1==b1 && a2==b2 && a3>b3 || c1==c2 && a1==b1 && a2==b2 && a3==b3 && k1>k2)
		{
			str0=m_SList.GetItemText(i-1,0);
			str1=m_SList.GetItemText(i-1,1);
			str2=m_SList.GetItemText(i-1,2);
			str3=m_SList.GetItemText(i-1,3);
			str4=m_SList.GetItemText(i-1,4);
			str5=m_SList.GetItemText(i-1,5);

			m_SList.SetItemText(i-1,0,m_SList.GetItemText(i,0));
			m_SList.SetItemText(i-1,1,m_SList.GetItemText(i,1));
			m_SList.SetItemText(i-1,2,m_SList.GetItemText(i,2));
			m_SList.SetItemText(i-1,3,m_SList.GetItemText(i,3));
			m_SList.SetItemText(i-1,4,m_SList.GetItemText(i,4));
			m_SList.SetItemText(i-1,5,m_SList.GetItemText(i,5));

			m_SList.SetItemText(i,0,str0);
			m_SList.SetItemText(i,1,str1);
			m_SList.SetItemText(i,2,str2);
			m_SList.SetItemText(i,3,str3);
			m_SList.SetItemText(i,4,str4);
			m_SList.SetItemText(i,5,str5);

		}
	}
	}
	}
}

void CStudentSystemDlg::OnCount() 
{
	// TODO: Add your control notification handler code here
	int i=n;
	double a1,b1,c1,d1;
	double a2,b2,c2,d2;
	a2=b2=c2=d2=0;
	for(int j=0;j<=i-1;j++)
	{
		a1=atof(m_SList.GetItemText(j,2));
		b1=atof(m_SList.GetItemText(j,3));
		c1=atof(m_SList.GetItemText(j,4));
		d1=atof(m_SList.GetItemText(j,5));

		a2+=a1;
		b2+=b1;
		c2+=c1;
		d2+=d1;
	}
	double a3=a2/i,b3=b2/i,c3=c2/i,d3=d2/i;
	CString str0,str1,str2,str3,str4,str5;
	str0=" 数学   /   物理   /   英语 /   总分 ";
	str1.Format(_T("%lf"),a3);
	str2.Format(_T("%lf"),b3);
	str3.Format(_T("%lf"),c3);
	str4.Format(_T("%lf"),d3);
	str5=str0+'\n'+str1+" / "+str2+" / "+str3+" / "+str4;
	MessageBox(str5,"平均分");
}

void CStudentSystemDlg::OnSearch() 
{
	// TODO: Add your control notification handler code here
	int m=0,t=0;
	CString str,sttrr="",stttrrr("");
	UpdateData(TRUE);
	st=m_name;
	sstt=m_num;
	for(int i=0;i<=n-1;i++)
	{
		if(st==m_SList.GetItemText(i,1) || sstt==m_SList.GetItemText(i,0))
		{
			stttrrr+=m_SList.GetItemText(i,0)+"/"+m_SList.GetItemText(i,1)+"/"+m_SList.GetItemText(i,2)+"/"+m_SList.GetItemText(i,3)+"/"+m_SList.GetItemText(i,4)+"/"+m_SList.GetItemText(i,5)+'\n';
			m++;
		}
	}
	if(m!=0)
		MessageBox(stttrrr,"查找成功");
	else
	{
		for(int j=0;j<=n-1;j++)
		{
			if(st!="" && st.GetLength()<=m_SList.GetItemText(j,1).GetLength() && m_SList.GetItemText(j,1).Find(st)!=-1)
			//str=m_SList.GetItemText(j,1).Mid(0,2);
			//if(str==st)
			{
				sttrr+=(m_SList.GetItemText(j,0)+"/"+m_SList.GetItemText(j,1)+"/"+m_SList.GetItemText(j,2)+"/"+m_SList.GetItemText(j,3)+"/"+m_SList.GetItemText(j,4)+"/"+m_SList.GetItemText(j,5)+'\n');
				t++;
			}
		}
		if(t==0)
			MessageBox("查无此人!","查找失败");
		else
			MessageBox(sttrr,"查找成功");
	}	
}

void CStudentSystemDlg::OnClear() 
{
	// TODO: Add your control notification handler code here
	m_SList.DeleteAllItems();
	n=0;
}

void CStudentSystemDlg::OnWriterin() 
{
	// TODO: Add your control notification handler code here
	if(n==0)
	{
		MessageBox("请先添加数据!");
	}else {
	CString FilePathName;
	CFileDialog dlg(FALSE);
	if(dlg.DoModal()==IDOK)
		FilePathName=dlg.GetPathName();
	CFile file;
	file.Open(FilePathName,CFile::modeCreate | CFile::modeReadWrite,NULL);
	CString str(""),sttrr(""),str0,str1,str2,str3,str4,str5,st;
	int a,b,c;
	for(int i=0;i<=n-1;i++)
	{
		str0=m_SList.GetItemText(i,0);
		str1=m_SList.GetItemText(i,1);
		a=_ttoi(m_SList.GetItemText(i,2));
		str2.Format(_T("%d"),a);
		b=_ttoi(m_SList.GetItemText(i,3));
		str3.Format(_T("%d"),b);
		c=_ttoi(m_SList.GetItemText(i,4));
		str4.Format(_T("%d"),c);
		sttrr=str0+" "+str1+" "+str2+" "+str3+" "+str4;
		
		file.Write(sttrr,strlen(sttrr));
		file.Write(_T("\r\n"),strlen("\r\n"));
	}
	
	file.Close();
	}
}

void CStudentSystemDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	int m=m_SList.GetNextItem(-1,LVIS_SELECTED);
	m_SList2.DeleteAllItems();
/*	s=i;
	CString str0,str1,str2,str3,str4,str5;
	str0=m_SList.GetItemText(i,0);
	str1=m_SList.GetItemText(i,1);
	str2=m_SList.GetItemText(i,2);
	str3=m_SList.GetItemText(i,3);
	str4=m_SList.GetItemText(i,4);
	str5=m_SList.GetItemText(i,5);
	m_SList2.InsertItem(t,"");
	m_SList2.SetItemText(t,0,str0);
	m_SList2.SetItemText(t,1,str1);
	m_SList2.SetItemText(t,2,str2);
	m_SList2.SetItemText(t,3,str3);
	m_SList2.SetItemText(t,4,str4);
	m_SList2.SetItemText(t,5,str5);
	t++;
*/
	CString str;
	CString str0,str1,str2,str3,str4,str5;
	for(int i=0;i<n;i++)
	{
		double math=atof(m_SList.GetItemText(i,2));
		if(math<=70 && math>=60)
		{
			m_SList2.InsertItem(t,"");
			str0=m_SList.GetItemText(i,0);
			m_SList2.SetItemText(t,0,str0);

			
			str1=m_SList.GetItemText(i,1);
			m_SList2.SetItemText(t,1,str1);

			str2=m_SList.GetItemText(i,2);
			str3=m_SList.GetItemText(i,3);
			str4=m_SList.GetItemText(i,4);
			str5=m_SList.GetItemText(i,5);

			
			
			sst[t]=i;
			m_SList2.SetItemText(t,2,str2);
			m_SList2.SetItemText(t,3,str3);
			m_SList2.SetItemText(t,4,str4);
			m_SList2.SetItemText(t,5,str5);
			t++;
			
			n--;
		}
	}
	for(int b=0;b<t;b++)
	{
		m_SList.DeleteItem(sst[b]);
	}

}

void CStudentSystemDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	
	CString str0,str1,str2,str3,str4,str5;
	for(int i=0;i<t;i++)
	{
		str0=m_SList2.GetItemText(i,0);
			str1=m_SList2.GetItemText(i,1);
			str2=m_SList2.GetItemText(i,2);
			str3=m_SList2.GetItemText(i,3);
			str4=m_SList2.GetItemText(i,4);
			str5=m_SList2.GetItemText(i,5);
		m_SList.InsertItem(0,"");
		m_SList.SetItemText(0,0,str0);
		m_SList.SetItemText(0,1,str1);
		m_SList.SetItemText(0,2,str2);
		m_SList.SetItemText(0,3,str3);
		m_SList.SetItemText(0,4,str4);
		m_SList.SetItemText(0,5,str5);
		n++;
	}
	t=0;
	m_SList2.DeleteAllItems();
}

void CStudentSystemDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	t=0;
	m_SList2.DeleteAllItems();
	CString str;
	CString str0,str1,str2,str3,str4,str5;
	for(int i=0;i<=n-1;i++)
	{
		int math=_ttoi(m_SList.GetItemText(i,2));
		if(math<100 && math>=90)
		{
			
			n--;
			str.Format(_T("%lf"),math);
			str0=m_SList.GetItemText(i,0);
			str1=m_SList.GetItemText(i,1);
			str2=m_SList.GetItemText(i,2);
			str3=m_SList.GetItemText(i,3);
			str4=m_SList.GetItemText(i,4);
			str5=m_SList.GetItemText(i,5);

			m_SList2.InsertItem(0,"");
			m_SList2.SetItemText(0,0,str0);
			m_SList2.SetItemText(0,1,str1);
			m_SList2.SetItemText(0,2,str2);
			m_SList2.SetItemText(0,3,str3);
			m_SList2.SetItemText(0,4,str4);
			m_SList2.SetItemText(0,5,str5);
			t++;
			m_SList.DeleteItem(i);
			i--;
		}
	}

}

void CStudentSystemDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CString str0,str1,str2,str3,str4,str5;
	for(int i=0;i<t;i++)
	{
		
		str0=m_SList2.GetItemText(i,0);
		str1=m_SList2.GetItemText(i,1);
		str2=m_SList2.GetItemText(i,2);
		str3=m_SList2.GetItemText(i,3);
		str4=m_SList2.GetItemText(i,4);
		str5=m_SList2.GetItemText(i,5);

		m_SList.InsertItem(0,"");
		m_SList.SetItemText(0,0,m_SList2.GetItemText(i,0));
		m_SList.SetItemText(0,1,m_SList2.GetItemText(i,1));
		m_SList.SetItemText(0,2,m_SList2.GetItemText(i,2));
		m_SList.SetItemText(0,3,m_SList2.GetItemText(i,3));
		m_SList.SetItemText(0,4,m_SList2.GetItemText(i,4));
		m_SList.SetItemText(0,5,m_SList2.GetItemText(i,5));
		n++;
	}
	t=0;
	m_SList2.DeleteAllItems();
}

void CStudentSystemDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	if(n==0)
	{
		MessageBox("请先添加数据!");
	}else 
	{
		CDrawDlg dlg;
		num_rect=5;
		int i;
		x1=x2=x3=x4=x5=0;
		double q;
		for(i=0;i<=n-1;i++)
		{
			q=atof(m_SList.GetItemText(i,2));	
			if(q<60)
				x1=x1+1;
			if(q>=60 && q<=70)
				x2=x2+1;
			if(q>70 && q<=80)
				x3=x3+1;
			if(q>80 && q<=90)
				x4=x4+1;
			if(q>90)
				x5=x5+1;
		}
		dlg.d1=x1;
		dlg.d2=x2;
		dlg.d3=x3;
		dlg.d4=x4;
		dlg.d5=x5;
		if(dlg.DoModal()==IDOK)
		{
		}
	}
	
}

void CStudentSystemDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	if(n==0)
	{
		MessageBox("请先添加数据!");
	}else 
	{
		CBing dlg;
		int i;
		x1=x2=x3=x4=x5=0;
		double q;
		for(i=0;i<=n-1;i++)
		{
			q=atof(m_SList.GetItemText(i,2));	
			if(q<60)
				x1=x1+1;
			if(q>=60 && q<=70)
				x2=x2+1;
			if(q>70 && q<=80)
				x3=x3+1;
			if(q>80 && q<=90)
				x4=x4+1;
			if(q>90)
				x5=x5+1;
		}
		dlg.percentage[0]=(float)x1/n-1;
		dlg.percentage[1]=(float)x2/n-1;
		dlg.percentage[2]=(float)x3/n-1;
		dlg.percentage[3]=(float)x4/n-1;
		dlg.percentage[4]=(float)x5/n-1;

		dlg.DoModal();
	}
}

void CStudentSystemDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	if(n==0)
	{
		MessageBox("请先添加数据!");
	}else 
	{
		CTree dlg;
		int i;
		x1=x2=x3=x4=x5=0;
		double q;
		for(i=0;i<=n-1;i++)
		{
			q=atof(m_SList.GetItemText(i,2));	
			if(q<60)
				x1=x1+1;
			if(q>=60 && q<=70)
				x2=x2+1;
			if(q>70 && q<=80)
				x3=x3+1;
			if(q>80 && q<=90)
				x4=x4+1;
			if(q>90)
				x5=x5+1;
		}
		dlg.d1=x1;
		dlg.d2=x2;
		dlg.d3=x3;
		dlg.d4=x4;
		dlg.d5=x5;

		x1=x2=x3=x4=x5=0;
		for(i=0;i<=n-1;i++)
		{
			q=atof(m_SList.GetItemText(i,2));	
			if(q<60)
				x1=x1+1;
			if(q>=60 && q<=70)
				x2=x2+1;
			if(q>70 && q<=80)
				x3=x3+1;
			if(q>80 && q<=90)
				x4=x4+1;
			if(q>90)
				x5=x5+1;
		}
		dlg.percentage[0]=(float)x1/n-1;
		dlg.percentage[1]=(float)x2/n-1;
		dlg.percentage[2]=(float)x3/n-1;
		dlg.percentage[3]=(float)x4/n-1;
		dlg.percentage[4]=(float)x5/n-1;

		if(dlg.DoModal()==IDOK)
		{
		}
		
	}
}
