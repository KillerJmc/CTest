#include "stu.h"

void stu_login()
{
	system("cls");

	cout << "ѧ����¼\n"
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
	
	if (stu_map.count(stu_id) == 1)
	{
		if (stu_map[stu_id].first == stu_name && stu_map[stu_id].second == stu_pwd)
		{
			cout << "\n��¼�ɹ���" << endl;
			system("pause");
			stu_function(stu_id, stu_name);
		}
		else
		{
			cout << "\n������������������" << endl;
		}
	}
	else
	{
		cout << "\nѧ�Ų����ڣ�" << endl;
	}

	system("pause");
	system("cls");

}

void stu_function(string& stu_id, string& stu_name)
{
	while (true)
	{
		system("cls");
		cout << "��ݣ�ѧ��\n��ѡ�����¹���\n\n"
			<< "1.����ԤԼ\n"
			<< "2.�鿴����ԤԼ״̬\n"
			<< "3.�鿴����ԤԼ\n"
			<< "4.ȡ��ԤԼ\n"
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
		if (e.id == stu_id && e.appointment_status == "�����")
		{
			cout << "�Ѵ���ԤԼ������ȡ��ԤԼ�������˽����������" << endl;
			system("pause");
			return;
		}
	}

	cout << "������ԤԼ��ʱ�䣺\n"
	 	 << "1.��һ\n"
		 << "2.�ܶ�\n"
		 << "3.����\n"
		 << "4.����\n"
		 << "5.����\n"
		 << endl;

	size_t choice;
	cin >> choice;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "��������������ԤԼ��" << endl;
		system("pause");
		return;
	}

	if (choice < 1 || choice > 5)
	{
		cout << "��������������ԤԼ��" << endl;
		system("pause");
		return;
	}

	string date = "����";
	date += choice == 1 ? "һ" :
			choice == 2 ? "��" :
			choice == 3 ? "��" :
			choice == 4 ? "��" : "��";

	cout << "\n������ԤԼ��ʱ�Σ�\n"
		<< "1.����\n"
		<< "2.����\n"
		<< endl;

	cin >> choice;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "��������������ԤԼ��" << endl;
		system("pause");
		return;
	}

	if (choice < 1 || choice > 2)
	{
		cout << "��������������ԤԼ��" << endl;
		system("pause");
		return;
	}

	string time = choice == 1 ? "����" : "����";

	cout << "\n������Ϣ���£�" << endl;
	cout << "\n���\t\t\t�������\t\t��ռ��\n";
	for (auto& e : lab_map)
	{
		cout << e.first << "\t\t\t"
			<< e.second.first << "\t\t\t"
			<< e.second.second
			<< endl;
	}

	cout << "\n�밴���ѡ�������\n";
	cin >> choice;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "��������������ԤԼ��" << endl;
		system("pause");
		return;
	}

	if (choice < 1 || choice > lab_map.size())
	{
		cout << "��������������ԤԼ��" << endl;
		system("pause");
		return;
	}

	if (lab_map[choice].second >= lab_map[choice].first)
	{
		cout << "����������ԤԼʧ�ܡ�" << endl;
		system("pause");
		return;
	}

	string lab_id = to_string(choice);
	string appointment_status = "�����";


	appointment_vec.push_back({ date, time, stu_id, stu_name, lab_id, appointment_status });

	stu_appointment_file.put(date, time, stu_id, stu_name, lab_id, appointment_status);

	cout << "\nԤԼ�ɹ��������" << endl;

	system("pause");
}

void check_self_appointment_status(string& stu_name)
{
	system("cls");
	cout << "��������ԤԼ��Ϣ���£�" << endl;
	cout << "\n����\t\t\tʱ��\t\t\t������\t\t\tԤԼ״̬" << endl;
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

void cancel_self_appointment(string& stu_name)
{
	system("cls");
	cout << "���п�ȡ����ԤԼ��Ϣ���£�\n"
		 << "ע��ֻ������к�ԤԼ�ɹ��Ĳ���ȡ��"
		 << endl;
	cout << "\n���\t\t����\t\tʱ��\t\t������\t\tԤԼ״̬" << endl;
	vector<AppointmentSingleLineRecord> cancel_vec;
	
	for (auto& e : appointment_vec)
		if (e.name == stu_name)
			if (e.appointment_status == "�����" || e.appointment_status == "ԤԼ�ɹ�")
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

	cout << "\n�밴�������Ҫȡ����ԤԼ��¼��0��ʾ���أ�" << endl;
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

		if (idx < 0 || idx > cancel_vec.size())
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
		cout << "\n�Ƿ�ȡ����\n"
			<< "1.��\n"
			<< "2.��"
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

		if (choice == 2)
		{
			cout << "\nȡ��ԤԼʧ�ܡ�" << endl;
			system("pause");
			return;
		} 
		else
		{
			for (auto& e : appointment_vec)
			{
				if (e == cancel_vec[idx - 1])
				{
					if (e.appointment_status == "ԤԼ�ɹ�")
					{
						int lab_id = stoi(e.lab_id);
						lab_map[lab_id].second--;

						lab_file.clear();
						for (auto& e : lab_map)
						{
							lab_file.put(e.first, e.second.first, e.second.second);
						}
					}
					e.appointment_status = "��ȡ��ԤԼ";
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

		cout << "\nȡ���ɹ�" << endl;
		system("pause");
	}


}


