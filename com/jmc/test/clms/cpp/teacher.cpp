#include "teacher.h"

void teacher_login()
{
	system("cls");

	cout << "��ʦ��¼\n"
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

	if (teacher_map.count(teacher_id) == 1)
	{
		if (teacher_map[teacher_id].first == teacher_name && teacher_map[teacher_id].second == teacher_pwd)
		{
			cout << "\n��¼�ɹ���" << endl;
			system("pause");
			teacher_function();
		}
		else
		{
			cout << "\n������������������" << endl;
		}
	}
	else
	{
		cout << "\nְ���Ų����ڣ�" << endl;
	}

	system("pause");
	system("cls");
}

void teacher_function()
{
	while (true)
	{
		system("cls");
		cout << "��ݣ���ʦ\n��ѡ�����¹���\n\n"
			<< "1.�鿴����ԤԼ\n"
			<< "2.���ԤԼ\n"
			<< "3.ע����¼\n"
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
	cout << "����ԤԼ��Ϣ���£�" << endl;
	cout << "\n����\t\tʱ��\t\tѧ��\t\tѧ������\t\t������\t\tԤԼ״̬" << endl;
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
		if (e.appointment_status == "�����") reviewing_vec.push_back(e);
	}

	cout << "����˵�ԤԼ��¼���£�" << endl;
	cout << "\n���\t\t����\t\tʱ��\t\tѧ��\t\tѧ������\t\t������\t\tԤԼ״̬" << endl;
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
	cout << "\n�밴���������˵�ԤԼ��¼��0��ʾ���أ�" << endl;
	size_t idx;
	while (true)
	{
		cin >> idx;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "�����������������롣" << endl;
			system("pause");
			continue;
		}

		if (idx < 0 || idx > reviewing_vec.size())
		{
			cout << "�����������������롣" << endl;
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
		cout << "\n������ѡ�������ڵı��\n"
			 << "1.ͨ��\n"
			 << "2.��ͨ��"
			 << endl;

		int choice;
		while (true)
		{
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "�����������������롣" << endl;
				system("pause");
				continue;
			}

			if (idx < 1 || idx > 2)
			{
				cout << "�����������������롣" << endl;
				system("pause");
				continue;
			}
			break;
		}

		for (auto& e : appointment_vec)
		{
			if (e == reviewing_vec[idx - 1])
			{
				if (e.appointment_status == "�����")
				{
					e.appointment_status = idx == 1 ? "ԤԼ�ɹ�" : "ԤԼʧ��";
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

		cout << "\n������" << endl;
		system("pause");
	}
	
}
