#ifndef NAV_H
#define NAV_H

#include "ui_nav.h"
#include "headers.h"

class Nav : public QWidget {
    Q_OBJECT

public:
    explicit Nav(QWidget *parent = nullptr);
    ~Nav();

signals:
    void buttonClicked(const QString &buttonName); 

private:
    Ui::Nav *ui;  
};

#endif // NAV_H

