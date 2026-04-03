#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker//虚基类来初始化成员，当作boss，manager，employee的父类
{
public:
	virtual void showinfo()=0;
	virtual string getdeptname()=0;
	int m_id;
	string m_name;
	int m_deptid;
};