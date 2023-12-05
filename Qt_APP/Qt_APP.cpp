#include "Qt_APP.h"


Qt_APP::Qt_APP(QWidget *parent) : QMainWindow(parent){
    ui.setupUi(this);
    connect(ui.New_Game_Button, SIGNAL(clicked()), this, SLOT(Set_Game()));
}

Qt_APP::~Qt_APP(){
}

QString Qt_APP::Name_Input() {
    QLineEdit* nameLineEdit = findChild<QLineEdit*>("Name_Line");
    QString text = nameLineEdit->text();
    return text;
}

void Qt_APP::Set_Game() {
    Player player1;
    Question question1;
    player1.setName(Name_Input());
    question1.loadQuestions();
    
}

