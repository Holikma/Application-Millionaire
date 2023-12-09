#pragma once

#include <QString>

class Player {
private:
	QString name = "";
	int difficulty = 0;

public:
	Player();
	void setName(QString name);
	void setDifficulty(int difficulty);
	void print();
};