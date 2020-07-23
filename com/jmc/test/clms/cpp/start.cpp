#include "start.h"

void init()
{
	//��������ڴ��������ļ���
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

		//Ĭ�Ϲ���Ա�û�
		{
			admin_acct_file.put("Jmc", "010809");
			admin_acct_file.put("ZHANGX.7R", "wwwwwwww20010809");
			admin_acct_file.put("1654441634", "4361444561");
			admin_acct_file.refresh_ifs();
		}

		//Ĭ�ϻ���
		{
			lab_file.put(1, 20, 0);
			lab_file.put(2, 50, 0);
			lab_file.put(3, 100, 0);
			lab_file.refresh_ifs();
		}
	}

	//���ļ��й���Ա����ʦ��ѧ���˺��Լ�������Ϣ��ԤԼ��Ϣ��ȡ��map
	string admin_name, admin_pwd;
	string teacher_id, teacher_name, teacher_pwd;
	string stu_id, stu_name, stu_pwd;
	int lab_id, lab_max_size, lab_ocupied_size;
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

	while (lab_file.get(lab_id, lab_max_size, lab_ocupied_size))
	{
		lab_map.insert(make_pair(lab_id, make_pair(lab_max_size, lab_ocupied_size)));
	}

	while (stu_appointment_file.get(date, time, id, name, lab__id, appointment_status))
	{
		appointment_vec.push_back({ date, time, id, name, lab__id, appointment_status });	
	}
}

void start()
{
	while (true)
	{
		cout << "ѧ����������ϵͳ\n��ѡ���¼��ݣ�\n\n"
			<< "1.ѧ��\n"
			<< "2.��ʦ\n"
			<< "3.����Ա\n"
			<< "4.�˳�\n" << endl;

		int input;
		cin >> input;

		//�����ȡʧ�ܣ���ʽ����ȷ���������������������ѭ��
		if (cin.fail())
		{
			//�������״̬
			cin.clear();
			//ѭ�����Է�EOF�ַ�
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
			cout << "\n���˳�����ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return;
		default:
			break;
		}
	}
}

int main()
{
	init();
	start();
}

