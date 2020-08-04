#include <iostream>
using namespace std;
#include "GlobalFile.h"
#include "Identity.h"
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"

void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->valiOrder();
		}
		else if (select == 0)
		{
			delete teacher;
			cout << "Logout successfully!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "Process fail! Please enter correctly! " << endl;
			system("pause");
			system("cls");
		}
	}
}


void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;



		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			cout << "View the computer room" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			cout << "Clear the appointment" << endl;
			stu->cancelOrder();
		}
		else if (select == 0)
		{
			delete student;
			cout << "Logout successfully!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "Process fail! Please enter correctly! " << endl;
			system("pause");
			system("cls");
		}
	}
}

void adminMenu(Identity*& admin)
{
	while (true)
	{
		admin->operMenu();

		Admin* adm = (Admin*)admin;
		int select = 0;
		cin >> select;

		

		if (select == 1)
		{
			cout << "Add an account" << endl;
			adm->addPerson();
		}
		else if (select == 2)
		{
			cout << "Check the account information " << endl;
			adm->showPerson();
		}
		else if (select == 3)
		{
			cout << "View the computer room" << endl;
			adm->showComputer();
		}
		else if (select == 4)
		{
			cout << "Clear the appointment" << endl;
			adm->clearFile();
		}
		else if(select == 0)
		{
			delete admin;
			cout << "Logout successfully!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "Process fail! Please enter correctly! " << endl;
			system("pause");
			system("cls");
		}
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "File is not exist" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "Please enter your student Id: " << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "Please enter your Teacher Id: " << endl;
		cin >> id;
	}

	cout << "Please enter your Username: " << endl;
	cin >> name;

	cout << "Please enter your Password: " << endl;
	cin >> pwd;

	if (type == 1)
	{
		//Student
		int fId;
		string fName;
		string fPwd;
		

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "Student identity login successfully!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//teacher
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "Teacher identity login successfully!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//admin
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "Admin identity login successfully!" << endl;
				system("pause");
				system("cls");
				person = new Admin( name, pwd);
				adminMenu(person);
				return;
			}
		}
	}

	cout << "Login fail! Please enter correctly! " << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;

	while (true)
	{
	cout << endl;
	cout << "=======================================================" << endl;
	cout << "||    Welcome to Computer Room Reservation System    ||" << endl;
	cout << "=======================================================" << endl;
	cout << endl;
	cout << "Please select your identity:  " << endl;
	cout << endl;
	cout << "\t     __________________________ " << endl;
	cout << "\t    |                          |"<< endl;
	cout << "\t    |-----1.   Student    -----|" << endl;
	cout << "\t    |--------------------------|" << endl;
	cout << "\t    |-----2.   Teacher    -----|" << endl;
	cout << "\t    |--------------------------|" << endl;
	cout << "\t    |-----3.   Admin      -----|" << endl;
	cout << "\t    |--------------------------|" << endl;
	cout << "\t    |-----4.   Exit       -----|" << endl;
	cout << "\t    |__________________________|" << endl;
	cout << endl;
	cout << "Please enter your selection: " << endl;

	cin >> select;

	switch (select)
	{
	case 1:
		LoginIn(STUDENT_FILE, 1);
		break;

	case 2:
		LoginIn(TEACHER_FILE, 2);
		break;

	case 3:
		LoginIn(ADMIN_FILE, 3);
		break;

	case 4:
		cout << "See you next time! Have a good day!" << endl;
		system("pause");
		return 0;
		break;

	default:
		cout << " Enter wrong number, please retype again!" << endl;
		system("pause");
		system("cls");
		break;
	}

	}

	system("pause");
	return 0;
}

