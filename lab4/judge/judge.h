#ifndef _JUDGE_H
#define _JUDGE_H
#include "data_structure.h"

class judge{
public:
    bool compile(file &f, int num);
    bool execute(folder &fd, int num);
    void compare(folder &fd, sets& sts);
};

#endif