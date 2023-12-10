#include "Question.h"

Question::Question() {
    QString line = "";
    QFile file("questions.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        for (int i = 0; i < 10; i++) {
            line = in.readLine();
            Questions[i] = line;

            QString ans[5];
            line = in.readLine();
            QStringList ansList = line.split(',');

            for (int j = 0; j < 5; j++) {
                ans[j] = ansList[j];
                if (j == 4) {
                    Answers_index[i] = ans[j].toInt();
                    break;
                }
                Answers[i][j] = ans[j];
            }
        }
        file.close();
    }
    else {
        qDebug() << "Unable to open file";
    }

    for (int i = 0; i < 10; i++) {
		question_order[i] = i;
	}
}

void Question::printQuestion(int index) {
    qDebug() << "Question: " << question_order[index];
    qDebug() << "Answer: " << Answers[question_order[index]][Answers_index[question_order[index]]]  << "Answer index: " << Answers_index[question_order[index]];
    
}

QString Question::getQuestion(int index) {
	return Questions[question_order[index]];
}

QString Question::getAnswer(int index, int ans) {
	return Answers[question_order[index]][ans];
}

int Question::getAnswer_index(int index) {
	return Answers_index[question_order[index]];
}

int Question::get_order_index() {
	return order_index;
}

void Question::randomize_order() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
		std::swap(question_order[i], question_order[rand() % 10]);
	}
}

void Question::normal_order() {
    for (int i = 0; i < 10; i++) {
		question_order[i] = i;
	}
}

void Question::increment() {
    order_index++;
}

