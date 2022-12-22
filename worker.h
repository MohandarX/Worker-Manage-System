#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker
{
public:
	//显示个人信息
	virtual void Show_info() = 0;

	//获取岗位名称
	virtual string getDeptname() = 0;

	//员工信息
	int m_id;//员工编号
	string m_name;//员工姓名
	int m_deptid;//部门编号
};