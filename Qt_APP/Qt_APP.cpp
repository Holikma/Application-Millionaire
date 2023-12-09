#include "Qt_APP.h"

Qt_APP::Qt_APP(QWidget *parent) : QMainWindow(parent){
    ui.setupUi(this);
    ui.Score_Field->setText("0");
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
    ui.Name_Line->setEnabled(false);
    ui.Level_Box->setEnabled(false);
    ui.Random_Box->setEnabled(false);
    ui.Submit_Button->setEnabled(true);

}

void Qt_APP::check_answers(Question q) {
    if (ui.A_option->isChecked()) {
        if (q.getAnswer_index(current_index) == 0) {
			ui.Score_Field->setText(QString::number(ui.Score_Field->text().toInt() + 1));
		}
	}
    else if (ui.B_option->isChecked()) {
        if (q.getAnswer_index(current_index) == 1) {
			ui.Score_Field->setText(QString::number(ui.Score_Field->text().toInt() + 1));
		}
	}
    else if (ui.C_option->isChecked()) {
        if (q.getAnswer_index(current_index) == 2) {
			ui.Score_Field->setText(QString::number(ui.Score_Field->text().toInt() + 1));
		}
	}
    else  {
        if (q.getAnswer_index(current_index) == 3) {
			ui.Score_Field->setText(QString::number(ui.Score_Field->text().toInt() + 1));
		}
	}

    ui.A_option->setChecked(false);
    ui.B_option->setChecked(false);
    ui.C_option->setChecked(false);
    ui.D_option->setChecked(false);

    ui.A_option->setEnabled(true);
    ui.B_option->setEnabled(true);
    ui.C_option->setEnabled(true);
    ui.D_option->setEnabled(true);
}

void Qt_APP::submit_answer() {
    ui.A_option->setEnabled(false);
    ui.B_option->setEnabled(false);
    ui.C_option->setEnabled(false);
    ui.D_option->setEnabled(false);
}

void Qt_APP::loop_questions() {
    current_index++;
    if (current_index > 9) {
        QMessageBox::information(this, "Game Over", "Your score is: " + ui.Score_Field->text());
        close();
    }
    else {
    ui.Question_Field->setReadOnly(true);
    ui.Submit_Button->setEnabled(true);
    ui.Question_Field->setPlainText(q.getQuestion(current_index));
    ui.A_option->setText(q.getAnswer(current_index, 0));
    ui.B_option->setText(q.getAnswer(current_index, 1));
    ui.C_option->setText(q.getAnswer(current_index, 2));
    ui.D_option->setText(q.getAnswer(current_index, 3));
    check_answers(q);
    }
}

void Qt_APP::randomize_order(int* order) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 9; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(order[i], order[j]);
    }
}

void Qt_APP::Set_Game() {
    player1.setName(Name_Input());
    player1.setDifficulty(Level_Input());

    freeze();
    if (ui.Random_Box->isChecked()) {
        int order[10] = { 0,1,2,3,4,5,6,7,8,9 };
        randomize_order(order);
        for (int i = 0; i < 10; i++) {
            ui.Question_Field->setPlainText(q.getQuestion(order[i]));
            ui.A_option->setText(q.getAnswer(order[i], 0));
            ui.B_option->setText(q.getAnswer(order[i], 1));
            ui.C_option->setText(q.getAnswer(order[i], 2));
            ui.D_option->setText(q.getAnswer(order[i], 3));
            check_answers(q);
            submit_answer();
            loop_questions();
        }
        loop_questions();
    }
}




