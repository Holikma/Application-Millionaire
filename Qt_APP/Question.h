#pragma once

#include <string>
#include "Qt_APP.h"

class Question {
	private:
		QString Questions[10]{};
		QString Answers[10][4]{};
		int Answers_index[10]{};
	public:
		Question();
		void loadQuestions();
		void printQuestions();
};