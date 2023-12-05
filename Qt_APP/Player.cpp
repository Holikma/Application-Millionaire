#include "Player.h"


Player::Player() {
	this->name = "";
	this->score = 0;
	this->difficulty = 0;
}

void Player::setName(QString name) {
	this->name = name;
}

void Player::setScore(float score) {
	this->score = score;
}

void Player::setDifficulty(int diff) {
	difficulty = diff;
}


void Player::print() {
	qDebug() << "Name: " << this->name << " Score: " << this->score;

}