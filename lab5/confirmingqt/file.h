#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <string>
using namespace std;

class file : public QObject
{
    Q_OBJECT

private:
    string _path;
    string _data;

public:
    explicit file(QObject *parent = nullptr);
    file();
    explicit file(string &path);
    void read_data();
    string get_path();
    string get_data();
    void display();

signals:

};

#endif // FILE_H
