#include "Player.h"


Player::Player() {
	this->name = "";
	this->score = 0;
	this->level = 0;
}

void Player::setName(QString name) {
	this->name = name;
}

void Player::setScore(float score) {
	this->score = score;
}

void Player::setLevel(QString level) {
	this->level = level;
}

void Player::print() {
	qDebug() << "Name: " << this->name << " Score: " << this->score;

}