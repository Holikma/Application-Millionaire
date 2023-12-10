#pragma once

#include <QString>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <QString>
#include <QDebug>
#include <QFile>

class Question {
	private:
		QString Questions[10]{};
		QString Answers[10][4]{};
		int Answers_index[10]{};
		int question_order[10]{};
		int order_index = -1;
		
	public:
		Question();
		void randomize_order();
		void normal_order();
		void increment();
		void printQuestion(int index);
		int get_order_index();
		int getAnswer_index(int index);
		QString getQuestion(int index);
		QString getAnswer(int ind_i, int ind_j);
};