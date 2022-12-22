#include"manager.h"
Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Manager::Show_info()
{
	cout << "职工编号: " << this->m_id
		<< "\t职工姓名: " << this->m_name
		<< "\t职工岗位: " << this->getDeptname()
		<< "\t职责: 完成老板交付的任务,并下发任务给员工" << endl;
}
string Manager::getDeptname()
{
	return "经理";
}