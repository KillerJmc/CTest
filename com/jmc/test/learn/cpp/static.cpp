#include <iostream>
#include "tools.h"

using namespace std;

class A 
{
    public:
        //��̬������������������
        const static int c_i = 8;
        //��ͨ��̬������������������
        static int i;
        static void main(string args[])
        {
            //��̬������ʹ�þ�̬����
            i = 6;
            cout << args[1] << endl;
        }
};

//��ʼ���ྲ̬����
int A::i = 3;

void static_main()
{ 
    cout << A::c_i << endl;
    //����A a; cout << a.i;
    cout << A::i << endl; 
    
    string args[] {"0", "666"};
    //����A a; a.main(args);
    A::main(args);
    cout << A::i;
    
}




