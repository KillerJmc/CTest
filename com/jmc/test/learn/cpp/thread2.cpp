#include <iostream>
#include "tools.h"

using namespace std;

class AA
{
    public:
        mutable int _i;
        
        AA(int i) : _i(i)
        {
            cout << "构造函数执行！" << "thread_id：" << this_thread::get_id() << endl;
        }
        AA(const AA& a)
        {
            _i = a._i;
            cout << "拷贝构造函数执行！" << "thread_id：" << this_thread::get_id() << endl;
        }
        ~AA()
        {
            _i = 0;
            cout << "析构函数执行！" << "thread_id：" << this_thread::get_id() << endl;
        }
        
        void work(int p)
        {
            cout << "-----------------------------------------------";
            cout << "work：p = " << p << endl;
            cout << "-----------------------------------------------";
        }
};

void safe(int i, const AA& a)
{
    cout << "save：" << "thread_id：" << this_thread::get_id() << endl;
}

void thread2_main()
{
    cout << "main：" << "thread_id：" << this_thread::get_id() << endl;
    
    int i = 0;
    int p = 3;
    AA a(i);
    thread(&AA::work, &a, p).detach();
}