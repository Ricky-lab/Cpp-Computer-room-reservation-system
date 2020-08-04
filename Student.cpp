#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	
	ifs.close();
}

void Student::operMenu()
{
	cout << endl;
	cout << "Hi dear student!" << endl;
	cout << "\t\t-------------------------" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|  1. Apply reservation |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|  2. Check my Appmt    |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|  3. Check all Appmt   |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|  4. Cancel Appmt      |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t|  0. Logout            |" << endl;
	cout << "\t\t|                       |" << endl;
	cout << "\t\t-------------------------" << endl;

	cout << "Please select your option: " << endl;

}

void Student::applyOrder()
{
	cout << "Computer rooms are opened from Mon to Fir!" << endl;
	cout << "Please select the reservation: " << endl;
	cout << "1.Mon" << endl;
	cout << "2.Tue" << endl;
	cout << "3.Wed" << endl;
	cout << "4.Thu" << endl;
	cout << "5.Fri" << endl;

	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "Input incorrectly, please try again!" << endl;

	}

	cout << "Please select the time of the resevaction date" << endl;
	cout << "1. Morning" << endl;
	cout << "2. Afternoon" << endl;

	while (true)
	{
		cin >> interval;
		if (interval>=1&&interval<=2)
		{
			break;
		}

		cout << "Input incorrectly, please try again!" << endl;
	}

	cout << "Please select the Room: " << endl;
	cout << "1. Room 1 " << endl;
	cout << "2. Room 2 " << endl;
	cout << "3. Room 3 " << endl;
	

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}

		cout << "Input incorrectly, please try again!" << endl;
	}

	cout << "Apply successfully! Teachers are auditing! " << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << " ";

	ofs.close();

	system("pause");
	system("cls");

}

void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "Empty record!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << " Reservation date: " << of.m_orderData[i]["date"];
			cout << " Time Bucket: " << (of.m_orderData[i]["interval"] == "1" ? "Morning":"Afternoon");
			cout << " Computer Room: " << of.m_orderData[i]["roomId"];

			string status = " Status: ";
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
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}

void Student::showAllOrder()
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

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "No record!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "The appointment that is processing or has been processed can be cancelled!" << endl;
	cout << "Please enter the number that you want to cancel: " << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << " Reservation date: " << of.m_orderData[i]["date"];
				cout << " Time Bucket: " << (of.m_orderData[i]["interval"] == "1" ? "Morning" : "Afternoon");
				cout << " Computer Room: " << of.m_orderData[i]["roomId"];

				string status = " Status: ";
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
				cout << status << endl;
			}
		}
	}

	cout << "Please enter record that you want to cancel, enter 0 get back: " << endl;
	int select = 0;
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
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "Reservation has been cancelled." << endl;
				break;
			}
		}
		cout << " Enter incorrectly, please try again!" << endl;
	}
	system("pause");
	system("cls");
}
