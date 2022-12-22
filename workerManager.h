#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#define FILENAME "workerfile.txt"
using namespace std;
class workerManager
{
public:
	//���캯��
	workerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void System_exit();

	//���ְ��
	void Add_worker();

	//�����ļ�
	void Save();

	//��ȡ�ļ����ж�����
	int getFileWorkerNum();

	//��ʾְ��
	void Show_Worker();

	//ɾ��ְ��
	void Del_Worker();
	
	//�ж�ְ���Ƿ����
	int WorkerIsExist(int Id);
	
	//��ʼ������
	void initworker();
	
	//�༭ְ��
	void Mod_Worker();

	//����ְ��
	void Find_Worker();

	//��Ա����Ž�����
	void Sort_Worker();

	//����ļ�
	void Clean_File();

	//��������
	~workerManager();


	int m_WorkerNum;//ְ������
	worker** m_WorkerArray;//ְ��ָ������
	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��
};