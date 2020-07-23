#include <iostream>
#include "tools.h"

using namespace std;

class Comparator
{
    public:
        bool operator()(int i, int k) const
        {
            return i > k;
        }
};

void map_test01()
{
    //�Զ�����key�����ظ�
    map<string, int> m;
    for (int i = 0; i < 5; i++)
        m.insert(make_pair("Jmc", i + 1));
    print_m(m);
    
    //�Զ�����key���ظ�
    multimap<string, int> m2;
    for (int i = 0; i < 5; i++)
        m2.insert(make_pair("Jmc", i + 1));
    print_m(m2);
   
    //ͨ��keyɾ��
    m2.erase("Jmc");
    print_m(m2);
    
}

void map_test02()
{
    map<int, int, less<int>> m;
    for (int i = 10; i <= 50; i += 10)
        m.insert(make_pair(i / 10, i));
    print_m(m);
    
    //map<int, int, Comparator> m2;
    map<int, int, greater<int>> m2;
    for (int i = 10; i <= 50; i += 10)
        m2.insert(make_pair(i / 10, i));
    print_m(m2);
    
}

void map_test03()
{
    multimap<int, int> m;
    for (int i = 10; i <= 100; i+= 10)
        m.insert(make_pair(i % 3, i));
    print_m(m);
    
    cout << "keyΪ1���У�" << endl;
    int count = m.count(1);
    auto begin = m.find(1);
    auto end = m.find(1);
    for (int i = 0; i < count; ++i) end++;
    m.erase(m.begin(), begin);
    m.erase(end, m.end());
    print_m(m);
    
}

void map_main()
{
    map_test03();
}




