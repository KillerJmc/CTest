#include <my_file.h>

clms::my_file::my_file(string path)
{
    this -> _path = path;
    this -> _in = ifstream(path);
}

clms::my_file::~my_file()
{
    if (_in.is_open()) _in.close();
}

string clms::my_file::get_path()
{
    return this -> _path;
}

bool clms::my_file::is_open()
{
    return _in.is_open();
}

void clms::my_file::create()
{
    *this << "";
}

void clms::my_file::put()
{
    _ss << "\n";
    *this << _ss.str();
    //正确清空
    _ss.str("");
}

bool clms::my_file::get()
{
    return true;
}
        
void clms::my_file::refresh_ifs()
{
    if (_in.is_open()) _in.close();
    this -> _in = ifstream(this -> _path);
}

void clms::my_file::clear()
{
    out(_path, "", false);
}

bool clms::my_file::del()
{
    if (_in.is_open()) _in.close();

    if (remove(_path.c_str()) == 0)
    {
        return true;
    }
    else
    {
        perror("remove");
        return false;
    }
}

clms::my_file& clms::my_file::operator<<(const char * content)
{
    out(_path, content, true);
    return *this;
}

clms::my_file& clms::my_file::operator<<(string content)
{
    out(_path, content, true);
    return *this;
}

bool clms::my_file::operator>>(string & content)
{
    content = read(_path);
    return true;
}

string clms::read(string path)
{
    ifstream in(path, ios::in);
    if (!in.is_open())
    {
        cout << "文件读取失败！" << endl;
        return "";
    }

    stringstream s;
    s << in.rdbuf();
    in.close();
    return s.str();
}

bool clms::out(string path, string content, bool append)
{
    ofstream out = append ? ofstream(path, ios::out | ios::app) : ofstream(path, ios::out);
    if (!out.is_open())
    {
        cout << "文件读取失败！" << endl;
        return false;
    }
    out << content;
    out.close();
    return true;
}

ostream & clms::operator<<(ostream &out, my_file& f)
{
    return out << read(f._path);
}

bool clms::copy(string src_path, string des_path)
{
    string f_name = src_path.substr(src_path.find_last_of("/") + 1);
    des_path += "/" + f_name;
    
    ifstream src(src_path, ios::in | ios::binary);
    ofstream des(des_path, ios::out | ios::binary);
    if (!src.is_open() || !des.is_open())
    {
        cout << "读取文件失败！" << endl;
        return false;
    }
    des << src.rdbuf();
    return true;
}