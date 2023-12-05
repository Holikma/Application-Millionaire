#include "Player.h"
#include <iostream>

Player::Player() {
	this->name = "";
	this->score = 0;
}

void Player::setName(QString name) {
	this->name = name;
}

void Player::setScore(float score) {
	this->score = score;
}

void Player::print() {
	std::cout << "Name: " << this->name.toStdString() << std::endl;
	std::cout << "Score: " << this->score << std::endl;
}