#pragma once
#include "worker.h"
#include <iostream>
using namespace std;
class Manager :public worker
{
public:
	Manager(int id, string name, int did);
	void Show_info();
	string getDeptname();
};
