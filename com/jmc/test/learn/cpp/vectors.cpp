#include <iostream>
#include <vector>
#include <algorithm>
#include "tools.h"

using namespace std;

void print(int i)
{
    cout << i << endl;
}

void vectors_test01()
{
    vector<int> v = {3, 1, 2};
    v.push_back(7);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    
    cout << "-----------------------------------------------";
    
    vector<int> v2 (10, 8848);
    print_a(v2);

    cout << "-----------------------------------------------";

    vector<int>::iterator it;
    //������v.end()ָ�����һ��Ԫ��
    //+1��λ�ã��Ǹ��ط���Ԫ�أ�
    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
 
    cout << "-----------------------------------------------";

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    //��for_each����
    for_each(v.begin(), v.end(), print);

    cout << "-----------------------------------------------";
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.empty() << endl;
    v.clear();
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.empty() << endl;
    cout << "-----------------------------------------------";
}

void vectors_test02()
{
    vector<int> v;
    cout << v.capacity() << endl;
    v.resize(5);
    cout << v.capacity() << endl;
    print_a(v);
    v.resize(10, 8848);
    print_a(v);
    cout << "-----------------------------------------------";
}

void vectors_test03()
{
    vector<int> v = {1, 2, 3, 4, 5};
    v.insert(v.begin(), 10);
    print_a(v);
    v.insert(v.begin(), 2, 8848);
    print_a(v);
    v.erase(v.begin() + 2);
    print_a(v);
    v.erase(v.begin(), v.begin() + 2);
    print_a(v);
    cout << "-----------------------------------------------";
}

void vectors_test04()
{
    vector<int> v;
    for (int i = 0; i < 10000; i++) 
        v.push_back(i + 1);
    out_sth_endl(v.size(), v.capacity());
    v.resize(3);
    out_sth_endl(v.size(), v.capacity());
    
    //������������꼴������
    //��ʼ������ֻ�����õĲ���
    //Ȼ����ԭ����ָ��ָ�򻥻�
    vector<int>(v).swap(v);
    out_sth_endl(v.size(), v.capacity());
    cout << "-----------------------------------------------";
}

void vectors_test05()
{
    vector<int> v;
    int num = 0;
    int * addr = nullptr;
    for (int i = 0; i < 100000; ++i)
    {
        v.push_back(i);
        if (addr != &v[0])
        {
            addr = &v[0];
            num++;
        }
    }
    
    vector<int> v2;
    //Ԥ���ռ䣬���ٶ�̬��չ
    v2.reserve(100000);
    int num2 = 0;
    int * addr2 = nullptr;
    for (int i = 0; i < 100000; ++i)
    {
        v2.push_back(i);
        if (addr2 != &v2[0])
        {
            addr2 = &v2[0];
            num2++;
        }
    }
    
    out_sth_endl(num, num2);
    cout << "-----------------------------------------------";
        
}

void vectors_main()
{
    vectors_test01();
    vectors_test02();
    vectors_test03();
    vectors_test04();
    vectors_test05();
}
