#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker
{
public:
	//��ʾ������Ϣ
	virtual void Show_info() = 0;

	//��ȡ��λ����
	virtual string getDeptname() = 0;

	//Ա����Ϣ
	int m_id;//Ա�����
	string m_name;//Ա������
	int m_deptid;//���ű��
};