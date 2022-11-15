#include "output.h"
#include<fstream>
bool output::save(folder& fd, sets& sts){
    string outpath = "./output";
    ofstream e(outpath + "/equal.csv", ios::app);
    ofstream ne(outpath + "/inequal.csv", ios::app);
    string aname, bname;
    int n = fd.get_num();
    string prefix = "input/";
    prefix += fd.get_name();
    prefix += "/";
    for(int i = 0;i < n - 1;i++){
        aname = fd.get_file(i)->get_name();
        for(int j = i + 1;j < n;j++){
            bname = fd.get_file(j)->get_name();
            if(sts.find(i, j)){
                e << prefix << aname << "," << prefix << bname <<endl;
            }
            else{
                ne << prefix << aname << "," << prefix << bname <<endl;
            }
        }
    }
    e.close();
    ne.close();
}