; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStudentSystemDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StudentSystem.h"

ClassCount=8
Class1=CStudentSystemApp
Class2=CStudentSystemDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_DIALOG2
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1
Class4=CDlgAdd
Resource4=IDD_ADD
Class5=CDlgRefine
Resource5=IDD_ABOUTBOX
Class6=CDrawDlg
Resource6=IDD_STUDENTSYSTEM_DIALOG
Class7=CBing
Resource7=IDD_DIALOG3
Class8=CTree
Resource8=IDD_DIALOG4

[CLS:CStudentSystemApp]
Type=0
HeaderFile=StudentSystem.h
ImplementationFile=StudentSystem.cpp
Filter=N

[CLS:CStudentSystemDlg]
Type=0
HeaderFile=StudentSystemDlg.h
ImplementationFile=StudentSystemDlg.cpp
Filter=D
LastObject=CStudentSystemDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=StudentSystemDlg.h
ImplementationFile=StudentSystemDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STUDENTSYSTEM_DIALOG]
Type=1
Class=CStudentSystemDlg
ControlCount=23
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_OPEN,button,1342242816
Control3=IDC_ADD,button,1342242816
Control4=IDC_DELETE,button,1342242816
Control5=IDC_REFINE,button,1342242816
Control6=IDC_SORT,button,1342242816
Control7=IDC_COUNT,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_name,edit,1350631552
Control10=IDC_SEARCH,button,1342242816
Control11=IDC_CLEAR,button,1342242816
Control12=IDC_WRITERIN,button,1342242816
Control13=IDC_num,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_LIST2,SysListView32,1350631425
Control16=IDC_BUTTON1,button,1342242816
Control17=IDC_BUTTON2,button,1342242816
Control18=IDC_BUTTON3,button,1342242816
Control19=IDC_STATIC,static,1342308352
Control20=IDC_BUTTON4,button,1342242816
Control21=IDC_BUTTON5,button,1342242816
Control22=IDC_BUTTON6,button,1342242816
Control23=IDC_BUTTON7,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CDlgRefine
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631552
Control10=IDC_EDIT3,edit,1350631552
Control11=IDC_EDIT4,edit,1350631552
Control12=IDC_EDIT5,edit,1350631552

[DLG:IDD_ADD]
Type=1
Class=CDlgAdd
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631552
Control10=IDC_EDIT3,edit,1350631552
Control11=IDC_EDIT4,edit,1350631552
Control12=IDC_EDIT5,edit,1350631552

[CLS:CDlgAdd]
Type=0
HeaderFile=DlgAdd.h
ImplementationFile=DlgAdd.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgAdd

[CLS:CDlgRefine]
Type=0
HeaderFile=DlgRefine.h
ImplementationFile=DlgRefine.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT5

[DLG:IDD_DIALOG2]
Type=1
Class=CDrawDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDrawDlg]
Type=0
HeaderFile=DrawDlg.h
ImplementationFile=DrawDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CDrawDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=CBing
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CBing]
Type=0
HeaderFile=Bing.h
ImplementationFile=Bing.cpp
BaseClass=CDialog
Filter=D
LastObject=CBing
VirtualFilter=dWC

[DLG:IDD_DIALOG4]
Type=1
Class=CTree
ControlCount=11
Control1=IDC_TREE1,SysTreeView32,1350631431
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT1,edit,1350631552
Control8=IDC_EDIT2,edit,1350631552
Control9=IDC_EDIT3,edit,1350631552
Control10=IDC_EDIT4,edit,1350631552
Control11=IDC_EDIT5,edit,1350631552

[CLS:CTree]
Type=0
HeaderFile=Tree.h
ImplementationFile=Tree.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TREE1

