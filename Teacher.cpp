#include "Teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu()
{
	cout << endl;
	cout << "Hi dear teacher!" << endl;
	cout << "\t\t-------------------------" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|  1. Check all Appmt   |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|  2. Vali order        |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|  0. Logout            |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t-------------------------" << endl;

	cout << "Please select your option: " << endl;
}

void Teacher::showAllOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "No record!" << endl;
		system("pause");
		system("cls");
		return;
	}


	for (int i = 0; i < of.m_Size; i++)
	{
		cout << " Reservation date: " << of.m_orderData[i]["date"];
		cout << " Time Bucket: " << (of.m_orderData[i]["interval"] == "1" ? "Morning" : "Afternoon");
		cout << " stuId:" << of.m_orderData[i]["stuId"] << " ";
		cout << " stuName:" << of.m_orderData[i]["stuName"] << " ";
		cout << " roomId:" << of.m_orderData[i]["roomId"] << " ";

		string status = " status: ";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "【Processing】";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "【Process completely】";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "【Process unsuccessfully】";
		}
		else
		{
			status += "【Has been cancelled】";
		}
	}
	system("pause");
	system("cls");
}

void Teacher::valiOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "No record!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "The appointment of students are as the following: " << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << ",  ";

			cout << " Reservation date: " << of.m_orderData[i]["date"];
			cout << " Time Bucket: " << (of.m_orderData[i]["interval"] == "1" ? "Morning" : "Afternoon");
			cout << " roomId:" << of.m_orderData[i]["roomId"] << " ";

			string status = " status: ";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "【Processing】";
			}
			cout << status << endl;
		}
	}
	cout << "Please enter the resevation that you want to audit: " << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "Please enter the result of your audition: " << endl;
				cout << " 1. Pass" << endl;
				cout << " 2. Fail" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << " Audition complete!" << endl;
				break;
			}
		}
		cout << "Enter incorrectly, please enter again!" << endl;
	}
	system("pause");
	system("cls");
}
