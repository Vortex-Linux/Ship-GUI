#include <QApplication>
#include "../include/nav.h"  

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Nav nav;  
    nav.show();  

    return app.exec();
}

