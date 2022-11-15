#ifndef _DATA_STRUCTURE_H
#define _DATA_STRUCTURE_H
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<assert.h>
#include<random>
using namespace std;

class file{
private:
    string _path;
    string _name;
    string _data;
    bool _same;
public:
    file();
    file(string path, string name);
    void read_data();
    string get_path();
    string get_name();
    string get_data();
    bool get_same();
    void set_same();
    void display();
};

class folder{
private:
    string _path;
    string _name;
    int _file_num;
    vector<string> _file_name;
public:
    vector<file> _files;
    folder();
    folder(string path, string name);
    // read all the filename, init class file and add into the vector files at the same time.
    void read_file();
    string get_path();
    string get_name();
    int get_num();
    string get_file_name(int no);
    file* get_file(int no);
    void display();
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
private:
    class _type{
    public:
        int kind;       // 0->int; 1->char; 2->string
        int lower;
        int upper;
        _type(int t, int l, int u)
            :   kind(t)
            ,   lower(l)
            ,   upper(u) {}
    };
    vector<_type> format;
public:
    testcase(string path, string name);
    void read_format();
    int generate_int(int lower, int upper, mt19937& generator);
    char generate_char(mt19937& generator);
    string generate_str(int lower, int upper, mt19937& generator);
    bool create(int num);
};

#endif