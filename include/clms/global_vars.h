#pragma once
#include <iostream>
#include <vector>
#include <map>

#include <clms/my_file.h>

using namespace std;

namespace clms {
	namespace global_vars {
		extern const string DATA_PATH;
		extern const string ACCT_PATH;
		extern const string LAB_PATH;
		extern const string APPOINTMENT_PATH;

		extern map<string, string> admin_map;
		extern map<string, pair<string, string>> teacher_map;
		extern map<string, pair<string, string>> stu_map;
		extern map<int, pair<int, int>> lab_map;

		class AppointmentSingleLineRecord
		{
		public:
			string date, time, id, name, lab_id, appointment_status;
			bool operator==(AppointmentSingleLineRecord& another) const;
		};

		extern vector<AppointmentSingleLineRecord> appointment_vec;

		extern clms::my_file admin_acct_file;
		extern clms::my_file teacher_acct_file;
		extern clms::my_file stu_acct_file;
		extern clms::my_file lab_file;
		extern clms::my_file stu_appointment_file;
	}
}


