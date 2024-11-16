#ifndef NAV_H
#define NAV_H

#include "ui_nav.h"
#include <QWidget>
#include <QStyle>
#include <QPushButton>

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

