#pragma once
#include <clms/global_vars.h>

namespace clms {
	namespace stu {
		void stu_login();

		void stu_function(string& stu_id, string& stu_name);

		void request_appointment(string& stu_id, string& stu_name);

		void check_self_appointment_status(string& stu_name);

		void view_appointments();

		void cancel_self_appointment(string& stu_name);
	}
	
}
