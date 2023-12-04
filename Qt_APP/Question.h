#pragma once

#include <string>

using namespace std;


class Question {
	private:
		string Questions[10]{};
		string Answers[10][4]{};
		int Answers_index[10]{};
	public:
		Question();
		void loadQuestions();
		void printQuestions();
		void setAnswersIndex();
		void SetAnswers();
		void setQuestion(int index);
};