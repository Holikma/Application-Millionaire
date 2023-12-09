#pragma once

#include <QString>


class Question {
	private:
		QString Questions[10]{};
		QString Answers[10][4]{};
		int Answers_index[10]{};
		
	public:
		Question();
		void printQuestions();
		QString getQuestion(int index);
		QString getAnswer(int ind_i, int ind_j);
		int getAnswer_index(int index);		
};