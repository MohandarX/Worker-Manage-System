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
		cout << "输入选项: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出
			wm.System_exit();
			break;
		case 1://增加职工
			wm.Add_worker();
			break;
		case 2://显示职工
			wm.Show_Worker();
			break;
		case 3://删除职工
			wm.Del_Worker();
			break;
		case 4://修改职工
			wm.Mod_Worker();
			break;
		case 5://查找职工
			wm.Find_Worker();
			break;
		case 6://按照序号排序
			wm.Sort_Worker();
			break;
		case 7://清空
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}