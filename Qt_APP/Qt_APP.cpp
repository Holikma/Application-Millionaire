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

QString Qt_APP::Level_Input() {
    QComboBox* Level_Box = findChild<QComboBox*>("Level_Box");
    QString text = Level_Box->currentText();
    return text;
}

void Qt_APP::freeze() {
	ui.New_Game_Button->setEnabled(false);
    findChild<QLineEdit*>("Name_Line")->setReadOnly(true);
    findChild<QComboBox*>("Level_Box")->setEnabled(false);
}

void Qt_APP::Set_Game() {
    Player player1;
    Question question1;
    freeze();
    player1.setName(Name_Input());
    player1.setLevel(Level_Input());
    question1.loadQuestions();
    
    
}

