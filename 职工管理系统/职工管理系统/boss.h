#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class boss:public worker//boss类的同文件声明
{public:
	boss(int id, string name, int dId);//boss的构造函数初始化worker类对象
	virtual void showinfo();//展示boss类信息
	virtual string getdeptname();
};