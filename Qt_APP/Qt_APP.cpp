#include "Qt_APP.h"

Qt_APP::Qt_APP(QWidget *parent) : QMainWindow(parent){
    ui.setupUi(this);
    ui.Score_Field->setText("0");
    ui.Submit_Button->setEnabled(false);
    ui.Next_Question_Button->setEnabled(false);
    ui.A_option->setEnabled(false);
    ui.B_option->setEnabled(false);
    ui.C_option->setEnabled(false);
    ui.D_option->setEnabled(false);
    ui.Question_Field->setReadOnly(true);
    ui.A_option->setAutoExclusive(false);
    ui.B_option->setAutoExclusive(false);
    ui.C_option->setAutoExclusive(false);
    ui.D_option->setAutoExclusive(false);

    connect(ui.New_Game_Button, SIGNAL(clicked()), this, SLOT(Set_Game()));
    connect(ui.End_Game_Button, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui.Submit_Button, SIGNAL(clicked()), this, SLOT(loop_questions()));

}

Qt_APP::~Qt_APP(){
}

QString Qt_APP::Name_Input() {
    return ui.Name_Line->text();
}

int Qt_APP::Level_Input() {
    QString text = ui.Level_Box->currentText();
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

void Qt_APP::lock_in_input() {
    ui.Name_Line->setEnabled(false);
    ui.Level_Box->setEnabled(false);
    ui.Random_Box->setEnabled(false);
    ui.Submit_Button->setEnabled(true);
    ui.Next_Question_Button->setEnabled(true);
    ui.A_option->setEnabled(true);
    ui.B_option->setEnabled(true);
    ui.C_option->setEnabled(true);
    ui.D_option->setEnabled(true);

}

void Qt_APP::check_answers(int index) {
    if (ui.A_option->isChecked()) {
        if (q.getAnswer_index(index) == 0) {
			ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() + 0.5));
		}
        ui.A_option->setChecked(false);
	}
    else if (ui.B_option->isChecked()) {
        if (q.getAnswer_index(index) == 1) {
			ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() + 0.5));
		}
        ui.B_option->setChecked(false);
	}
    else if (ui.C_option->isChecked()) {
        if (q.getAnswer_index(index) == 2) {
			ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() + 0.5));
		}
        ui.C_option->setChecked(false);
	}
    else if (ui.D_option->isChecked()) {
        if (q.getAnswer_index(index) == 3) {
            ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() + 0.5));
        }
        ui.D_option->setChecked(false);
    }
}

void Qt_APP::loop_questions() {
    check_answers(q.get_order_index());
    q.increment();
    if (q.get_order_index() > 9) {
        QMessageBox::information(this, "Game Over", "Your score is: " + ui.Score_Field->text());
    }
    else {
        ui.Submit_Button->setEnabled(true);
        ui.Next_Question_Button->setEnabled(true);
        ui.Question_Field->setPlainText(q.getQuestion(q.get_order_index()));
        ui.A_option->setText(q.getAnswer(q.get_order_index(), 0));
        ui.B_option->setText(q.getAnswer(q.get_order_index(), 1));
        ui.C_option->setText(q.getAnswer(q.get_order_index(), 2));
        ui.D_option->setText(q.getAnswer(q.get_order_index(), 3));    
    }
}


void Qt_APP::Set_Game() {
    player.setName(Name_Input());
    player.setDifficulty(Level_Input());
    lock_in_input();

    if (ui.Random_Box->isChecked()){
        q.randomize_order();
    }
    else {
		q.normal_order();
	}
 
    loop_questions();
}




