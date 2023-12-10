#pragma once

#include <QString>
#include <QDebug>


class Player {
private:
	QString name;
	int difficulty;

public:
	Player();
	int getNumber_of_jokers();
	void setName(QString name);
	void setDifficulty(int difficulty);
};