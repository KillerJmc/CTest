#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <thread>

using namespace std;

class CollectCmds
{
public:
    void inMsgRecvQueue();
    void outMsgRecvQueue();

private:
    list<int> msgRecvQueue;
};