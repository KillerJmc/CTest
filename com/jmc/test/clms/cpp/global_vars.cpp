#include "global_vars.h"

const string DATA_PATH = "test\\CLMSData\\";
const string ACCT_PATH = DATA_PATH + "acct\\";
const string LAB_PATH = DATA_PATH + "lab\\";
const string APPOINTMENT_PATH = DATA_PATH + "appointment\\";

//admin_name, admin_pwd
map<string, string> admin_map;
//teacher_id, teacher_name, teacher_pwd
map<string, pair<string, string>> teacher_map;
//stu_id, stu_name, stu_pwd
map<string, pair<string, string>> stu_map;
//lab_id, lab_max_size, lab_occupied_size
map<int, pair<int, int>> lab_map;

vector<AppointmentSingleLineRecord> appointment_vec;

file admin_acct_file(ACCT_PATH + "admin_acct");
file teacher_acct_file(ACCT_PATH + "teacher_acct");
file stu_acct_file(ACCT_PATH + "stu_acct");
file lab_file(LAB_PATH + "lab_info");
file stu_appointment_file(APPOINTMENT_PATH + "stu_appointment");

bool AppointmentSingleLineRecord::operator==(AppointmentSingleLineRecord& another)
{
	return this->date == another.date
		&& this->time == another.time
		&& this->id == another.id
		&& this->name == another.name
		&& this->lab_id == another.lab_id
		&& this->appointment_status == another.appointment_status;
}
