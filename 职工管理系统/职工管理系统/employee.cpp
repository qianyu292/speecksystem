#include<iostream>
#include"employee.h"
using namespace std;//与boss类同理
employee::employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = dId;
}
void employee::showinfo()
{
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getdeptname()
		<< "\t岗位职责:完成经理交给的任务" << endl;
}
string employee::getdeptname()
{
	return string("员工");
}