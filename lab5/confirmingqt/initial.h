#ifndef INITIAL_H
#define INITIAL_H

#include <QDialog>
#include <vector>
#include "menu.h"

using namespace std;

namespace Ui {
class initial;
}

class initial : public QDialog
{
    Q_OBJECT

public:
    explicit initial(QWidget *parent = nullptr);
    ~initial();

    void init(vector<pair<string, string>> &ve, vector<pair<string, string>> &vine);

public slots:
    void click_equal();
    void click_inequal();
    void save_result();
private:
    menu* my_menu;
    Ui::initial *ui;
signals:
    void show_code(int kind, vector<pair<string, string>> &vec);
};

#endif // INITIAL_H
