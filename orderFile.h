#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"GlobalFile.h"
#include<fstream>

class OrderFile
{
public:
	OrderFile();

	void updateOrder();

	map<int, map<string, string>> m_orderData;

	int m_Size;

private:

};

