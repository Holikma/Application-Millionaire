#include "Qt_APP.h"
#include <iostream>
#include "Player.h"
#include "Question.h"


using namespace std;

Qt_APP::Qt_APP(QWidget *parent) : QMainWindow(parent){
    ui.setupUi(this);
    //connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

Qt_APP::~Qt_APP(){
}

void Qt_APP::Name_Input() {
    QLineEdit* nameLineEdit = findChild<QLineEdit*>("Name_Line");
    QString text = nameLineEdit->text();
    qDebug() << text;
}

