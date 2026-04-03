#include"speakermanager.h"
#include<iostream>
using namespace std;
speakermanager::speakermanager()
{
	this->initspeech();

	this->createspeaker();
}
void speakermanager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 **************" << endl;
	cout << "*************  1.开始演讲比赛 **************" << endl;
	cout << "*************  2.查看往届记录 **************" << endl;
	cout << "*************  3. 清空比赛记录**************" << endl;
	cout << "*************  0. 退出比赛程序**************" << endl;
	cout << "********************************************" << endl;
}
void speakermanager::existsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void speakermanager::speechstart()
{
	//抽签
	this->speechdraw();
	//分组比赛
	this->speechcontest();
	//显示分数
	this->showscore();
	//开始第二轮比赛
	this->m_index++;
	//抽签
	this->speechdraw();
	//分组比赛
	this->speechcontest();
	//显示分数
	this->showscore();

	this->initspeech();
}
void speakermanager::createspeaker()
{
	string nameseed = "ABCDEFGHIKLM";
	for (int i = 0; i < 12; ++i)
	{
		string name = "选手";
		name += nameseed[i];
		speaker sp;
		sp.m_name = name;

		for (int j = 0; j < 2; ++j)
		{
			sp.m_score[j] = 0;
		}
		v1.push_back(10001 + i);
		this->m_speaker.insert(make_pair(10001 + i, sp));
	}
}
void speakermanager::initspeech()//初始化数据
{
	v1.clear();

	v2.clear();

	Vvictory.clear();

	m_speaker.clear();

	int m_index=1;
}
void speakermanager::speechdraw()
{
	cout << "第" << this->m_index << "轮比赛正式开始" << endl;
	cout << "抽签结果如下" << endl;
	random_shuffle(v1.begin(), v1.end());
	if (this->m_index == 1)
	{
		for (auto it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		for (auto it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "抽签完毕" << endl;
	system("pause");
}
void speakermanager::speechcontest()
{
	multimap<double, int, greater<double>()>groupscore;
	int num = 0;
	vector<int>v;
	if (this->m_index == 1)
	{
		v = v1;
	}
	else
	{
		v = v2;
	}
	cout << "各选手比赛成绩如下" << endl;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		num++;
		deque<double>d;
		for (int i = 0; i < 10; ++i)
		{
			double s = (rand() % 401 + 600) / 10.f;
			d.push_back(s);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0);
		double avg = sum / d.size();
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;
		groupscore.insert(make_pair(avg, *it));
	}
	if (num % 6 == 0)
	{
		cout << "第" << num / 6 << "小组比赛成绩如下" << endl;
		for (auto it = groupscore.begin(); it != groupscore.end(); it++)
		{
			cout << "编号:" << it->second << " " << "姓名:" << this->m_speaker[it->second].m_name << " "
				<< "分数" << it->first << endl;
		}
		int count = 0;
		for (auto it = groupscore.begin(); it != groupscore.end()&&count<3; it++,count++)
		{
			if (this->m_index == 1)
			{
				v2.push_back(it->second);
			}
			else
			{
				this->Vvictory.push_back(it->second);
			}
			groupscore.clear();
			cout << endl;
		}
	}
	cout << "比赛结束" << endl;
	system("pause");
}
void speakermanager::showscore()
{
	cout << "第" << this->m_index << "轮晋级人员如下" << endl;
	vector<int>vs;
	if (this->m_index == 1)
	{
		vs = v2;
	}
	else
	{
		vs = Vvictory;
	}
	for (auto it = vs.begin(); it != vs.end(); it++)
	{
		cout << "编号:" << *it << "姓名:" << this->m_speaker[*it].m_name
			<< "分数:" << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	system("pause");
	system("cls");
	this->show_menu();
}
void speakermanager::saverecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = Vvictory.begin(); it != Vvictory.end(); ++it)
	{
		ofs << *it << ","
			<< this->m_speaker[*it].m_score[1] << endl;
	}
	ofs << endl;
	ofs.close();
	cout << "文件已存入" << endl;
	this->fileisempty = false;
}
void speakermanager::loadrecord()
{
	fstream ifs("speech.csx", ios::in);
	if (!ifs.is_open())
	{
		this->fileisempty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileisempty = true;
		cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	this->fileisempty = false;
	ifs.putback(ch);
	vector<string>v;
	int pos = -1;
	int start = 0;
	string data;
	int index = 0;
	while (ifs >> data)
	{
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);

			v.push_back(temp);
			start = pos + 1;
		}
	}
	this->m_record.insert(make_pair(index, v));
	index++;
	ifs.close();
}
void speakermanager::showrecord()
{
	if (this->fileisempty)
	{
		cout << "文件为空或不存在" << endl;

	}
	for (int i = 0; i < this->m_record.size(); ++i)
	{
		cout << "第" << i + 1 << "届"
			<< "冠军编号" << this->m_record[i][0] << "得分" << this->m_record[i][1] << " "
			<< "亚军编号" << this->m_record[i][2] << "得分" << this->m_record[i][3] << " "
			<< "季军编号" << this->m_record[i][4] << "得分" << this->m_record[i][5] << " "
			<< endl;
	}
	system("pause");
	system("cls");
}
void speakermanager::clearrecord()
{
	cout << "确认清空?" << endl;
	cout << "1.清空" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initspeech();

		this->createspeaker();

		this->loadrecord();
	}
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
speakermanager::~speakermanager()
{

}