#include "admin.h"

void admin_login()
{
	system("cls");

	cout << "����Ա��¼\n"
		<< "����������������Ϣ\n"
		<< endl;

	cout << "������";
	string admin_name;
	cin >> admin_name;

	cout << "���룺";
	string admin_pwd;
	cin >> admin_pwd;

	if (admin_map.count(admin_name) == 1)
	{
		if (admin_map[admin_name] == admin_pwd)
		{
			cout << "\n��¼�ɹ���" << endl;
			system("pause");
			admin_function();
		}
		else
		{
			cout << "\n�˺Ż�������������" << endl;
		}
	}
	else
	{
		cout << "\n�˺Ż�������������" << endl;
	}

	system("pause");
	system("cls");


}

void admin_function()
{
	while (true)
	{
		system("cls");
		cout << "��ݣ�����Ա\n��ѡ�����¹���\n\n"
			<< "1.����˺�\n"
			<< "2.�鿴�˺�\n"
			<< "3.�鿴����\n"
			<< "4.���ԤԼ\n"
			<< "5.ע����¼\n"
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
		cout << "��ѡ������˺�����\n\n"
			<< "1.ѧ���˺�\n"
			<< "2.��ʦ�˺�\n"
			<< "3.������һ��\n"
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
					cout << "�˺����\n"
						<< "����������������Ϣ\n"
						<< endl;

					cout << "ѧ�ţ�";
					string stu_id;
					cin >> stu_id;

					cout << "������";
					string stu_name;
					cin >> stu_name;

					cout << "���룺";
					string stu_pwd;
					cin >> stu_pwd;

					if (stu_id[0] == '\0' || stu_name[0] == '\0' || stu_pwd[0] == '\0')
					{
						cout << "\n��ȡʧ�ܣ�����������!" << endl;
						system("pause");
						return;
					}

					if (stu_map.count(stu_id) == 1)
					{
						cout << "\nѧ������Ѵ��ڣ�����������!" << endl;
						system("pause");
					}
					else 
					{
						stu_map.insert(make_pair(stu_id, make_pair(stu_name, stu_pwd)));
						stu_acct_file.put(stu_id, stu_name, stu_pwd);
						cout << "\n��ӳɹ�!" << endl;
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
					cout << "�˺����\n"
						<< "����������������Ϣ\n"
						<< endl;

					cout << "ְ���ţ�";
					string teacher_id;
					cin >> teacher_id;

					cout << "������";
					string teacher_name;
					cin >> teacher_name;

					cout << "���룺";
					string teacher_pwd;
					cin >> teacher_pwd;

					if (teacher_id[0] == '\0' || teacher_name[0] == '\0' || teacher_pwd[0] == '\0')
					{
						cout << "\n��ȡʧ�ܣ�����������!" << endl;
						system("pause");
						return;
					}

					if (teacher_map.count(teacher_id) == 1)
					{
						cout << "\nְ�����Ѵ���,����������!" << endl;
						system("pause");
					}
					else
					{
						teacher_map.insert(make_pair(teacher_id, make_pair(teacher_name, teacher_pwd)));
						teacher_acct_file.put(teacher_id, teacher_name, teacher_pwd);
						cout << "\n��ӳɹ�!" << endl;
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
		cout << "��ѡ��鿴�˺�����\n\n"
			<< "1.ѧ���˺�\n"
			<< "2.��ʦ�˺�\n"
			<< "3.������һ��\n"
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
				cout << "ѧ���˺���Ϣ���£�" << endl;
				cout << "\nѧ��\t\t\t����\t\t\t����" << endl;
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
				cout << "��ʦ�˺���Ϣ���£�" << endl;
				cout << "\nְ����\t\t\t����\t\t\t����" << endl;
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
	cout << "������Ϣ���£�" << endl;
	cout << "\n���\t\t\t�������\t\t��ռ��\n";
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
	cout << "ԤԼ����գ�" << endl;
	system("pause");
}
