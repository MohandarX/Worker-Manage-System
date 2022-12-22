#pragma once
#include "worker.h"
#include <iostream>
using namespace std;
class Boss :public worker
{
public:
	Boss(int id, string name, int did);
	void Show_info();
	string getDeptname();
};