#include"boss.h"
Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Boss::Show_info()
{
	cout << "ְ�����: " << this->m_id
		<< "\tְ������: " << this->m_name
		<< "\tְ����λ: " << this->getDeptname()
		<< "\tְ��: ����˾��������" << endl;
}
string Boss::getDeptname()
{
	return "�ܲ�";
}
