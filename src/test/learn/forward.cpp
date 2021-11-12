#include <iostream>
#include <algorithm>
#include <jmc-all>

using std::cout;
using std::endl;

namespace _forward
{

	const char* judge(int& i)
	{
		return "左值";
	}

	const char* judge(int&& i)
	{
		return "右值";
	}

	void m(int& i)
	{
		cout << "-----------m-----------" << endl;
		cout << "传入的变量为左值" << endl;
		cout << "函数中这个变量为" << judge(i) << endl;
		cout << "-----------m-----------\n" << endl;
	}

	void m(int&& i)
	{
		cout << "-----------m-----------" << endl;
		cout << "传入的变量为右值" << endl;
		cout << "函数中这个变量为" << judge(i) << endl;
		cout << "-----------m-----------\n" << endl;
	}

	template <typename T>
	void transfer(T&& t)
	{
		cout << "--------transfer--------" << endl;
		cout << "函数中这个变量为" << judge(t) << endl;
		cout << "应转为正确的T类型才能转发" << endl;
		cout << "--------transfer--------\n" << endl;
		// 把类型强制转换为正确的T类型
		m(std::forward<T>(t));
	}

	void main()
	{
		// 右值
		cout << "m(33)" << endl;
		m(33);
		cout << "transfer(33)" << endl;
		transfer(33);

		int i = 666;
		// 左值
		cout << "m(i)" << endl;
		m(i);
		cout << "transfer(i)" << endl;
		transfer(i);
	}
}
