#include "Player.h"


Player::Player() {
	this->name = "";
	this->difficulty = 0;
}

void Player::setName(QString name) {
	this->name = name;
}

void Player::setDifficulty(int difficulty) {
	this->difficulty = difficulty;
}


void Player::print() {
	qDebug() << "Name: " << this->name;

}