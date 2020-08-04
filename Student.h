#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include<vector>
#include"ComputerRoom.h"
#include<fstream>
#include"GlobalFile.h"
#include"orderFile.h"

class Student :public Identity
{
public:
	Student();

	Student(int id, string name, string pwd);

	virtual void operMenu() ;

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	int m_Id;

	//container of the Computer Room
	vector<ComputerRoom> vCom;
	
private:

};

