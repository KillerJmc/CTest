#include "teacher.h"

void teacher_login()
{
	system("cls");

	cout << "教师登录\n"
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

	if (teacher_map.count(teacher_id) == 1)
	{
		if (teacher_map[teacher_id].first == teacher_name && teacher_map[teacher_id].second == teacher_pwd)
		{
			cout << "\n登录成功！" << endl;
			system("pause");
			teacher_function();
		}
		else
		{
			cout << "\n姓名或密码输入有误！" << endl;
		}
	}
	else
	{
		cout << "\n职工号不存在！" << endl;
	}

	system("pause");
	system("cls");
}

void teacher_function()
{
	while (true)
	{
		system("cls");
		cout << "身份：教师\n请选择以下功能\n\n"
			<< "1.查看所有预约\n"
			<< "2.审核预约\n"
			<< "3.注销登录\n"
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
			view_all_appointments();
			break;
		case 2:
			review_appointments();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void view_all_appointments()
{
	system("cls");
	cout << "所有预约信息如下：" << endl;
	cout << "\n日期\t\t时段\t\t学号\t\t学生姓名\t\t机房号\t\t预约状态" << endl;
	for (auto& e : appointment_vec)
	{
		cout << e.date << "\t\t"
			 << e.time << "\t\t"
			 << e.id << "\t\t"
			 << e.name << "\t\t\t"
			 << e.lab_id << "\t\t"
			 << e.appointment_status
			 << endl;
	}
	cout << endl;
	system("pause");
}

void review_appointments()
{
	system("cls");
	vector<AppointmentSingleLineRecord> reviewing_vec;
	for (auto& e : appointment_vec)
	{
		if (e.appointment_status == "审核中") reviewing_vec.push_back(e);
	}

	cout << "待审核的预约记录如下：" << endl;
	cout << "\n编号\t\t日期\t\t时段\t\t学号\t\t学生姓名\t\t机房号\t\t预约状态" << endl;
	for(size_t i = 0; i < reviewing_vec.size(); i++)
	{
		auto e = reviewing_vec[i];
		cout << i + 1 << "\t\t"
			 << e.date << "\t\t"
			 << e.time << "\t\t"
			 << e.id << "\t\t"
			 << e.name << "\t\t\t"
			 << e.lab_id << "\t\t"
			 << e.appointment_status
			 << endl;
	}
	cout << "\n请按编号输入审核的预约记录，0表示返回：" << endl;
	size_t idx;
	while (true)
	{
		cin >> idx;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入有误请重新输入。" << endl;
			system("pause");
			continue;
		}

		if (idx < 0 || idx > reviewing_vec.size())
		{
			cout << "输入有误请重新输入。" << endl;
			system("pause");
			continue;
		}
		break;
	}

	if (idx == 0)
	{
		return;
	} 
	else
	{
		cout << "\n请输入选择结果对于的编号\n"
			 << "1.通过\n"
			 << "2.不通过"
			 << endl;

		int choice;
		while (true)
		{
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "输入有误请重新输入。" << endl;
				system("pause");
				continue;
			}

			if (idx < 1 || idx > 2)
			{
				cout << "输入有误请重新输入。" << endl;
				system("pause");
				continue;
			}
			break;
		}

		for (auto& e : appointment_vec)
		{
			if (e == reviewing_vec[idx - 1])
			{
				if (e.appointment_status == "审核中")
				{
					e.appointment_status = idx == 1 ? "预约成功" : "预约失败";
					break;
				}
			}
		}
			
		stu_appointment_file.clear();
		stringstream ss;
		for (auto& e : appointment_vec)
		{
			ss << e.date + " " + e.time + " " +
			      e.id + " " + e.name + " " +
				  e.lab_id + " " + e.appointment_status + " \n";
		}
		stu_appointment_file << ss.str();

		if (idx == 1)
		{
			int lab_id = stoi(reviewing_vec[idx - 1].lab_id);
			lab_map[lab_id].second++;

			lab_file.clear();
			for (auto& e : lab_map)
			{
				lab_file.put(e.first, e.second.first, e.second.second);
			}
		}

		cout << "\n审核完毕" << endl;
		system("pause");
	}
	
}
