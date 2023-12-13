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
    ui.Joker1_Button->setEnabled(false);
    ui.Joker2_Button->setEnabled(false);
    ui.Joker3_Button->setEnabled(false);
    connect(ui.New_Game_Button, SIGNAL(clicked()), this, SLOT(Set_Game()));
    connect(ui.Submit_Button, SIGNAL(clicked()), this, SLOT(loop_questions()));
    connect(ui.Next_Question_Button, SIGNAL(clicked()), this, SLOT(skip()));
    connect(ui.Joker1_Button, SIGNAL(clicked()), this, SLOT(Joker1()));
    connect(ui.Joker2_Button, SIGNAL(clicked()), this, SLOT(Joker2()));
    connect(ui.Joker3_Button, SIGNAL(clicked()), this, SLOT(Joker3()));
    connect(ui.End_Game_Button, SIGNAL(clicked()), this, SLOT(reset()));  
}

Qt_APP::~Qt_APP(){
}

QString Qt_APP::Name_Input() {
    return ui.Name_Line->text();
}

int Qt_APP::Level_Input() {
    QString text = ui.Level_Box->currentText();
    if (text == "Easy") {
        ui.Joker1_Button->setEnabled(true);
		ui.Joker2_Button->setEnabled(true);
		ui.Joker3_Button->setEnabled(true);
		return 1;
	}
	else if (text == "Medium") {
        ui.Joker1_Button->setEnabled(true);
        ui.Joker2_Button->setEnabled(true);
        ui.Joker3_Button->setEnabled(false);
		return 2;
	}
	else if (text == "Hard") {
        ui.Joker1_Button->setEnabled(true);
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
    ui.New_Game_Button->setEnabled(false);
    enable_options();
}

void Qt_APP::check_answers(int index) {
    if (ui.A_option->isChecked()) {
        if (q.getAnswer_index(index) == 0) {
            ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() + 1));
            QMessageBox::information(this, "Correct Answer", "You got it right!");
        }
        else {
            ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() - 1));
            QMessageBox::information(this, "Wrong Answer", "You got it wrong!");
        }
        ui.A_option->setAutoExclusive(false);
        ui.A_option->setChecked(false);
        ui.A_option->setAutoExclusive(true);
    }
    else if (ui.B_option->isChecked()) {
        if (q.getAnswer_index(index) == 1) {
            ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() + 1));
            QMessageBox::information(this, "Correct Answer", "You got it right!");
        }
        else {
            ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() - 1));
            QMessageBox::information(this, "Wrong Answer", "You got it wrong!");
        }
        ui.B_option->setAutoExclusive(false);
        ui.B_option->setChecked(false);
        ui.B_option->setAutoExclusive(true);
    }
    else if (ui.C_option->isChecked()) {
        if (q.getAnswer_index(index) == 2) {
            ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() + 1));
            QMessageBox::information(this, "Correct Answer", "You got it right!");
        }
        else {
            ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() - 1));
            QMessageBox::information(this, "Wrong Answer", "You got it wrong!");
        }
        ui.C_option->setAutoExclusive(false);
        ui.C_option->setChecked(false);
        ui.C_option->setAutoExclusive(true);
    }
    else if (ui.D_option->isChecked()) {
        if (q.getAnswer_index(index) == 3) {
            ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() + 1));
            QMessageBox::information(this, "Correct Answer", "You got it right!");
        }
        else {
            ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() - 1));
            QMessageBox::information(this, "Wrong Answer", "You got it wrong!");
        }
        ui.D_option->setAutoExclusive(false);
        ui.D_option->setChecked(false);
        ui.D_option->setAutoExclusive(true);
    }
    else if (!ui.A_option->isChecked() && !ui.B_option->isChecked() && !ui.C_option->isChecked() && !ui.D_option->isChecked() && q.get_order_index() != -1) {
        QMessageBox::information(this, "No Answer", "You didn't select an answer!");
        q.decrement();
    }
}

