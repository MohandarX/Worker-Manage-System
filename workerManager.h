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
	//构造函数
	workerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void System_exit();

	//添加职工
	void Add_worker();

	//保存文件
	void Save();

	//读取文件中有多少人
	int getFileWorkerNum();

	//显示职工
	void Show_Worker();

	//删除职工
	void Del_Worker();
	
	//判断职工是否存在
	int WorkerIsExist(int Id);
	
	//初始化数组
	void initworker();
	
	//编辑职工
	void Mod_Worker();

	//查找职工
	void Find_Worker();

	//按员工编号进排序
	void Sort_Worker();

	//清空文件
	void Clean_File();

	//析构函数
	~workerManager();


	int m_WorkerNum;//职工数量
	worker** m_WorkerArray;//职工指针数组
	bool m_FileIsEmpty;//判断文件是否为空
};