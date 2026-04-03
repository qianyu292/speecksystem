#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
class teacher :public Identity
{
public:
	teacher();

	teacher(int empid, string name, string m_id);

	virtual void open_menu();

	void showallorder();

	void vallorder()
};