void Qt_APP::loop_questions() {
    check_answers(q.get_order_index());
    enable_options();
    q.increment();
    if (q.get_order_index() > 9) {
        QMessageBox::information(this, "Game Over", "Your score is: " + ui.Score_Field->text());
        ui.Next_Question_Button->setEnabled(false);
        ui.Submit_Button->setEnabled(false);
        ui.Joker1_Button->setEnabled(false);
        ui.Joker2_Button->setEnabled(false);
        ui.Joker3_Button->setEnabled(false);
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
    if (ui.Random_Box->isChecked()) {
        q.randomize_order();
    }
    else {
        q.normal_order();
    }
    loop_questions();
}

void Qt_APP::skip() {
    q.increment();
    if (q.get_order_index() > 9) {
        QMessageBox::information(this, "Game Over", "Your score is: " + ui.Score_Field->text());
        ui.Next_Question_Button->setEnabled(false);
        ui.Submit_Button->setEnabled(false);
        ui.Joker1_Button->setEnabled(false);
        ui.Joker2_Button->setEnabled(false);
        ui.Joker3_Button->setEnabled(false);
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
    ui.Score_Field->setText(QString::number(ui.Score_Field->text().toFloat() - 0.5));
}

void Qt_APP::Joker1() {
    ui.Joker1_Button->setEnabled(false);
    if (q.getAnswer_index(q.get_order_index()) == 0) {
        ui.A_option->setEnabled(true);// answer is A
        ui.B_option->setEnabled(true);
        ui.C_option->setEnabled(false);
        ui.D_option->setEnabled(false);
    }
    else if (q.getAnswer_index(q.get_order_index()) == 1) {
        ui.A_option->setEnabled(false);
        ui.B_option->setEnabled(true);// answer is B
        ui.C_option->setEnabled(true);
        ui.D_option->setEnabled(false);
    }
    else if (q.getAnswer_index(q.get_order_index()) == 2) {
        ui.A_option->setEnabled(false);
        ui.B_option->setEnabled(false);
        ui.C_option->setEnabled(true);// answer is C
        ui.D_option->setEnabled(true);
    }
    else if (q.getAnswer_index(q.get_order_index()) == 3) {
        ui.A_option->setEnabled(true);
        ui.B_option->setEnabled(false);
        ui.C_option->setEnabled(false);
        ui.D_option->setEnabled(true);// answer is D
    }
}

void Qt_APP::Joker2() {
    ui.Joker2_Button->setEnabled(false);
    if (q.getAnswer_index(q.get_order_index()) == 0) {
        ui.A_option->setEnabled(true); // answer is A
        ui.B_option->setEnabled(false);
        ui.C_option->setEnabled(true);
        ui.D_option->setEnabled(false);
    }
    else if (q.getAnswer_index(q.get_order_index()) == 1) {
        ui.A_option->setEnabled(false);
        ui.B_option->setEnabled(true); // answer is B
        ui.C_option->setEnabled(false);
        ui.D_option->setEnabled(true);
    }
    else if (q.getAnswer_index(q.get_order_index()) == 2) {
        ui.A_option->setEnabled(true);
        ui.B_option->setEnabled(false);
        ui.C_option->setEnabled(true); // answer is C
        ui.D_option->setEnabled(false);
    }
    else if (q.getAnswer_index(q.get_order_index()) == 3) {
        ui.A_option->setEnabled(false);
        ui.B_option->setEnabled(true);
        ui.C_option->setEnabled(false);
        ui.D_option->setEnabled(true); // answer is D
    }
}

void Qt_APP::Joker3() {
    ui.Joker3_Button->setEnabled(false);
    if (q.getAnswer_index(q.get_order_index()) == 0) {
        ui.A_option->setEnabled(true); // answer is A
		ui.B_option->setEnabled(false);
		ui.C_option->setEnabled(false);
        ui.D_option->setEnabled(true);
	}
    else if (q.getAnswer_index(q.get_order_index()) == 1) {
		ui.A_option->setEnabled(true);
        ui.B_option->setEnabled(true); // answer is B
		ui.C_option->setEnabled(false);
        ui.D_option->setEnabled(false);
	}
    else if (q.getAnswer_index(q.get_order_index()) == 2) {
		ui.A_option->setEnabled(false);
    	ui.B_option->setEnabled(true);
		ui.C_option->setEnabled(true); // answer is C
		ui.D_option->setEnabled(false);
	}
    else if (q.getAnswer_index(q.get_order_index()) == 3) {
		ui.A_option->setEnabled(false);
		ui.B_option->setEnabled(false);
        ui.C_option->setEnabled(true);
        ui.D_option->setEnabled(true); // answer is D
	}
}

void Qt_APP::enable_options() {
	ui.A_option->setEnabled(true);
	ui.B_option->setEnabled(true);
	ui.C_option->setEnabled(true);
	ui.D_option->setEnabled(true);
}

void Qt_APP::reset() {
    QMessageBox::information(this, "Game Over", "Your score is: " + QString::number(ui.Score_Field->text().toFloat() - 0.5 * (10 - q.get_order_index())));
    ui.New_Game_Button->setEnabled(true);
    ui.Name_Line->setEnabled(true);
	ui.Name_Line->setText("");
    q.normal_order();
    q.set_order_index(-1);
	ui.Score_Field->setText("0");
	ui.Level_Box->setEnabled(true);
	ui.Random_Box->setEnabled(true);
	ui.Submit_Button->setEnabled(false);
	ui.Next_Question_Button->setEnabled(false);
	ui.A_option->setEnabled(false);
	ui.B_option->setEnabled(false);
	ui.C_option->setEnabled(false);
	ui.D_option->setEnabled(false);
	ui.Question_Field->setPlainText("");
	ui.A_option->setText("A)");
	ui.B_option->setText("B)");
	ui.C_option->setText("C)");
	ui.D_option->setText("D)");
	ui.Joker1_Button->setEnabled(false);
	ui.Joker2_Button->setEnabled(false);
	ui.Joker3_Button->setEnabled(false);
}





