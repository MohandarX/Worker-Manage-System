#include"workerManager.h"
workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		this->m_WorkerNum = 0;
		this->m_FileIsEmpty = true;
		this->m_WorkerArray = NULL;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_WorkerNum = 0;
		this->m_FileIsEmpty = true;
		this->m_WorkerArray = NULL;
		ifs.close();
		return;
	}
	this->m_WorkerNum = this->getFileWorkerNum();
	this->m_WorkerArray = new worker * [this->m_WorkerNum];
	this->initworker();
}
void workerManager::Show_Menu()
{
	cout << "0.退出" << endl;
	cout << "1.增加职工" << endl;
	cout << "2.显示职工" << endl;
	cout << "3.删除职工" << endl;
	cout << "4.修改职工" << endl;
	cout << "5.查找职工" << endl;
	cout << "6.按照编号排序" << endl;
	cout << "7.清空" << endl;
}
void workerManager::System_exit()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workerManager::Add_worker()
{
	cout << "输入想要添加的人数: " << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newSize = this->m_WorkerNum + addnum;
		worker** newspace = new worker * [newSize];
		if (this->m_WorkerArray != NULL)
		{
			for (int i = 0; i < this->m_WorkerNum; ++i)
			{
				newspace[i] = this->m_WorkerArray[i];
			}
		}
		for (int i = 0; i < addnum; ++i)
		{
			int Id;
			string Name;
			int Did;
			cout << "输入第"<< i + 1<<"个新职工编号: " << endl;
			cin >> Id;
			cout << "输入第" << i + 1 << "个新职工姓名: " << endl;
			cin >> Name;
			cout << "选择该职工岗位"
				<< "\t0.员工"
				<< "\t1.经理"
				<< "\t2.总裁" << endl;
			cin >> Did;
			worker* twk = NULL;
			switch (Did)
			{
			case 0:
				twk = new Employee(Id, Name, Did);
				break;
			case 1:
				twk = new Manager(Id, Name, Did);
				break;
			case 2:
				twk = new Boss(Id, Name, Did);
			default:
				break;
			}
			newspace[this->m_WorkerNum + i] = twk;
		}
		delete[] this->m_WorkerArray;
		this->m_WorkerArray = newspace;
		this->m_WorkerNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "成功添加" << addnum << "名职工" << endl;
		this->Save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void workerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_WorkerNum; ++i)
	{
		ofs << this->m_WorkerArray[i]->m_id << " "
			<< this->m_WorkerArray[i]->m_name << " "
			<< this->m_WorkerArray[i]->m_deptid << endl;
	}
	ofs.close();
}
int workerManager::getFileWorkerNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int tid;
	string tname;
	int tdid;
	int num = 0;
	while (ifs >> tid && ifs >> tname && ifs >> tdid)
	{
		++num;
	}
	ifs.close();
	return num;
}
void workerManager::Show_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "没有员工或者员工文件不存在!!!" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_WorkerNum; ++i)
		{
			this->m_WorkerArray[i]->Show_info();
		}
	}
	system("pause");
	system("cls");
}
void workerManager::Del_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空!!" << endl;
	}
	else
	{
		int del_id;
		int index = -1;
		cout << "输入你想删除的职工编号" << endl;
		cin >> del_id;
		index = this->WorkerIsExist(del_id);
		if (index != -1)
		{
			delete this->m_WorkerArray[index];
			for (int i = index; i < this->m_WorkerNum - 1; ++i)
			{
				this->m_WorkerArray[i] = this->m_WorkerArray[i + 1];
			}
			this->m_WorkerNum--;
			this->Save();
			cout << "删除成功!!!" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工!!" << endl;
		}
		system("pause");
		system("cls");
	}
}
int workerManager::WorkerIsExist(int Id)
{
	for (int i = 0; i < this->m_WorkerNum; ++i)
	{
		if (this->m_WorkerArray[i]->m_id == Id)
			return i;
	}
	return -1;
}
void workerManager::initworker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int tid;
	string tname;
	int tdid;
	int index = 0;
	while (ifs >> tid && ifs >> tname && ifs >> tdid)
	{
		worker* twk = NULL;
		if (tdid == 0)
		{
			twk = new Employee(tid, tname, tdid);
		}
		else if (tdid == 1)
		{
			twk = new Manager(tid, tname, tdid);
		}
		else
		{
			twk = new Boss(tid, tname, tdid);
		}
		this->m_WorkerArray[index++] = twk;
	}
	ifs.close();
}
void workerManager::Mod_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空!!" << endl;
	}
	else
	{
		cout << "输入你要修改的职工编号:" << endl;
		int id;
		cin >> id;
		int ret = this->WorkerIsExist(id);
		if (ret != -1)
		{
			delete this->m_WorkerArray[ret];
			int newid;
			string newname = "";
			int newdid;
			cout << "查找到了职工号为" << id << "的员工,请输入新的职工号:" << endl;
			cin >> newid;
			cout << "请输入新的姓名" << endl;
			cin >> newname;
			while (true)
			{
				cout << "请输入新的职位"
					<< "\t0.员工"
					<< "\t1.经理"
					<< "\t2.总裁" << endl;
				cin >> newdid;
				if (newdid == 0)
				{
					this->m_WorkerArray[ret] = new Employee(newid, newname, newdid);
					break;
				}
				else if (newdid == 1)
				{
					this->m_WorkerArray[ret] = new Manager(newid, newname, newdid);
					break;
				}
				else if (newdid == 2)
				{
					this->m_WorkerArray[ret] = new Boss(newid, newname, newdid);
					break;
				}
				else
				{
					cout << "职位编号输入错误!!" << endl;
				}
			}
			cout << "修改成功!!!" << endl;
			this->Save();
		}
		else
		{
			cout << "查无此人!" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerManager::Find_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空!!" << endl;
	}
	else
	{
		int select;
		while (true)
		{
			cout << "输入查找方式" << endl;
			cout << "0.按姓名查找" << endl;
			cout << "1.按编号查找" << endl;
			cin >> select;
			if (select != 0 && select != 1)
			{
				cout << "输入非法重新输入" << endl;
				continue;
			}
			break;
		}
		if (select == 0)
		{
			cout << "输入姓名:" << endl;
			string f_name;
			bool flag = true;
			cin >> f_name;
			for (int i = 0; i < this->m_WorkerNum; ++i)
			{
				if (this->m_WorkerArray[i]->m_name == f_name)
				{
					this->m_WorkerArray[i]->Show_info();
					flag = false;
				}
			}
			if (flag)
			{
				cout << "查无此人!" << endl;
			}
		}
		else
		{
			cout << "输入编号:" << endl;
			int f_id;
			cin >> f_id;
			int ret = this->WorkerIsExist(f_id);
			if (ret != -1)
			{
				this->m_WorkerArray[ret]->Show_info();
			}
			else
			{
				cout << "查无此人!" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void workerManager::Sort_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空!!" << endl;
		system("pause");
	}
	else
	{
		int select = -1;
		while (true)
		{
			cout << "请选择排序方式" << endl;
			cout << "0.按编号升序" << endl;
			cout << "1.按编号降序" << endl;
			cin >> select;
			if (select != 0 && select != 1)
			{
				cout << "输入非法重新输入" << endl;
				continue;
			}
			break;
		}
		for (int i = 0; i < this->m_WorkerNum; ++i)
		{
			int minormax = i;
			for (int j = i + 1; j < this->m_WorkerNum; ++j)
			{
				if (select == 0)
				{
					if (this->m_WorkerArray[i]->m_id > this->m_WorkerArray[j]->m_id)
					{
						minormax = j;
					}
				}
				else
				{
					if (this->m_WorkerArray[i]->m_id < this->m_WorkerArray[j]->m_id)
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				worker* t = this->m_WorkerArray[i];
				this->m_WorkerArray[i] = this->m_WorkerArray[minormax];
				this->m_WorkerArray[minormax] = t;
			}
		}
		cout << "排序成功!!" << endl;
		this->Save();
		this->Show_Worker();
	}
	system("cls");
}
void workerManager::Clean_File()
{
	char select;
	cout << "确定要清空文件吗????" << endl;
	while (true)
	{
		cout << "请输入Y/N : " << endl;
		cin >> select;
		if (select == 'Y' || select == 'y')
		{
			break;
		}
		if (select == 'N' || select == 'n')
		{
			return;
		}
	}
	ofstream ofs(FILENAME, ios::trunc);
	ofs.close();
	if (this->m_WorkerArray != NULL)
	{
		for (int i = 0; i < this->m_WorkerNum; ++i)
		{
			if (this->m_WorkerArray[i] != NULL)
			{
				delete this->m_WorkerArray[i];
			}
		}
		this->m_WorkerNum = 0;
		this->m_FileIsEmpty = true;
		delete[] this->m_WorkerArray;
		this->m_WorkerArray = NULL;
	}
	cout << "清空成功!!!" << endl;
	system("pause");
	system("cls");
}
workerManager::~workerManager()
{
	if (this->m_WorkerArray != NULL)
	{
		delete[] this->m_WorkerArray;
		this->m_WorkerArray = NULL;
	}
}