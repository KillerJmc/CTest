#include <iostream>
#include <fstream>
#include <test/tools.h>

using namespace std;

void file_main()
{
    
    ofstream ofs;
    //默认打开即变为空
    //用ios::app才是添加模式
    ofs.open("/sdcard/ok", ios::out);
    ofs << "Hello World!" << endl;
    ofs.close();
    

    ifstream ifs;
    ifs.open("/sdcard/ok", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl;
        return;
    }
    
    //判断文件是否为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空！" << endl;
        exit(666);
    }
    ifs.seekg(0, ios::beg);
      
    //读取
    //1(按行)
    /*char buf1[1024];
    while (ifs >> buf1)
    {
        cout << buf1 << endl;
        cout << "换行！" << endl;
    }*/
    
    //2(按行)
    /*char buf2[1024];
    while (ifs.getline(buf2, sizeof(buf2)))
    {
        cout << buf2 << endl;
        cout << "换行！" << endl;
    }*/
    
    //3(按行)
    /*string buf;
    while (getline(ifs, buf)) 
    {
        cout << buf << endl;
        cout << "换行！" << endl;
    }*/
    
    //研究指针情况
    /*char c;
    for (int i = 0; i < 15; i++)
    {
        //打印当前读写位置
        cout << ifs.tellg();
        //读了再移位，第0位有读到
        ifs >> c;
        cout << '\t' << c << endl;
    }*/
    
    //读为变量
    string s;
    while (true)
    {
        ifs >> s;
        if (ifs.eof()) break;
        cout << s << '\t';
    }
        
    ifs.close();
}
