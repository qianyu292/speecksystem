#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
class manager:public worker//与boss类同理
{
public:
	manager(int id, string name, int dId);
	virtual void showinfo();
	virtual string getdeptname();
};