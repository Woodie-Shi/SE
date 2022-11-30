#include "result.h"
#include <fstream>

result::result(QObject *parent) : QObject(parent)
{

}

void result::add_equ(pair<string, string> &p){
    if(!equivalence.size()|| p.first != equivalence.back().first || p.second != equivalence.back().second){
        equivalence.push_back(p);
    }
}

void result::add_inequ(pair<string, string> &p){
    if(!inequivalence.size() || p.first != inequivalence.back().first || p.second != inequivalence.back().second){
        inequivalence.push_back(p);
    }
}

void result::save(){
    string outpath = "./confirm";
    ofstream e(outpath + "/equal.csv", ios::app);
    ofstream ne(outpath + "/inequal.csv", ios::app);
    int num_e = equivalence.size(), num_ne = inequivalence.size();
    for(int i = 0;i < num_e;i++){
        e << equivalence[i].first << "," << equivalence[i].second << endl;
    }
    for(int j = 0;j < num_ne;j++){
        ne << inequivalence[j].first << "," << inequivalence[j].second << endl;
    }
    e.close();
    ne.close();
}
