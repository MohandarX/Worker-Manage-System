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
	cout << "0.�˳�" << endl;
	cout << "1.����ְ��" << endl;
	cout << "2.��ʾְ��" << endl;
	cout << "3.ɾ��ְ��" << endl;
	cout << "4.�޸�ְ��" << endl;
	cout << "5.����ְ��" << endl;
	cout << "6.���ձ������" << endl;
	cout << "7.���" << endl;
}
void workerManager::System_exit()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workerManager::Add_worker()
{
	cout << "������Ҫ��ӵ�����: " << endl;
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
			cout << "�����"<< i + 1<<"����ְ�����: " << endl;
			cin >> Id;
			cout << "�����" << i + 1 << "����ְ������: " << endl;
			cin >> Name;
			cout << "ѡ���ְ����λ"
				<< "\t0.Ա��"
				<< "\t1.����"
				<< "\t2.�ܲ�" << endl;
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
		cout << "�ɹ����" << addnum << "��ְ��" << endl;
		this->Save();
	}
	else
	{
		cout << "��������" << endl;
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
		cout << "û��Ա������Ա���ļ�������!!!" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��!!" << endl;
	}
	else
	{
		int del_id;
		int index = -1;
		cout << "��������ɾ����ְ�����" << endl;
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
			cout << "ɾ���ɹ�!!!" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��!!" << endl;
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
		cout << "�ļ������ڻ����ļ�Ϊ��!!" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ�����:" << endl;
		int id;
		cin >> id;
		int ret = this->WorkerIsExist(id);
		if (ret != -1)
		{
			delete this->m_WorkerArray[ret];
			int newid;
			string newname = "";
			int newdid;
			cout << "���ҵ���ְ����Ϊ" << id << "��Ա��,�������µ�ְ����:" << endl;
			cin >> newid;
			cout << "�������µ�����" << endl;
			cin >> newname;
			while (true)
			{
				cout << "�������µ�ְλ"
					<< "\t0.Ա��"
					<< "\t1.����"
					<< "\t2.�ܲ�" << endl;
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
					cout << "ְλ����������!!" << endl;
				}
			}
			cout << "�޸ĳɹ�!!!" << endl;
			this->Save();
		}
		else
		{
			cout << "���޴���!" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerManager::Find_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��!!" << endl;
	}
	else
	{
		int select;
		while (true)
		{
			cout << "������ҷ�ʽ" << endl;
			cout << "0.����������" << endl;
			cout << "1.����Ų���" << endl;
			cin >> select;
			if (select != 0 && select != 1)
			{
				cout << "����Ƿ���������" << endl;
				continue;
			}
			break;
		}
		if (select == 0)
		{
			cout << "��������:" << endl;
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
				cout << "���޴���!" << endl;
			}
		}
		else
		{
			cout << "������:" << endl;
			int f_id;
			cin >> f_id;
			int ret = this->WorkerIsExist(f_id);
			if (ret != -1)
			{
				this->m_WorkerArray[ret]->Show_info();
			}
			else
			{
				cout << "���޴���!" << endl;
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
		cout << "�ļ������ڻ����ļ�Ϊ��!!" << endl;
		system("pause");
	}
	else
	{
		int select = -1;
		while (true)
		{
			cout << "��ѡ������ʽ" << endl;
			cout << "0.���������" << endl;
			cout << "1.����Ž���" << endl;
			cin >> select;
			if (select != 0 && select != 1)
			{
				cout << "����Ƿ���������" << endl;
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
		cout << "����ɹ�!!" << endl;
		this->Save();
		this->Show_Worker();
	}
	system("cls");
}
void workerManager::Clean_File()
{
	char select;
	cout << "ȷ��Ҫ����ļ���????" << endl;
	while (true)
	{
		cout << "������Y/N : " << endl;
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
	cout << "��ճɹ�!!!" << endl;
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