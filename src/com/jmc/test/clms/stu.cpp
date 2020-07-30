#include "stu.h"

void stu_login()
{
	system("cls");

	cout << "学生登录\n"
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
	
	if (stu_map.count(stu_id) == 1)
	{
		if (stu_map[stu_id].first == stu_name && stu_map[stu_id].second == stu_pwd)
		{
			cout << "\n登录成功！" << endl;
			system("pause");
			stu_function(stu_id, stu_name);
		}
		else
		{
			cout << "\n姓名或密码输入有误！" << endl;
		}
	}
	else
	{
		cout << "\n学号不存在！" << endl;
	}

	system("pause");
	system("cls");

}

void stu_function(string& stu_id, string& stu_name)
{
	while (true)
	{
		system("cls");
		cout << "身份：学生\n请选择以下功能\n\n"
			<< "1.申请预约\n"
			<< "2.查看自身预约状态\n"
			<< "3.查看所有预约\n"
			<< "4.取消预约\n"
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
				request_appiontment(stu_id, stu_name);
				break;
			case 2:
				check_self_appointment_status(stu_name);
				break;
			case 3:
				view_appointments();
				break;
			case 4:
				cancel_self_appointment(stu_name);
				break;
			case 5:
				return;
			default:
				break;
		}
	}
}

void request_appiontment(string& stu_id, string& stu_name)
{
	system("cls");

	for (auto& e : appointment_vec)
	{
		if (e.id == stu_id && e.appointment_status == "审核中")
		{
			cout << "已存在预约，请在取消预约或给出审核结果后再重试" << endl;
			system("pause");
			return;
		}
	}

	cout << "请输入预约的时间：\n"
	 	 << "1.周一\n"
		 << "2.周二\n"
		 << "3.周三\n"
		 << "4.周四\n"
		 << "5.周五\n"
		 << endl;

	size_t choice;
	cin >> choice;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "输入有误请重新预约。" << endl;
		system("pause");
		return;
	}

	if (choice < 1 || choice > 5)
	{
		cout << "输入有误请重新预约。" << endl;
		system("pause");
		return;
	}

	string date = "星期";
	date += choice == 1 ? "一" :
			choice == 2 ? "二" :
			choice == 3 ? "三" :
			choice == 4 ? "四" : "五";

	cout << "\n请输入预约的时段：\n"
		<< "1.上午\n"
		<< "2.下午\n"
		<< endl;

	cin >> choice;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "输入有误请重新预约。" << endl;
		system("pause");
		return;
	}

	if (choice < 1 || choice > 2)
	{
		cout << "输入有误请重新预约。" << endl;
		system("pause");
		return;
	}

	string time = choice == 1 ? "上午" : "下午";

	cout << "\n机房信息如下：" << endl;
	cout << "\n编号\t\t\t最大容量\t\t已占用\n";
	for (auto& e : lab_map)
	{
		cout << e.first << "\t\t\t"
			<< e.second.first << "\t\t\t"
			<< e.second.second
			<< endl;
	}

	cout << "\n请按编号选择机房：\n";
	cin >> choice;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "输入有误请重新预约。" << endl;
		system("pause");
		return;
	}

	if (choice < 1 || choice > lab_map.size())
	{
		cout << "输入有误请重新预约。" << endl;
		system("pause");
		return;
	}

	if (lab_map[choice].second >= lab_map[choice].first)
	{
		cout << "机房已满，预约失败。" << endl;
		system("pause");
		return;
	}

	string lab_id = to_string(choice);
	string appointment_status = "审核中";


	appointment_vec.push_back({ date, time, stu_id, stu_name, lab_id, appointment_status });

	stu_appointment_file.put(date, time, stu_id, stu_name, lab_id, appointment_status);

	cout << "\n预约成功！审核中" << endl;

	system("pause");
}

void check_self_appointment_status(string& stu_name)
{
	system("cls");
	cout << "所有自身预约信息如下：" << endl;
	cout << "\n日期\t\t\t时段\t\t\t机房号\t\t\t预约状态" << endl;
	for (auto& e : appointment_vec)
	{
		if (e.name == stu_name)
		{
			cout << e.date << "\t\t\t"
				 << e.time << "\t\t\t"
				 << e.lab_id << "\t\t\t"
				 << e.appointment_status
				 << endl;
		}
	}					
	cout << endl;
	system("pause");
}



void view_appointments()
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

void cancel_self_appointment(string& stu_name)
{
	system("cls");
	cout << "所有可取消的预约信息如下：\n"
		 << "注：只有审核中和预约成功的才能取消"
		 << endl;
	cout << "\n编号\t\t日期\t\t时段\t\t机房号\t\t预约状态" << endl;
	vector<AppointmentSingleLineRecord> cancel_vec;
	
	for (auto& e : appointment_vec)
		if (e.name == stu_name)
			if (e.appointment_status == "审核中" || e.appointment_status == "预约成功")
				cancel_vec.push_back(e);

	for (size_t i = 0; i < cancel_vec.size(); i++)
	{
		auto e = cancel_vec[i];
		cout << i + 1 << "\t\t"
			 << e.date << "\t\t"
			 << e.time << "\t\t"
			 << e.lab_id << "\t\t"
			 << e.appointment_status
			 << endl;
	}

	cout << "\n请按编号输入要取消的预约记录，0表示返回：" << endl;
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

		if (idx < 0 || idx > cancel_vec.size())
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
		cout << "\n是否取消？\n"
			<< "1.是\n"
			<< "2.否"
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

		if (choice == 2)
		{
			cout << "\n取消预约失败。" << endl;
			system("pause");
			return;
		} 
		else
		{
			for (auto& e : appointment_vec)
			{
				if (e == cancel_vec[idx - 1])
				{
					if (e.appointment_status == "预约成功")
					{
						int lab_id = stoi(e.lab_id);
						lab_map[lab_id].second--;

						lab_file.clear();
						for (auto& e : lab_map)
						{
							lab_file.put(e.first, e.second.first, e.second.second);
						}
					}
					e.appointment_status = "已取消预约";
					break;
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
		}

		cout << "\n取消成功" << endl;
		system("pause");
	}


}


