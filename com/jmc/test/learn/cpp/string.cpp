#include <iostream>
#include "tools.h"

using namespace std;

void string_main()
{ 
    string s1(10, 'a');
    cout << s1 << endl;
    
    const char * cs = "Hello C++";
    //��c_stringת��Ϊc++_string
    string s2(cs);
    cout << s2 << endl;
    
    string s3(s2);
    cout << s3 << endl;
    
    string s4;
    s4.assign("Hello C++", 5);
    cout << s4 << endl;
    
    //��10��n��ɵ��ַ���
    s4.assign(10, 'n');
    cout << s4 << endl;
    
    cout << "-----------------------------------------------";
    
    string a = "I";
    //׷��ĳ���ַ���ǰ5���ַ�
    a.append(" lovehahaha", 5);
    //׷��ĳ�ַ����ӵ�4������
    //����5���ַ���
    //��ʼ������4��֮���ַ�
    a.append("haah yousjkk", 4, 4);
    //ֱ��ĩβ׷��
    a.append("!");
    
    cout << a << endl;
    
}
