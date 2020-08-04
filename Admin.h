#pragma once
#include <iostream>
using namespace std;
#include"Identity.h"
#include <string>
#include<fstream>
#include "GlobalFile.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <functional>
#include <algorithm>
#include"ComputerRoom.h"

class Admin :public Identity
{
public:
	Admin ();

	Admin(string name, string pwd);

	virtual void operMenu() ;

	void addPerson();

	void showPerson();

	void showComputer();

	void clearFile();
	
	//in order to delete the same new account
	void initVector();

	vector<Student> vStu;

	vector<Teacher> vTea;

	//check the repetitive information
	bool checkRepeat(int id, int type);

	//Container of Computer Room
	vector<ComputerRoom> vCom;

private:

};

