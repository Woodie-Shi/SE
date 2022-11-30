#ifndef RESULT_H
#define RESULT_H

#include <QObject>
#include <vector>
#include <string>
using namespace std;

class result : public QObject
{
    Q_OBJECT
public:
    explicit result(QObject *parent = nullptr);
    void add_equ(pair<string, string> &p);
    void add_inequ(pair<string, string> &p);
    void save();

private:
    vector<pair<string, string>> equivalence;
    vector<pair<string, string>> inequivalence;

};

#endif // RESULT_H
