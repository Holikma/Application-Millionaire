#include "Question.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Question::Question() {};

void Question::loadQuestions() {
	string line;
	ifstream myfile("questions.txt");
	istringstream iss(line);
	if (myfile.is_open()){

		for (int i = 0; i < 10; i++) {
			getline(myfile, line);
			Questions[i] = line;
			string ans[5];
			getline(myfile, line);
			istringstream iss(line);
			for (int j = 0; j < 5; j++) {
				getline(iss, ans[j], ',');
				if (j == 4) {
					Answers_index[i] = stoi(ans[j]);
					break;
				}
				Answers[i][j] = ans[j];
			}
	}
		myfile.close();
	}
	else cout << "Unable to open file";
	
};

void Question::printQuestions() {
	for (int i = 0; i < 10; i++) {
		cout << Questions[i] << endl;
		for (int j = 0; j < 4; j++) {
			cout << Answers[i][j] << " ";
		}
		cout << endl;
		cout << Answers_index[i] << endl;
	}
};