#include"manager.h"
Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Manager::Show_info()
{
	cout << "ְ�����: " << this->m_id
		<< "\tְ������: " << this->m_name
		<< "\tְ����λ: " << this->getDeptname()
		<< "\tְ��: ����ϰ彻��������,���·������Ա��" << endl;
}
string Manager::getDeptname()
{
	return "����";
}