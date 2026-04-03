#include<iostream>
using namespace std;
int main()
{
	int select = 0;
	while (true)
	{
		cout << "------------欢迎进入机房预约系统------------" << endl;
		cout << "请输入你的身份" << endl;
		cout << "-----------------1.学生-------------------" << endl;
		cout << "-----------------2.老师-------------------" << endl;
		cout << "-----------------3.管理员-----------------" << endl;
		cout << "-----------------0.退出-------------------" << endl;
		cout << "请输入你的选择" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}