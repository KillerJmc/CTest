#include <iostream>
#include "tools.h"

using namespace std;

void my_print()
{
    cout << "thread" << endl;
    cout << "haha" << endl;
}

void thread_main()
{
    //����������ִ��
    //��������Ƕ��󣬾ͻḴ��һ��
    //�������߳����٣�����Ʒ����
    thread t(my_print);
    
    //�����ȴ�(��ͳ����)
    if (t.joinable()) t.join();
    
    /* ��ʹ��detach()����ʱ�������̼߳������У������߳�פ����̨���У������߳��޷���ȡ�øñ����̵߳Ŀ���Ȩ���������߳̽���ʱ��������ʱ�⸺�������뱻���߳���ص���Դ��*/
    //����main���������̾ͽ���
    //�޷�����Ļ�ϴ�ӡ��Ϣ
    //���Ƽ�ʹ��
    //t.detach();
    
    
    thread([] {out_sth_endl("NB", "Class");}).join();
    cout << "Hello World!" << endl;
}

