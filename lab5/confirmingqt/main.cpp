#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <filesystem>
#include <QApplication>
#include"initial.h"
#include "menu.h"
#include "result.h"


using namespace  std;

vector<pair<string, string>> equals;
vector<pair<string, string>> inequals;
result* r = new result;

int main(int argc, char *argv[])
{
    string outpath = "./confirm";
    if(!filesystem::exists(outpath)) filesystem::create_directory(outpath);
    ofstream efile(outpath + "/equal.csv");
    ofstream inefile(outpath + "/inequal.csv");
    efile << "file1" << "," << "file2" << endl;
    inefile << "file1" << "," << "file2" << endl;
    efile.close();
    inefile.close();
    QApplication a(argc, argv);
    initial program;
    program.show();
    program.init(equals, inequals);

    program.exec();
    a.exec();
}
