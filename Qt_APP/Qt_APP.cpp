#include "Qt_APP.h"


Qt_APP::Qt_APP(QWidget *parent) : QMainWindow(parent){
    ui.setupUi(this);
    connect(ui.New_Game_Button, SIGNAL(clicked()), this, SLOT(Set_Game()));
    connect(ui.End_Game_Button, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui.Next_Question_Button, SIGNAL(clicked()), this, SLOT(loop_questions()));
}

Qt_APP::~Qt_APP(){
}

QString Qt_APP::Name_Input() {
    return ui.Name_Line->text();
}

int Qt_APP::Level_Input() {
    QComboBox* Level_Box = findChild<QComboBox*>("Level_Box");
    QString text = Level_Box->currentText();
    if (text == "Easy") {
		return 1;
	}
	else if (text == "Medium") {
        ui.Joker3_Button->setEnabled(false);
		return 2;
	}
	else if (text == "Hard") {
        ui.Joker2_Button->setEnabled(false);
        ui.Joker3_Button->setEnabled(false);
		return 3;
	}
	else {
		return 0;
	}
}

void Qt_APP::freeze() {
	ui.New_Game_Button->setEnabled(false);
    ui.Name_Line->setEnabled(false);
    ui.Level_Box->setEnabled(false);
    ui.Random_Box->setEnabled(false);
}

void Qt_APP::loop_questions() {
    Question q;
    q.loadQuestions();
    current_index++;
    ui.Question_Field->setReadOnly(true);
	ui.Question_Field->setPlainText(q.getQuestion(current_index));
    ui.A_option->setText(q.getAnswer(current_index, 0));
    ui.B_option->setText(q.getAnswer(current_index, 1));
    ui.C_option->setText(q.getAnswer(current_index, 2));
    ui.D_option->setText(q.getAnswer(current_index, 3));

}

void Qt_APP::Set_Game() {
    Player player1;
    player1.setName(Name_Input());
    player1.setDifficulty(Level_Input());
    freeze();
    loop_questions();
}



