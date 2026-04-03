#pragma once
#include<iostream>
#include"Identity.h"
using namespace std;
class student :public Identity
{
public:
	student();

	student(int id, string name, string pwd);

    virtual void open_menu();

	void applyorder();

	void showmyorder();

	void showallorder();

	void cancerorder();

	int m_id;
};