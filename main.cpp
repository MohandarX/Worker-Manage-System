#include<iostream>
#include"workerManager.h"
using namespace std;
int main()
{
	workerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "����ѡ��: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�
			wm.System_exit();
			break;
		case 1://����ְ��
			wm.Add_worker();
			break;
		case 2://��ʾְ��
			wm.Show_Worker();
			break;
		case 3://ɾ��ְ��
			wm.Del_Worker();
			break;
		case 4://�޸�ְ��
			wm.Mod_Worker();
			break;
		case 5://����ְ��
			wm.Find_Worker();
			break;
		case 6://�����������
			wm.Sort_Worker();
			break;
		case 7://���
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}