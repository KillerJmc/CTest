#include <iostream>
#include "tools.h"

using namespace std;

class Exception
{
    private:
        string m_msg;
    public:
        Exception(string msg): m_msg(msg) {}
        void printStackTrace() 
        {
            cout << m_msg << endl;
        }
};

class T {
    public:
        T()
        {
            cout << "T被创建!" << endl;
        }
    
        ~T() 
        {
            cout << "T被销毁!" << endl;
        }
};

void exception2_main()
{
    try 
    {
        //发生异常自动析构！
        T t;
        cout << "报出异常！" << endl;
        throw Exception("已发生异常！");
        cout << "ttt";
    } 
    catch (Exception e)
    {
        e.printStackTrace();
    }
    cout << "main..." << endl;
    
}






