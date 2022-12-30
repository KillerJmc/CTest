#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace clms {
    class my_file
    {
        public:
            my_file(string path);
            ~my_file();
            string get_path();
            bool is_open();
            void create();
            template<class Var, class... Vs>
            void put(Var v, Vs... vs);
            template<class Var, class... Vs>
            bool get(Var& v, Vs&... vs);
            void refresh_ifs();
            void clear();
            bool del();
        
        private:
            string _path;
            ifstream _in;
            stringstream _ss;

        public:
            friend ostream &operator<<(ostream &out, my_file& f);
            my_file& operator<<(string content);
            my_file& operator<<(const char * content);
            template<class T>
            my_file& operator<<(T content);
            bool operator>>(string & content);
        
        private:
            void put();
            bool get();
    };

    template<class Var, class... Vs>
    void my_file::put(Var v, Vs... vs)
    {
        _ss << v << " ";
        put(vs...);
    }

    template<class Var, class... Vs>
    bool my_file::get(Var& v, Vs&... vs)
    {
        if (!(_in >> v))
        {
            refresh_ifs();
            return false;
        }

        return get(vs...);
    }

    template<class T>
    my_file& my_file::operator<<(T content)
    {
        *this << to_string(content);
        return *this;
    }

    string read(string path);
    bool out(string path, string content, bool append);
    bool copy(string src_path, string des_path);
    ostream & operator<<(ostream &out, my_file & f);
}

