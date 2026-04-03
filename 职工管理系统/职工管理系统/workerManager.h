#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empfile.txt"
class WorkerManager//主要类声明
{
public:
	WorkerManager();//构造函数

	void show_Menu();//显示菜单

	void exitsystem();//退出系统

	int m_empnum;//职工数量

	worker** m_emparray;//职工数组，储存职工信息

	bool m_feelisempty;//看文件是否为空

	void add_emp();//添加职工功能

	void save();//写文件功能

	int get_empnum();//看文件是否为空

	void init_emp();//写进文件功能

	void showimp();//显示职工功能

	void del_emp();//删除职工功能

	int isexist(int id);//查看id编号员工是否存在

	void mod_emp();//修改员工功能

	void find_emp();//查找员工功能

	void sort_emp();//排序员工功能

	void clear_file();//清空文档功能

	~WorkerManager();//析构函数
};