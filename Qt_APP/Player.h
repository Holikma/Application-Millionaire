#pragma once

#include "Qt_APP.h"

class Player {
private:
	QString name = "";
	float score;

public:
	Player();
	void setName(QString name);
	void setScore(float score);
	void print();
};