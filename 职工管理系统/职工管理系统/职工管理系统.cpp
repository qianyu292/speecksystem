#include<iostream>//具体实现文件
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
int main()
{   
	WorkerManager wm;//创建workermanager类的数据类型
	int choice = 0;
	while (true)//死循环，在switch中退出
	{
		wm.show_Menu();//显示菜单
		cout << "请输入你的选项" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitsystem();
			break;
		case 1:
			wm.add_emp();//增加职工
			break;
		case 2:
			wm.showimp();//显示职工
			break;
		case 3:
			wm.del_emp();//删除职工
			break;
		case 4:
			wm.mod_emp();//修改职工
			break;
		case 5:
			wm.find_emp();//查找职工
			break;
		case 6:
			wm.sort_emp();
			//排序职工
			break;
		case 7:
			wm.clear_file();//清空文档
			break;
		default:
			system("cls");//清屏操作
			break;
		}
	}
	return 0;
}