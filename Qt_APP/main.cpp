#include "Qt_APP.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    
    Qt_APP w;
    w.show();
    return a.exec();
}
