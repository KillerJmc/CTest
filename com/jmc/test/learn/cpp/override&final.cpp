#include <iostream>
#include "tools.h"

using namespace std;

class Base 
{
    virtual void ok() {}
};

class A : public Base
{
    //���߱���������Ҫ���صĺ�����
    //������һ���µ��麯��
    virtual void ok() override 
    {
        cout << "A: ok" << endl;
    }
};

class B final
{
    virtual void haha() final {}
};

/* ���ܼ̳���������麯��
class C : public B
{
    virtual void haha() {}
};
*/



void override_and_final_main()
{
    
}
