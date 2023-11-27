#include "Qt_APP.h"
#include <iostream>


using namespace std;

Qt_APP::Qt_APP(QWidget *parent) : QMainWindow(parent){
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

Qt_APP::~Qt_APP(){
}



