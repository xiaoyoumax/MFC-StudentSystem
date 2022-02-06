// Student.h: interface for the Student class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__76C2B2DE_BD87_47C8_ACDE_0D60A0862D7B__INCLUDED_)
#define AFX_STUDENT_H__76C2B2DE_BD87_47C8_ACDE_0D60A0862D7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Student  
{
public:
//	double sum;
//	double CSum;
	Student(CString ID,CString Name,double Math,double Physical,double English);
	Student();
	virtual ~Student();
	double CEnglish;
	double CMath;
	double CPhysical;
	CString CName;
	CString CId;
};

#endif // !defined(AFX_STUDENT_H__76C2B2DE_BD87_47C8_ACDE_0D60A0862D7B__INCLUDED_)
