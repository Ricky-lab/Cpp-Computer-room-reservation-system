#include "Admin.h"

Admin::Admin()
{

}

Admin::Admin(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//init the container Vector
	this->initVector();

	//get the information of Computer Room
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs>>c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}

	cout << "The number of the idle Computer(s) is: " << vCom.size() << endl;

	ifs.close();
}

void Admin::operMenu()
{
	cout << endl;
	cout << "Hi dear Admin!" << endl;
	cout << "\t\t-------------------------" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|     1. Add Acc        |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|     2. Check Acc      |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|     3. Check ComRoom  |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|     4. Clear Appmt    |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|     0. Logout         |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t-------------------------" << endl;

	cout << "Please select your option: " << endl;

}

void Admin::addPerson()
{
	cout << "Please select the type of new account: " << endl;
	cout << " 1. Student " << endl;
	cout << " 2. Teacher" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	string errorTip;// error tips

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "Please enter the Student Id";
		errorTip = "The student Id is repeatitive, please creat again! ";
	}
	else if(select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "Please enter the Teacher Id";
		errorTip = "The student Id is repeatitive, please creat again! ";
	}
	else
	{
		cout << "Process fail! Please enter correctly! " << endl;
		system("pause");
		system("cls");
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, 1);

		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "Please enter the name: " << endl;
	cin >> name;

	cout << "Please enter the password: " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "Creating successfully!" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//initialize the container to prevevt the repeatitive account saving
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "Student Id: " << s.m_Id << "\tStudent name: " << s.m_Name << "\tStudent Password: " << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "Teacher Id: " << t.m_EmpId << "\tTeacher name: " << t.m_Name << "\tTeacher Password: " << t.m_Pwd << endl;
}

void Admin::showPerson()
{
	cout << " Please select the type of information: " << endl;
	cout << "1. Check all the students " << endl;
	cout << "2. Check all the teachers" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "All the information of Students are the following: " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "All the information of Teacher are the following: " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

void Admin::showComputer()
{
	cout << "The information of Computer Room are the following: " << endl;
	
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << " Room Number: " << it->m_ComId << " \tComuputer Amount: " << it->m_MaxNum << endl;
	}

	system("pause");
	system("cls");

}

void Admin::clearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "Clear appointment successfully!" << endl;
	system("pause");
	system("cls");
}

void Admin::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "File open unsuccessfully!" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}

	cout << "The number of the Student(s) is: " << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "The number of the Teacher(s) is: " << vTea.size() << endl;
	ifs.close();

}

bool Admin::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else if(type == 2)
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;

}