#include "start.h"

static void init()
{
	//如果不存在创建数据文件夹
	file installed_file(DATA_PATH + "installed");
	if (!installed_file.is_open())
	{ 
		system(("mkdir \"" + ACCT_PATH + "\"").c_str());
		system(("mkdir \"" + APPOINTMENT_PATH + "\"").c_str());
		system(("mkdir \"" + LAB_PATH + "\"").c_str());
		installed_file.create();

		admin_acct_file.create();
		teacher_acct_file.create();
		stu_acct_file.create();
		lab_file.create();
		stu_appointment_file.create();

		//默认管理员用户
		{
			admin_acct_file.put("Jmc", "010809");
			admin_acct_file.put("ZHANGX.7R", "wwwwwwww20010809");
			admin_acct_file.put("1654441634", "4361444561");
			admin_acct_file.refresh_ifs();
		}

		//默认机房
		{
			lab_file.put(1, 20, 0);
			lab_file.put(2, 50, 0);
			lab_file.put(3, 100, 0);
			lab_file.refresh_ifs();
		}
	}

	//将文件中管理员，教师，学生账号以及机房信息，预约信息提取到map
	string admin_name, admin_pwd;
	string teacher_id, teacher_name, teacher_pwd;
	string stu_id, stu_name, stu_pwd;
	int lab_id, lab_max_size, lab_occupied_size;
	string date, time, id, name, lab__id, appointment_status;

	while (admin_acct_file.get(admin_name, admin_pwd))
	{
		admin_map.insert(make_pair(admin_name, admin_pwd));
	}

	while (teacher_acct_file.get(teacher_id, teacher_name, teacher_pwd))
	{
		teacher_map.insert(make_pair(teacher_id, make_pair(teacher_name, teacher_pwd)));
	}

	while (stu_acct_file.get(stu_id, stu_name, stu_pwd))
	{
		stu_map.insert(make_pair(stu_id, make_pair(stu_name, stu_pwd)));
	}

	while (lab_file.get(lab_id, lab_max_size, lab_occupied_size))
	{
		lab_map.insert(make_pair(lab_id, make_pair(lab_max_size, lab_occupied_size)));
	}

	while (stu_appointment_file.get(date, time, id, name, lab__id, appointment_status))
	{
		appointment_vec.push_back({ date, time, id, name, lab__id, appointment_status });
	}
}

static void start()
{
    init();
	while (true)
	{
		cout << "学生机房管理系统\n请选择登录身份：\n\n"
			<< "1.学生\n"
			<< "2.老师\n"
			<< "3.管理员\n"
			<< "4.退出\n" << endl;

		int input;
		cin >> input;

		//如果获取失败（格式不正确），清除缓冲区，避免死循环
		if (cin.fail())
		{
			//清除错误状态
			cin.clear();
			//循环忽略非EOF字符
			cin.ignore();
			system("cls");
		}

		switch (input)
		{
		case 1:
			stu_login();
			break;
		case 2:
			teacher_login();
			break;
		case 3:
			admin_login();
			break;
		case 4:
			cout << "\n已退出，欢迎下次使用！" << endl;
			system("pause");
			return;
		default:
			break;
		}
	}
}
