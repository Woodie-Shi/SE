#ifndef _DATA_STRUCTURE_H
#define _DATA_STRUCTURE_H
#include<string>
#include<vector>
#include<set>
using namespace std;

class file{
private:
    string _path;
    string _name;
    string _data;
public:
    file();
    file(string path, string name);
    void read_data();
    string get_path();
    string get_name();
    string get_data();
};

class folder{
private:
    string _path;
    string _name;
    int _file_num;
    vector<string> _file_name;
    vector<file> _files;
public:
    folder();
    folder(string path, string name);
    // read all the filename, init class file and add into the vector files at the same time.
    void read_file_name();
    string get_path();
    int get_num();
    string get_file_name(int no);
    file* get_file(int no);
};

class sets{
private:
    class _Set {
    public:
        set<int>_set;
        _Set() {}
    };
public:
    vector<_Set> _Sets;
    sets() {}
    void resize(int n);
    bool find(int no_1, int no_2);
    void add_to(int no_1, int no_2);
    void display();
};

class testcase : public file{
public:
    testcase(string path, string name);
    void read_format();
    bool create(int num);
};

#endif