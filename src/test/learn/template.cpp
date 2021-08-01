#include <iostream>
#include <tools>

using namespace std;

template<class T>
void fun()
{
    cout << "fun()..." << endl;
}

template<class T>
void add(T a, T b)
{
    cout << a + b << endl;
}

template<class T>
void out_sth_endl(T a)
{
    cout << "函数模板" << endl;
}

void out_sth_endl(int a)
{
    cout << "普通函数" << endl;
}

class Person 
{
    public:
        int id;
};

template<class T>
bool equals(T& a, T& b)
{
    return a == b;
}

//提供具体化的模板，会优先调用
template<> bool equals(Person& p1, Person& p2)
{
    return p1.id == p2.id;
}

void template_main()
{ 
    //这种情况必须指定类型
    fun<int>();
    
    int a = 3;
    char c = 'c';
    //自动类型推导不
    //发生隐式类型转换。
    //add(a, c);
    
    //显示指定类型
    //会发生隐式类型转换
    add<int>(a, c);
    
    int i = 3;
    //普通函数可以实现时
    //优先调用普通函数
    out_sth_endl(i);
    //强制使用函数模板：
    //通过空模板参数列表
    //<>(i);
    
    //不用发生类型转换，优先调
    //函数模板
    c = 'c';
    out_sth_endl(c);
    
    //最好不要同时写同名普通函数和函数模板！
    
    Person p1 = {10};
    Person p2 = {20};
    Person p3 = {10};
    //无需重载"==">运算符
    cout << equals(p1, p2) << endl;
    cout << equals(p1, p3) << endl;
    
}
