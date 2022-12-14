#include "menu.h"
#include "ui_menu.h"
#include "file.h"
#include "result.h"
#include<iostream>

extern vector<pair<string, string>> equals;
extern vector<pair<string, string>> inequals;
extern result* r;

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

    connect(ui->isequal, &QPushButton::clicked, this, &menu::yes);
    connect(ui->isinequal, &QPushButton::clicked, this, &menu::no);
    connect(this, &menu::next_equal, this, &menu::display);
    connect(this, &menu::next_inequal, this, &menu::display);
    connect(this, &menu::finished, this, &menu::fin);
}

menu::~menu()
{
    delete ui;
}

void menu::display(int kind, vector<pair<string, string>> &vec){
    this->show();
    size_t n = vec.size();

    if(kind == 1){
        if(equal_index < n){
            string f1_path = "./" + vec[equal_index].first;
            file* f1 = new file(f1_path);
            f1->read_data();
            ui->file1->setFrameShape (QFrame::Box);
            ui->file1->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(139, 176, 205);");
            ui->file1->setWordWrap(true);
            ui->file1->setText(QString::fromStdString(f1->get_data()));

            string f2_path = "./" + vec[equal_index++].second;
            file* f2 = new file(f2_path);
            f2->read_data();
            ui->file2->setFrameShape (QFrame::Box);
            ui->file2->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(139, 176, 205);");
            ui->file2->setWordWrap(true);
            ui->file2->setText(QString::fromStdString(f2->get_data()));

            ui->hint->setAlignment(Qt::AlignHCenter);
            ui->hint->setWordWrap(true);
            ui->hint->setText("等价");

        }
        else{
            if(change == 0){
                change = 1;
                emit this->next_inequal(2, inequals);
            }
            else emit this->finished();
        }
    }
    else if(kind == 2){
        if(inequal_index < n){
            string f11_path = "./" + vec[inequal_index].first;
            file* f1 = new file(f11_path);
            f1->read_data();
            ui->file1->setFrameShape (QFrame::Box);
            ui->file1->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(139, 176, 205);");
            ui->file1->setWordWrap(true);
            ui->file1->setText(QString::fromStdString(f1->get_data()));

            string f22_path = "./" + vec[inequal_index++].second;
            file* f2 = new file(f22_path);
            f2->read_data();
            ui->file2->setFrameShape (QFrame::Box);
            ui->file2->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(139, 176, 205);");
            ui->file2->setWordWrap(true);
            ui->file2->setText(QString::fromStdString(f2->get_data()));

            ui->hint->setAlignment(Qt::AlignHCenter);
            ui->hint->setWordWrap(true);
            ui->hint->setText("不等价");
        }
        else{
            if(change == 0){
                change = 1;
                emit this->next_equal(1, equals);
            }
            else emit this->finished();
        }
    }
}

void menu::yes(){
    if(change == 0){
        if(inequal_index == 0){
            r->add_equ(equals[equal_index - 1]);
            emit this->next_equal(1, equals);
        }
        else if(equal_index == 0){
            r->add_inequ(inequals[inequal_index - 1]);
            emit this->next_inequal(2, inequals);
        }
    }
    else{
        if(equal_index < equals.size()){
            r->add_equ(equals[equal_index - 1]);
            emit this->next_equal(1, equals);
        }
        else if(inequal_index < inequals.size()){
            r->add_inequ(inequals[inequal_index - 1]);
            emit this->next_inequal(2, inequals);
        }
        else emit this->finished();
    }
}

void menu::no(){
    if(change == 0){
        if(inequal_index == 0){
            r->add_inequ(equals[equal_index - 1]);
            emit this->next_equal(1, equals);
        }
        else if(equal_index == 0){
            r->add_equ(inequals[inequal_index - 1]);
            emit this->next_inequal(2, inequals);
        }
    }
    else{
        if(equal_index < equals.size()){
            r->add_inequ(equals[equal_index - 1]);
            emit this->next_equal(1, equals);
        }
        else if(inequal_index < inequals.size()){
            r->add_equ(inequals[inequal_index - 1]);
            emit this->next_inequal(2, inequals);
        }
        else emit this->finished();
    }
}

void menu::fin(){
    this->close();
}
