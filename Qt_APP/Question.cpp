#include "Question.h"
#include <iostream>
#include <fstream>

using namespace std;

Question::Question() {};

void Question::loadQuestions() {
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
}

void Question::printQuestions() {
    for (int i = 0; i < 10; i++) {
        qDebug() << Questions[i];
        for (int j = 0; j < 4; j++) {
            qDebug() << Answers[i][j] << " ";
        }
        qDebug() << Answers_index[i];
    }
}

QString Question::getQuestion(int index) {
	return Questions[index];
}

QString Question::getAnswer(int index, int ans) {
	return Answers[index][ans];
}

int Question::getAnswer_index(int index) {
	return Answers_index[index];
}