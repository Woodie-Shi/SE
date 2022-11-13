#include "data_structure.h"
#include<fstream>
#include <filesystem>
#include<regex>
#include<random>

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
void file::display(){
    cout << get_name() << ": " << endl << get_data() << endl;
}

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
string folder::get_name() { return _name; }
int folder::get_num() { return _file_num; }
string folder::get_file_name(int no) { return _files[no].get_name(); }

file* folder::get_file(int no){
    return &_files[no];
}

void folder::display(){
    for(auto it = _files.begin();it != _files.end();it++){
        it->display();
    }
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
    :   file(path, name) {}

void testcase::read_format(){
    string str = get_data();
    regex r0("(int)\\((-?[0-9]+),(-?[0-9]+)\\)");
    regex r1("(char)");
    regex r2("(string)\\(([0-9]+),([0-9]+)\\)");
    smatch m0, m1, m2;
    bool f0, f1, f2;
    int i = 0;
    string temp;
    while (i < str.length()) {
        if (str[i] != ' ') {
            temp += str[i];
            i++;
        }
        else {
            f0 = regex_match(temp, m0, r0);
            f1 = regex_match(temp, m1, r1);
            f2 = regex_match(temp, m2, r2);
            if (f0) {
                
                _type* temp = new _type(0, stoi(m0.str(2)), stoi(m0.str(3)));
                format.push_back(*temp);
                delete temp;
            }
            else if(f1) {
                _type* temp = new _type(1, 0, 0);
                format.push_back(*temp);
                delete temp;
            }
            else if(f2) {
                _type* temp = new _type(2, stoi(m2.str(2)), stoi(m2.str(3)));
                format.push_back(*temp);
                delete temp;
            }
            else assert(0);
            temp.clear();
            i++;
        }
    }
    
    f0 = regex_match(temp, m0, r0);
    f1 = regex_match(temp, m1, r1);
    f2 = regex_match(temp, m2, r2);
    if (f0) {
        _type* temp = new _type(0, stoi(m0.str(2)), stoi(m0.str(3)));
        format.push_back(*temp);
        delete temp;
    }
    else if(f1) {
         _type* temp = new _type(1, 0, 0);
        format.push_back(*temp);
        delete temp;
    }
    else if(f2) {
        _type* temp = new _type(2, stoi(m2.str(2)), stoi(m2.str(3)));
        format.push_back(*temp);
        delete temp;
    }
    else assert(0);
    temp.clear();
}

int testcase::generate_int(int lower, int upper, mt19937& generator){
    uniform_int_distribution< int > distribute(lower, upper);
    return distribute(generator);
}
char testcase::generate_char(mt19937& generator){
    uniform_int_distribution< int > distribute(65, 122);
    bool success = 0;
    int ran = 0;
    char ch;
    while (!success) {
        ran = distribute(generator);
        if (ran < 91 || ran > 96) {
            ch = ran;
            success = 1;
        }
    }
    return ch;
}
string testcase::generate_str(int lower, int upper, mt19937& generator){
    int len = generate_int(lower, upper, generator);
    string s;
    for (int i = 0; i < len; i++) {
        s += generate_char(generator);
    }
    return s;
}

bool testcase::create(int num){
    string newpath = get_path() + "/testcases";
    bool success = filesystem::create_directory(newpath);
    if(!success){
        cout << "Error to create testcase dir." << endl;
        assert(0);
    }
    for (int fn = 0; fn < num; fn++) {
        random_device os_seed;
        const int seed = os_seed();
        mt19937 generator(seed);
    
        string extra = to_string(fn);
        extra += ".txt";
        ofstream outfile(newpath + "/" + extra);
        for (auto it = format.begin(); it != format.end(); it++) {
            if (it->kind == 0) {
                outfile << generate_int(it->lower, it->upper, generator);
            }
            else if (it->kind == 1) {
                outfile << generate_char(generator);
            }
            else {
                outfile << generate_str(it->lower, it->upper, generator);
            }
            if (it == format.end() - 1) continue;
            outfile << " ";
        }
        outfile.close();
    }
    return true;
}