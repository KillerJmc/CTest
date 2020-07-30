#include <iostream>
#include "../main/tools.h"

using namespace std;

void my_print()
{
    cout << "thread" << endl;
    cout << "haha" << endl;
}

void thread_main()
{
    //创建并立即执行
    //如果传的是对象，就会复制一份
    //对象，主线程销毁，复制品还在
    thread t(my_print);
    
    //阻塞等待(传统做法)
    if (t.joinable()) t.join();
    
    /* 当使用detach()函数时，主调线程继续运行，被调线程驻留后台运行，主调线程无法再取得该被调线程的控制权。当主调线程结束时，由运行时库负责清理与被调线程相关的资源。*/
    //但是main结束，进程就结束
    //无法在屏幕上打印信息
    //不推荐使用
    //t.detach();
    
    
    thread([] {out_sth_endl("NB", "Class");}).join();
    cout << "Hello World!" << endl;
}

