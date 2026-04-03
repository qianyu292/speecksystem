#include<iostream>
#include"boss.h"
using namespace std;//boss类的实现
boss::boss(int id, string name, int dId)//初始化成员
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = dId;
}
void boss::showinfo()
{
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getdeptname()//用函数返回其职务
		<< "\t职工任务：统筹公司" << endl;
 }
string boss::getdeptname()
{
	return "老板";
}