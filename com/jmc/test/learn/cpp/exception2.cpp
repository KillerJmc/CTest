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
            cout << "T������!" << endl;
        }
    
        ~T() 
        {
            cout << "T������!" << endl;
        }
};

void exception2_main()
{
    try 
    {
        //�����쳣�Զ�������
        T t;
        cout << "�����쳣��" << endl;
        throw Exception("�ѷ����쳣��");
        cout << "ttt";
    } 
    catch (Exception e)
    {
        e.printStackTrace();
    }
    cout << "main..." << endl;
    
}






