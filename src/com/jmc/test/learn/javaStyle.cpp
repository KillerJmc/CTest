#include <iostream>

using namespace std;

struct system {
    struct Out {
        void println(string str) {
            cout << str << endl;
        }
    }; 
    Out out;
};

typedef string String;
struct system System;








class Main {
    public : static void main(String args[]) {
        System.out.println("Hello World!");
    }
};












void javaStyle_main(){}