#pragma once

#include "Qt_APP.h"
#include <iostream>

using namespace std;

class Player{
	private:
		QString name = "";
		float score;
		
	public:
		Player();
		void setName();

};