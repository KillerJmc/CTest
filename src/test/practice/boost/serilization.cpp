#include <iostream>
#include <sstream>
#include <format>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using std::cout, std::endl;

namespace boost_test
{
	namespace serialization
	{
		class Student
		{
		private:
			long _id;
			std::string _name;

		public:
			Student() {}
			Student(long id, std::string name) : _id(id), _name(name) {}
			auto to_string() -> std::string
			{
				return std::format("Student(id = {}, name = {})", _id, _name);
			}

		private:
			// 为boost提供对private变量的访问权限
			friend class boost::serialization::access;

			// 序列化/反序列化方法
			// 该方法会在序列化/反序列化的时候被自动调用
			template<class Archive>
			void serialize(Archive& ar, const unsigned int version)
			{
				// 这里的ar在序列化时会被填充成输入模式的对象
				// 在反序列化时会被填充成输出模式的对象
				ar& _id;
				ar& _name;
			}

		};

		// 序列化函数
		template <class T>
		auto serialize(T t) -> std::string
		{
			std::stringstream sstream;
			// 类似于ObjcetOutputStream
			boost::archive::text_oarchive out(sstream);
			out << t;
			return sstream.str();
		}

		// 反序列化函数
		template <class T>
		T deserialize(std::string serialized_str)
		{
			std::stringstream sstream;
			sstream << serialized_str;

			// 类似于ObjcetInputStream
			boost::archive::text_iarchive in(sstream);
			T t = T();
			in >> t;
			return t;
		}

		void main()
		{
			// 序列化测试
			Student stu(1, "Jmc");
			auto serialized_str = serialize(stu);
			cout << "serialize string: [" << serialized_str << "]" << endl;

			// 反序列化测试
			Student new_stu = deserialize<Student>(serialized_str);
			cout << new_stu.to_string() << endl;
		}
	}
}