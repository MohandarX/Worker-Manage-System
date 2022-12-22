#pragma once
#include "worker.h"
#include <iostream>
using namespace std;
class Employee:public worker
{
public:
	Employee(int id,string name,int did);
	void Show_info();
	string getDeptname();
};