#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class file
{
    public:
        file(string path);
        ~file();
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
        friend ostream &operator<<(ostream &out, file& f);
        file& operator<<(string content);
        file& operator<<(const char * content);
        template<class T>
        file& operator<<(T content);
        bool operator>>(string & content);
        
    private:
        void put();
        bool get();
};

template<class Var, class... Vs>
void file::put(Var v, Vs... vs)
{
    _ss << v << " ";
    put(vs...);
}

template<class Var, class... Vs>
bool file::get(Var& v, Vs&... vs)
{
    if (!(_in >> v))
    {
        refresh_ifs();
        return false;
    }

    return get(vs...);
}

template<class T>
file& file::operator<<(T content)
{
    *this << to_string(content);
    return *this;
}

string read(string path);
bool out(string path, string content, bool append);
bool copy(string src_path, string des_path);
ostream & operator<<(ostream &out, file & f);

