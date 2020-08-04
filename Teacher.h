#pragma once
#include <iostream>
using namespace std;
#include"Identity.h"
#define _CRT_SECURE_NO_WARNINGS
#include"orderFile.h"
#include<vector>

class Teacher :public Identity
{
public:
	Teacher ();

	Teacher(int empId, string name, string pwd);

	virtual void operMenu() ;

	void showAllOrder();

	void valiOrder();

	int m_EmpId;

private:

};

