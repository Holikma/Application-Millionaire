#pragma once

#include <QString>
#include <QDebug>


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