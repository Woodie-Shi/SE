#include "initial.h"
#include "ui_initial.h"
#include "result.h"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>

extern vector<pair<string, string>> equals;
extern vector<pair<string, string>> inequals;
extern result* r;

initial::initial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::initial)
{
    ui->setupUi(this);
    setFixedSize(306, 338);
    my_menu = new menu();
    connect(ui->closeBtn, &QPushButton::clicked, this, &initial::close);
    connect(ui->equalBtn, &QPushButton::clicked, this, &initial::click_equal);
    connect(ui->inequalBtn, &QPushButton::clicked, this, &initial::click_inequal);
    connect(this, &initial::show_code, my_menu, &menu::display);
    connect(my_menu, &menu::finished, this, &initial::save_result);
}

initial::~initial()
{
    delete ui;
}

void initial::init(vector<pair<string, string>> &ve, vector<pair<string, string>> &vine){
    ifstream equ("./output/equal.csv");
    ifstream inequ("./output/inequal.csv");
    string str;
    equ >> str;
    inequ >> str;
    regex r("(.+),(.+)");
    smatch m1, m2;
    bool f1, f2;

    while(!equ.eof()){
        equ >> str;
        f1 = regex_match(str, m1, r);
        if(f1){
            ve.push_back(make_pair(m1.str(1), m1.str(2)));
        }
        else cout << "Not match." << endl;
    }
    while(!inequ.eof()){
        inequ >> str;
        f2 = regex_match(str, m2, r);
        if(f2){
            vine.push_back(make_pair(m2.str(1), m2.str(2)));
        }
        else cout << "Not match." << endl;
    }
}

void initial::click_equal(){
    this->hide();
    emit this->show_code(1, equals);
}

void initial::click_inequal(){
    this->hide();
    emit this->show_code(2, inequals);
}

void initial::save_result(){
    r->save();
    this->show();
    this->close();
}
