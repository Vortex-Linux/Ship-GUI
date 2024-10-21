#ifndef NAV_H
#define NAV_H

#include <QWidget>
#include "ui_nav.h"

class Nav : public QWidget {
    Q_OBJECT

public:
    explicit Nav(QWidget *parent = nullptr);
    ~Nav();

private:
    Ui::Nav *ui;  
};

#endif // NAV_H

