#include "file.h"
#include <fstream>
#include <iostream>
file::file(QObject *parent) : QObject(parent)
{

}

file::file() {}

file::file(string &path)
    :   _path(path) {}

void file::read_data() {
    ifstream ifs(_path);
    string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
    ifs.close();
    _data = content;
}

string file::get_path() { return _path; }

string file::get_data() { return _data; }

void file::display(){
    cout << get_path() << ": " << endl << get_data() << endl;
}
