#include "admin.h"

void admin_login()
{
	system("cls");

	cout << "管理员登录\n"
		<< "请依次输入以下信息\n"
		<< endl;

	cout << "姓名：";
	string admin_name;
	cin >> admin_name;

	cout << "密码：";
	string admin_pwd;
	cin >> admin_pwd;

	if (admin_map.count(admin_name) == 1)
	{
		if (admin_map[admin_name] == admin_pwd)
		{
			cout << "\n登录成功！" << endl;
			system("pause");
			admin_function();
		}
		else
		{
			cout << "\n账号或密码输入有误！" << endl;
		}
	}
	else
	{
		cout << "\n账号或密码输入有误！" << endl;
	}

	system("pause");
	system("cls");


}

void admin_function()
{
	while (true)
	{
		system("cls");
		cout << "身份：管理员\n请选择以下功能\n\n"
			<< "1.添加账号\n"
			<< "2.查看账号\n"
			<< "3.查看机房\n"
			<< "4.清空预约\n"
			<< "5.注销登录\n"
			<< endl;

		int input;
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
		}

		switch (input)
		{
			case 1:
				add_account();
				break;
			case 2:
				view_accounts();
				break;
			case 3:
				view_labs();
				break;
			case 4:
				clear_appointment();
				break;
			case 5:
				return;
			default:
				break;
		}
	}
	

}

void add_account()
{
	while (true)
	{
		system("cls");
		cout << "请选择添加账号类型\n\n"
			<< "1.学生账号\n"
			<< "2.教师账号\n"
			<< "3.返回上一级\n"
			<< endl;

		int input;
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
		}

		switch (input)
		{
			case 1:
			{
				while (true)
				{
					system("cls");
					cout << "账号添加\n"
						<< "请依次输入以下信息\n"
						<< endl;

					cout << "学号：";
					string stu_id;
					cin >> stu_id;

					cout << "姓名：";
					string stu_name;
					cin >> stu_name;

					cout << "密码：";
					string stu_pwd;
					cin >> stu_pwd;

					if (stu_id[0] == '\0' || stu_name[0] == '\0' || stu_pwd[0] == '\0')
					{
						cout << "\n读取失败，请重新输入!" << endl;
						system("pause");
						return;
					}

					if (stu_map.count(stu_id) == 1)
					{
						cout << "\n学生编号已存在，请重新输入!" << endl;
						system("pause");
					}
					else 
					{
						stu_map.insert(make_pair(stu_id, make_pair(stu_name, stu_pwd)));
						stu_acct_file.put(stu_id, stu_name, stu_pwd);
						cout << "\n添加成功!" << endl;
						system("pause");
						return;
					}
				}
			}
				break;
			case 2:
			{
				while (true)
				{
					system("cls");
					cout << "账号添加\n"
						<< "请依次输入以下信息\n"
						<< endl;

					cout << "职工号：";
					string teacher_id;
					cin >> teacher_id;

					cout << "姓名：";
					string teacher_name;
					cin >> teacher_name;

					cout << "密码：";
					string teacher_pwd;
					cin >> teacher_pwd;

					if (teacher_id[0] == '\0' || teacher_name[0] == '\0' || teacher_pwd[0] == '\0')
					{
						cout << "\n读取失败，请重新输入!" << endl;
						system("pause");
						return;
					}

					if (teacher_map.count(teacher_id) == 1)
					{
						cout << "\n职工号已存在,请重新输入!" << endl;
						system("pause");
					}
					else
					{
						teacher_map.insert(make_pair(teacher_id, make_pair(teacher_name, teacher_pwd)));
						teacher_acct_file.put(teacher_id, teacher_name, teacher_pwd);
						cout << "\n添加成功!" << endl;
						system("pause");
						break;
					}
				}
			}
				break;
			case 3:
				return;
			default:
				break;
		}
	}
}

void view_accounts()
{
	while (true)
	{
		system("cls");
		cout << "请选择查看账号类型\n\n"
			<< "1.学生账号\n"
			<< "2.教师账号\n"
			<< "3.返回上一级\n"
			<< endl;

		int input;
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
		}

		switch (input)
		{
			case 1:
			{
				system("cls");
				cout << "学生账号信息如下：" << endl;
				cout << "\n学号\t\t\t姓名\t\t\t密码" << endl;
				for (auto& e : stu_map)
				{
					string stu_id = e.first;
					string stu_name = e.second.first;
					string stu_pwd = e.second.second;

					cout << stu_id << "\t\t\t"
						 << stu_name << "\t\t\t"
						 << stu_pwd << "\t\t\t"
						 << endl;
				}
				cout << endl;
				system("pause");
			}
				break;
			case 2:
			{
				system("cls");
				cout << "教师账号信息如下：" << endl;
				cout << "\n职工号\t\t\t姓名\t\t\t密码" << endl;
				for (auto& e : teacher_map)
				{
					string teacher_id = e.first;
					string teacher_name = e.second.first;
					string teacher_pwd = e.second.second;

					cout << teacher_id << "\t\t\t"
						 << teacher_name << "\t\t\t"
						 << teacher_pwd
						 << endl;
				}
				cout << endl;
				system("pause");
			}
				break;
			case 3:
				return;
			default:
				break;
		}
	}
}

void view_labs()
{
	system("cls");
	cout << "机房信息如下：" << endl;
	cout << "\n编号\t\t\t最大容量\t\t已占用\n";
	for(auto e : lab_map)
	{
		cout << e.first << "\t\t\t"
			 << e.second.first << "\t\t\t"
			 << e.second.second
			 << endl;
	}
	cout << endl;
	system("pause");
}

void clear_appointment()
{
	system("cls");
	stu_appointment_file.clear();
	lab_file.clear();
	appointment_vec.clear();
	for (auto& e : lab_map)
	{
		e.second.second = 0;
		lab_file.put(e.first, e.second.first, e.second.second);
	}
	cout << "预约已清空！" << endl;
	system("pause");
}
