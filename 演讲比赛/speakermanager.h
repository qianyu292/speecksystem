#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<numeric>
#include<deque>
#include<fstream>
#include"speaker.h"
using namespace std;
class speakermanager
{
public:
	speakermanager();

	~speakermanager();

	void show_menu();

	void existsystem();

	vector<int>v1;

	vector<int>v2;

	vector<int>Vvictory;

	map<int, speaker>m_speaker;

	int m_index;

	void initspeech();

	void speechstart();

	void createspeaker();

	void speechdraw();

	void speechcontest();

	void showscore();

	void saverecord();

	void loadrecord();

	bool fileisempty;

	map<int, vector<string>>m_record;

	void showrecord();

	void clearrecord();
};