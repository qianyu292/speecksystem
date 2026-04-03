#pragma once
#include<iostream>
using namespace std;
class Identity
{
public:
	virtual void open_menu() = 0;

	string m_name;
	string m_pwd;
};