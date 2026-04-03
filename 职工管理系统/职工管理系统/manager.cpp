#include<iostream>
#include"manager.h"
using namespace std;
manager::manager(int id, string name, int dId)//与boss类同理
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = dId;
}
void manager::showinfo()
{
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getdeptname()
		<< "\t职工任务：完成老板交给的任务" << endl;
}
string manager::getdeptname()
{
	return "经理";
}