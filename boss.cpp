#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Boss::Show_info()
{
	cout << "职工编号: " << this->m_id
		<< "\t职工姓名: " << this->m_name
		<< "\t职工岗位: " << this->getDeptname()
		<< "\t职责: 管理公司所有事务" << endl;
}
string Boss::getDeptname()
{
	return "总裁";
}
