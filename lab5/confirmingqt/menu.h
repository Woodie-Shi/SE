#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <vector>
using namespace std;

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
private:
    Ui::menu *ui;
    size_t equal_index = 0;
    size_t inequal_index = 0;
    bool change = 0;    //if the other side confirmed

public slots:
    void display(int kind, vector<pair<string, string>> &vec);
    void yes();
    void no();
    void fin();
signals:
    void next_equal(int kind, vector<pair<string, string>> &vec);
    void next_inequal(int kind, vector<pair<string, string>> &vec);
    void finished();
};

#endif // MENU_H
