#pragma once

#include "Qt_APP.h"

class Player {
private:
	QString name = "";
	float score;
	int difficulty = 0;

public:
	Player();
	void setName(QString name);
	void setScore(float score);
	void setDifficulty(int difficulty);
	void print();
};