#include "data_structure.h"
#include<fstream>
#include <filesystem>

// class file----------------------------------------------------------------------------------------------
file::file() {}
file::file(string path, string name)
    :   _path(path)
    , _name(name) {}

void file::read_data(){
    ifstream ifs(_path + "/" + _name);
    string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
    ifs.close();
    _data = content;
}

string file::get_path() { return _path; }
string file::get_name() { return _name; }
string file::get_data() { return _data; }

//class folder---------------------------------------------------------------------------------------------
folder::folder() {}
folder::folder(string path, string name)
    :   _path(path)
    ,   _name(name) {}

void folder::read_file_name(){
    _file_num = 0;
    string path = _path + "/" + _name;
    for (const auto & entry : filesystem::directory_iterator(path)){
        string str = entry.path().filename().string();
        if(str == "stdin_format.txt") continue;
        _file_name.push_back(str);
        ++_file_num;
        file *f = new file(path, str);
        f->read_data();
        _files.push_back(*f);
        delete f;
    }
}

string folder::get_path() { return _path; }
int folder::get_num() { return _file_num; }
string folder::get_file_name(int no) { return _files[no].get_name(); }

file* folder::get_file(int no){
    return &_files[no];
}

//class sets-----------------------------------------------------------------------------------------------
void sets::resize(int n){
    _Sets.resize(n);
}

void sets::add_to(int no_1, int no_2){
    for (auto it = _Sets[no_1]._set.begin(); it != _Sets[no_1]._set.end(); it++) {
        if(no_2 != *it) _Sets[no_2]._set.insert(*it);
    }
    for (auto it = _Sets[no_2]._set.begin(); it != _Sets[no_2]._set.end(); it++) {
        if(no_1 != *it) _Sets[no_1]._set.insert(*it);
    }
    _Sets[no_1]._set.insert(no_2);
    _Sets[no_2]._set.insert(no_1);
}

bool sets::find(int no_1, int no_2){
    return (_Sets[no_1]._set.count(no_2) > 0);
}

void sets::display(){
    int num = 0;
    for (auto it = _Sets.begin();it != _Sets.end(); it++, num++) {
        cout << num << ": ";
        for (auto i = (*it)._set.begin(); i != (*it)._set.end(); i++){
            cout << *i << " ";
        }
        cout << endl;
    }
}

//class testcase-------------------------------------------------------------------------------------------
testcase::testcase(string path, string name)
    :   file(path, name);
