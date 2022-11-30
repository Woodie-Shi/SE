#ifndef _PREPROCESS_H
#define _PREPROCESS_H
#include "data_structure.h"

class preprocess{
private:
    string _path;
    string _name;
public:
    preprocess();
    preprocess(string path, string name);
    void display_args();
    folder* init_folder();
    void find_same(folder &fd, sets &sts);
};
#endif