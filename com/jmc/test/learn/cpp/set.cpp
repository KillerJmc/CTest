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

void set_test01()
{ 
    //set�����򲻿��ظ�
    set<int> s;
    for (int i = 10; i <= 50; i += 10)
    {
        s.insert(i);
        s.insert(i - 3);
        s.insert(i + 1);
    }
        
    print_a(s);
    
    set<int>::iterator it = s.find(10);
    if (it != s.end()) 
        cout << "�ҵ�Ԫ��" << endl;
        
    int count = s.count(10);
    cout << count << endl;
    
    //multiset�������ظ�Ԫ��
    multiset<int> ms;
    for (int i = 0; i < 5; i++) ms.insert(10);
    cout << ms.count(10) << endl;
    print_a(ms);
}

void set_test02()
{
    set<int> s;
    for (int i = 10; i <= 50; i += 10) s.insert(i);
    print_a(s);
    
    set<int, Comparator> s2;
    for (int i = 10; i <= 50; i += 10) s2.insert(i);
    print_a(s2);
}

void set_main()
{
    set_test02();
}






