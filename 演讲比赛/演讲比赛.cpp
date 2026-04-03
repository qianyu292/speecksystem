#include<iostream>
#include"speakermanager.h"
using namespace std;
int main()
{
	speakermanager wm;
	while (true)
	{
		wm.show_menu();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			wm.existsystem();
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
	return 0;
}