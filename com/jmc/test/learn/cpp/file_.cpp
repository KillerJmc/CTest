#include <iostream>
#include <fstream>
#include "tools.h"

using namespace std;

void file_main()
{
    
    ofstream ofs;
    //Ĭ�ϴ򿪼���Ϊ��
    //��ios::app�������ģʽ
    ofs.open("/sdcard/ok", ios::out);
    ofs << "Hello World!" << endl;
    ofs.close();
    

    ifstream ifs;
    ifs.open("/sdcard/ok", ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }
    
    //�ж��ļ��Ƿ�Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ�գ�" << endl;
        exit(666);
    }
    ifs.seekg(0, ios::beg);
      
    //��ȡ
    //1(����)
    /*char buf1[1024];
    while (ifs >> buf1)
    {
        cout << buf1 << endl;
        cout << "���У�" << endl;
    }*/
    
    //2(����)
    /*char buf2[1024];
    while (ifs.getline(buf2, sizeof(buf2)))
    {
        cout << buf2 << endl;
        cout << "���У�" << endl;
    }*/
    
    //3(����)
    /*string buf;
    while (getline(ifs, buf)) 
    {
        cout << buf << endl;
        cout << "���У�" << endl;
    }*/
    
    //�о�ָ�����
    /*char c;
    for (int i = 0; i < 15; i++)
    {
        //��ӡ��ǰ��дλ��
        cout << ifs.tellg();
        //��������λ����0λ�ж���
        ifs >> c;
        cout << '\t' << c << endl;
    }*/
    
    //��Ϊ����
    string s;
    while (true)
    {
        ifs >> s;
        if (ifs.eof()) break;
        cout << s << '\t';
    }
        
    ifs.close();
}
