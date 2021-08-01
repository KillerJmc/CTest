#include <iostream>
#include <set>
#include <tools>

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
    //set：有序不可重复
    set<int> s;
    for (int i = 10; i <= 50; i += 10)
    {
        s.insert(i);
        s.insert(i - 3);
        s.insert(i + 1);
    }
        
    tools::print_stl(s);
    
    set<int>::iterator it = s.find(10);
    if (it != s.end()) 
        cout << "找到元素" << endl;
        
    int count = s.count(10);
    cout << count << endl;
    
    //multiset可以有重复元素
    multiset<int> ms;
    for (int i = 0; i < 5; i++) ms.insert(10);
    cout << ms.count(10) << endl;
    tools::print_stl(ms);
}

void set_test02()
{
    set<int> s;
    for (int i = 10; i <= 50; i += 10) s.insert(i);
    tools::print_stl(s);
    
    set<int, Comparator> s2;
    for (int i = 10; i <= 50; i += 10) s2.insert(i);
    tools::print_stl(s2);
}

void set_main()
{
    set_test02();
}






