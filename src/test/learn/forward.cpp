#include <iostream>
#include <algorithm>
#include <jmc-all>

using std::cout;
using std::endl;

namespace _forward
{

	const char* judge(int& i)
	{
		return "��ֵ";
	}

	const char* judge(int&& i)
	{
		return "��ֵ";
	}

	void m(int& i)
	{
		cout << "-----------m-----------" << endl;
		cout << "����ı���Ϊ��ֵ" << endl;
		cout << "�������������Ϊ" << judge(i) << endl;
		cout << "-----------m-----------\n" << endl;
	}

	void m(int&& i)
	{
		cout << "-----------m-----------" << endl;
		cout << "����ı���Ϊ��ֵ" << endl;
		cout << "�������������Ϊ" << judge(i) << endl;
		cout << "-----------m-----------\n" << endl;
	}

	template <typename T>
	void transfer(T&& t)
	{
		cout << "--------transfer--------" << endl;
		cout << "�������������Ϊ" << judge(t) << endl;
		cout << "ӦתΪ��ȷ��T���Ͳ���ת��" << endl;
		cout << "--------transfer--------\n" << endl;
		// ������ǿ��ת��Ϊ��ȷ��T����
		m(std::forward<T>(t));
	}

	void main()
	{
		// ��ֵ
		cout << "m(33)" << endl;
		m(33);
		cout << "transfer(33)" << endl;
		transfer(33);

		int i = 666;
		// ��ֵ
		cout << "m(i)" << endl;
		m(i);
		cout << "transfer(i)" << endl;
		transfer(i);
	}
}
