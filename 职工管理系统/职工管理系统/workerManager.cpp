#include<iostream>
using namespace std;
#include "workerManager.h"
WorkerManager::WorkerManager()//构造函数具体实现
{
	ifstream ifs;//创建ifstream类型数据结构
	ifs.open(FILENAME, ios::in);//写文件中的打开文件
	if (!ifs.is_open())//查看文档是否存在
	{
		cout << "文件不存在" << endl;
		this->m_empnum = 0;//将职工数量清空

		this->m_emparray = NULL;//将职工数组清空

		this->m_feelisempty = true;
		ifs.close();//写文件中的关闭文档
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_empnum = 0;

		this->m_emparray = NULL;

		this->m_feelisempty = true;
		ifs.close();
		return;
	}
	int num = this->get_empnum();//在文件中添加职工数量
	cout << "职工人数为" << num << endl;
	this->m_empnum = num;

	this->m_emparray = new worker * [this->m_empnum];//添加职工数组
	this->init_emp();//文件中添加职工
	for (int i = 0; i < this->m_empnum; ++i)
	{
		cout << "职工编号" << this->m_emparray[i]->m_id
			<< "职工姓名" << this->m_emparray[i]->m_name
			<< "职工岗位" << this->m_emparray[i]->m_deptid << endl;
	}
}
void WorkerManager::add_emp()//添加职工功能具体实现
{
	cout << "请输入职工数量" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_empnum + addnum;//开辟新空间
		worker ** newspace = new worker*[newsize];//开辟新数组内存
		if (this->m_emparray != NULL)//判断是否存在职工
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparray[i];//将原职工赋值给新内存
			}
		}
		for (int i = 0; i < addnum; i++)//输入新职工
		{
			int id;
			string name;
			int dselect;
			cout << "请输入" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dselect;
			worker* worker = NULL;
			switch (dselect)//根据不同职位初始化员工
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace[this->m_empnum + i] = worker;//开辟新的内存
		}
		delete[] this->m_emparray;

		this->m_emparray = newspace;

		this->m_empnum = newsize;

		cout << "成功添加" << addnum <<"名新职工" <<endl;
		this->save();
		this->m_feelisempty = false;
	}
	else
	{
		cout << "输入有误" << endl;
	}
}
void WorkerManager::save()//写进文件
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_empnum; ++i)
	{
		ofs << this->m_emparray[i]->m_id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_deptid << endl;
	}
	ofs.close();
}
int WorkerManager::get_empnum()//写进文件
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}
void WorkerManager::init_emp()//写进文件
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker* worker = NULL;
		if (dId == 1)
		{
			worker = new employee(id, name, dId);
		}
		else if(dId==2)
		{
			worker = new manager(id, name, dId);
		}
		else
		{
			worker = new boss(id, name, dId);
		}
		this->m_emparray[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManager::showimp()//显示职工
{
	if (this->m_feelisempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_empnum; ++i)
		{
			this->m_emparray[i]->showinfo();
		}
	}
	system("pause");//停止刷新操作
	system("cls");//清屏操作
}
void WorkerManager::show_Menu()//显示菜单
{
	cout << "********************************" << endl;
	cout << "******欢迎使用职工管理系统******" << endl;
	cout << "*********0.退出管理程序*********" << endl;
	cout << "*********1.增加职工信息*********" << endl;
	cout << "*********2.显示员工信息*********" << endl;
	cout << "*********3.删除离职员工*********" << endl;
	cout << "*********4.修改职工信息*********" << endl;
	cout << "*********5.查找职工信息*********" << endl;
	cout << "*********6.按照编号排序*********" << endl;
	cout << "*********7.清空所有文档*********" << endl;
	cout << "********************************" << endl;
	cout << endl;
} 
void WorkerManager::exitsystem()//退出菜单
{ 
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::del_emp()//删除职工
{
	if (this->m_feelisempty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号" << endl;
		int id;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1) 
		{
			for (int i = index; i < this->m_empnum - 1; ++i)
			{
				this->m_emparray[i] = this->m_emparray[i + 1];//后一个覆盖前一个信息
			}
			this->m_empnum--;//将职工数量减1

			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::isexist(int id)//看员工是否存在
{
	int index = -1;
	for (int i = 0; i < m_empnum; ++i)
	{
		if (this->m_emparray[i]->m_id = id)//遍历整个职工数组（指针）
		{
			index = i;
			break;
		}
	}
	return index;//返回职工编号
}
void WorkerManager::mod_emp()//修改职工具体实现
{
	if (this->m_feelisempty)
	{
		cout << "文件为空或文件不存在" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;

		int ret = this->isexist(id);//判断职工是否存在
		if (ret != -1)
		{
			delete this->m_emparray[ret];//释放该职工内存，利于重新编写

			int newid;
			string newname;
			int newdId;

			cout << "查到" << id << "号职工，请重新输入" << endl;
			cin >> newid;
			cout << "请输入新的姓名" << endl;
			cin >> newname;
			cout << "请输入新的岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			cin >> newdId;
			worker* worker = NULL;
			switch (newdId)
			{
			case 1:
				worker = new employee(newid, newname, newdId);
				break;
			case 2:
				worker = new manager(newid, newname, newdId);
				break;
			case 3:
				worker = new boss(newid, newname, newdId);
				break;
			default:
				break;
			}
			this->m_emparray[ret] = worker;

			cout << "修改成功" << endl;

			this->save();
		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::find_emp()//查找职工
{
	if (this->m_feelisempty)
	{
		cout << "文件为空" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找的编号" << endl;
			cin >> id;
			
			int ret = isexist(id);//id是职工编号
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下" << endl;
				this->m_emparray[ret]->showinfo();//显示职工信息
			}
			else {
				cout << "查找失败" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;

			bool flag = false;//设置标记

			for (int i = 0; i < this->m_empnum; ++i)
			{
				if (this->m_emparray[i]->m_name == name)
				{
					cout << "查找成功，职工编号如下"
						<< this->m_emparray[i]->m_id
						<< endl;
					this->m_emparray[i]->showinfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入错误" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::sort_emp()//排序员工具体实现
{
	if (this->m_feelisempty)
	{
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;

		int select = 0;
		cin >> select;//选择排序算法
		for (int i = 0; i < m_empnum; ++i)
		{
			int minormax = 1;
			for (int j = i + 1; j < m_empnum; ++j)
			{
				if (select == 1)
				{
					if (this->m_emparray[minormax]->m_id > this->m_emparray[j]->m_id)
					{
						minormax = j;
					}
				}
				else
				{
					if (this->m_emparray[minormax]->m_id < this->m_emparray[j]->m_id)
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				worker* temp = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[minormax];
				this->m_emparray[minormax] = temp;
			}
		}
		cout << "排序成功" << endl;
		this->save();
		this->showimp();
	}
}
void WorkerManager::clear_file()
{
	cout << "确定清空吗" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->m_empnum; ++i)
			{
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;
			}
			delete[]m_emparray;
			this->m_emparray = NULL;
			this->m_empnum = 0;
			this->m_feelisempty = true;
		}
	}
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()//析构函数
{
    if (this->m_emparray != NULL)
	{

		delete[] this->m_emparray;
		this->m_emparray = NULL;
	}
}