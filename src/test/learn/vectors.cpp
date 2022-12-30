#include <iostream>
#include <vector>
#include <algorithm>
#include <test/tools.h>

using namespace std;

void my_print(int i)
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
    tools::print_stl(v2);

    cout << "-----------------------------------------------";

    vector<int>::iterator it;
    //迭代器v.end()指向最后一个元素
    //+1的位置（那个地方无元素）
    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
 
    cout << "-----------------------------------------------";

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    //用for_each遍历
    for_each(v.begin(), v.end(), my_print);

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
    tools::print_stl(v);
    v.resize(10, 8848);
    tools::print_stl(v);
    cout << "-----------------------------------------------";
}

void vectors_test03()
{
    vector<int> v = {1, 2, 3, 4, 5};
    v.insert(v.begin(), 10);
    tools::print_stl(v);
    v.insert(v.begin(), 2, 8848);
    tools::print_stl(v);
    v.erase(v.begin() + 2);
    tools::print_stl(v);
    v.erase(v.begin(), v.begin() + 2);
    tools::print_stl(v);
    cout << "-----------------------------------------------";
}

void vectors_test04()
{
    vector<int> v;
    for (int i = 0; i < 10000; i++) 
        v.push_back(i + 1);
    tools::print({v.size(), v.capacity()});
    v.resize(3);
    tools::print({v.size(), v.capacity()});
    
    //匿名对象掉用完即被销毁
    //初始化对象只拷贝用的部分
    //然后与原对象指针指向互换
    vector<int>(v).swap(v);
    tools::print({v.size(), v.capacity()});
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
    //预留空间，减少动态扩展
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
    
    tools::print({num, num2});
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
