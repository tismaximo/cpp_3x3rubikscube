#include<iostream>
#include "..\include\rubik.h"
#include "..\include\rlutil.h"


Rubik::Rubik(const std::string state[6][consts::dimensions]) {
	this->state = new std::string*[6];
	for (int i = 0; i < 6; i++) {
		this->state[i] = new std::string[consts::dimensions];
	}
	this->setState(state);
}

Rubik::Rubik() {
	this->state = new std::string*[6];
	for (int i = 0; i < 6; i++) {
		this->state[i] = new std::string[consts::dimensions];
	}
	this->setState(consts::solved);
}

Rubik::~Rubik() {
	delete this->state;
}

void Rubik::setState(const std::string state[6][consts::dimensions]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < consts::dimensions; j++) {
			this->state[i][j] = state[i][j];
		}
	}
}

std::string** Rubik::getState() { return this->state; }

void Rubik::Draw() {
	int x, y; // position in which the individual color will be drawn
    for (int i = 0; i < 6; i++) {
        switch (i) { // the positions in which the first of the 9 colors of the side will be drawn
        case 0:
            x = 14;
            y = 11;
            break;
        case 1:
            x = 4;
            y = 11;
            break;
        case 2:
            x = 14;
            y = 4;
            break;
        case 3:
            x = 24;
            y = 11;
            break;
        case 4:
            x = 14;
            y = 18;
            break;
        case 5:
            x = 34;
            y = 11;
            break;
        }
        for (int j = 0; j < consts::dimensions; j++) {
            for (int k = 0; k < consts::dimensions; k++) {
                switch (this->state[i][j][k]) {
                case 65:
                    rlutil::setColor(rlutil::BLUE);
                    rlutil::setBackgroundColor(rlutil::BLUE);
                    break;
                case 82:
                    rlutil::setColor(rlutil::RED);
                    rlutil::setBackgroundColor(rlutil::RED);
                    break;
                case 66:
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::setBackgroundColor(rlutil::WHITE);
                    break;
                case 86:
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
                    break;
                case 77:
                    rlutil::setColor(rlutil::BROWN);
                    rlutil::setBackgroundColor(rlutil::BROWN);
                    break;
                case 78:
                    rlutil::setColor(rlutil::LIGHTMAGENTA);
                    rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
                    break;
                }
                rlutil::locate(x + k + k*2, y + j + j); // increases the X position for every K loop, increases Y for every J loop
                std::cout << state[i][j][k]; // draws an individual square
            }
        }
        //repeat for the remaining sides
    }
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
}

void Rubik::Scramble() {
	for (int i = 0; i < 25; i++) {
		switch (rand() % 6) {
		case 0:
			turnB();
			break;
		case 1:
			turnL();
			break;
		case 2:
			turnD();
			break;
		case 3:
			turnF();
			break;
		case 4:
			turnR();
			break;
		case 5:
			turnU();
			break;
		}
		Draw();
        rlutil::msleep(10);
	}
}

// turns (this code sucks i will try to come up with a way to make it more flexible later)
// each of these functions moves each individual square that needs to be moved one by one and in no particular order

void Rubik::turnB() {
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[5][i];
	}
	state[5][0][0] = tempSide1[2][0];
	state[5][0][1] = tempSide1[1][0];
	state[5][0][2] = tempSide1[0][0];
	state[5][1][0] = tempSide1[2][1];
	state[5][1][2] = tempSide1[0][1];
	state[5][2][0] = tempSide1[2][2];
	state[5][2][1] = tempSide1[1][2];
	state[5][2][2] = tempSide1[0][2];
	temp1 = state[3][2][2];
	temp2 = state[3][1][2];
	temp3 = state[3][0][2];
	state[3][2][2] = state[4][2][0];
	state[3][1][2] = state[4][2][1];
	state[3][0][2] = state[4][2][2];
	temp4 = state[2][0][2];
	temp5 = state[2][0][1];
	temp6 = state[2][0][0];
	state[2][0][2] = temp1;
	state[2][0][1] = temp2;
	state[2][0][0] = temp3;
	temp7 = state[1][2][0];
	temp8 = state[1][1][0];
	temp9 = state[1][0][0];
	state[1][0][0] = temp4;
	state[1][1][0] = temp5;
	state[1][2][0] = temp6;
	state[4][2][2] = temp7;
	state[4][2][1] = temp8;
	state[4][2][0] = temp9;
}

void Rubik::turnD() {
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[4][i];
	}
	state[4][0][0] = tempSide1[2][0];
	state[4][0][1] = tempSide1[1][0];
	state[4][0][2] = tempSide1[0][0];
	state[4][1][0] = tempSide1[2][1];
	state[4][1][2] = tempSide1[0][1];
	state[4][2][0] = tempSide1[2][2];
	state[4][2][1] = tempSide1[1][2];
	state[4][2][2] = tempSide1[0][2];
	temp1 = state[0][2][2];
	temp2 = state[0][2][1];
	temp3 = state[0][2][0];
	state[0][2][2] = state[1][2][2];
	state[0][2][1] = state[1][2][1];
	state[0][2][0] = state[1][2][0];
	temp4 = state[3][2][2];
	temp5 = state[3][2][1];
	temp6 = state[3][2][0];
	state[3][2][2] = temp1;
	state[3][2][1] = temp2;
	state[3][2][0] = temp3;
	temp7 = state[5][2][2];
	temp8 = state[5][2][1];
	temp9 = state[5][2][0];
	state[5][2][2] = temp4;
	state[5][2][1] = temp5;
	state[5][2][0] = temp6;
	state[1][2][2] = temp7;
	state[1][2][1] = temp8;
	state[1][2][0] = temp9;
}

void Rubik::turnF() {
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[0][i];
	}
	state[0][0][0] = tempSide1[2][0];
	state[0][0][1] = tempSide1[1][0];
	state[0][0][2] = tempSide1[0][0];
	state[0][1][0] = tempSide1[2][1];
	state[0][1][2] = tempSide1[0][1];
	state[0][2][0] = tempSide1[2][2];
	state[0][2][1] = tempSide1[1][2];
	state[0][2][2] = tempSide1[0][2];
	temp1 = state[1][2][2];
	temp2 = state[1][1][2];
	temp3 = state[1][0][2];
	state[1][0][2] = state[4][0][0];
	state[1][1][2] = state[4][0][1];
	state[1][2][2] = state[4][0][2];
	temp4 = state[2][2][0];
	temp5 = state[2][2][1];
	temp6 = state[2][2][2];
	state[2][2][0] = temp1;
	state[2][2][1] = temp2;
	state[2][2][2] = temp3;
	temp7 = state[3][2][0];
	temp8 = state[3][1][0];
	temp9 = state[3][0][0];
	state[3][0][0] = temp4;
	state[3][1][0] = temp5;
	state[3][2][0] = temp6;
	state[4][0][0] = temp7;
	state[4][0][1] = temp8;
	state[4][0][2] = temp9;
}

void Rubik::turnL() {
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[1][i];
	}
	state[1][0][0] = tempSide1[2][0];
	state[1][0][1] = tempSide1[1][0];
	state[1][0][2] = tempSide1[0][0];
	state[1][1][0] = tempSide1[2][1];
	state[1][1][2] = tempSide1[0][1];
	state[1][2][0] = tempSide1[2][2];
	state[1][2][1] = tempSide1[1][2];
	state[1][2][2] = tempSide1[0][2];
	temp1 = state[5][2][2];
	temp2 = state[5][1][2];
	temp3 = state[5][0][2];
	state[5][0][2] = state[4][2][0];
	state[5][1][2] = state[4][1][0];
	state[5][2][2] = state[4][0][0];
	temp4 = state[2][0][0];
	temp5 = state[2][1][0];
	temp6 = state[2][2][0];
	state[2][0][0] = temp1;
	state[2][1][0] = temp2;
	state[2][2][0] = temp3;
	temp7 = state[0][0][0];
	temp8 = state[0][1][0];
	temp9 = state[0][2][0];
	state[0][0][0] = temp4;
	state[0][1][0] = temp5;
	state[0][2][0] = temp6;
	state[4][0][0] = temp7;
	state[4][1][0] = temp8;
	state[4][2][0] = temp9;
}

void Rubik::turnR() {
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[3][i];
	}
	state[3][0][0] = tempSide1[2][0];
	state[3][0][1] = tempSide1[1][0];
	state[3][0][2] = tempSide1[0][0];
	state[3][1][0] = tempSide1[2][1];
	state[3][1][2] = tempSide1[0][1];
	state[3][2][0] = tempSide1[2][2];
	state[3][2][1] = tempSide1[1][2];
	state[3][2][2] = tempSide1[0][2];
	temp1 = state[0][2][2];
	temp2 = state[0][1][2];
	temp3 = state[0][0][2];
	state[0][0][2] = state[4][0][2];
	state[0][1][2] = state[4][1][2];
	state[0][2][2] = state[4][2][2];
	temp4 = state[2][0][2];
	temp5 = state[2][1][2];
	temp6 = state[2][2][2];
	state[2][2][2] = temp1;
	state[2][1][2] = temp2;
	state[2][0][2] = temp3;
	temp7 = state[5][0][0];
	temp8 = state[5][1][0];
	temp9 = state[5][2][0];
	state[5][2][0] = temp4;
	state[5][1][0] = temp5;
	state[5][0][0] = temp6;
	state[4][2][2] = temp7;
	state[4][1][2] = temp8;
	state[4][0][2] = temp9;
}

void Rubik::turnU() {
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[2][i];
	}
	state[2][0][0] = tempSide1[2][0];
	state[2][0][1] = tempSide1[1][0];
	state[2][0][2] = tempSide1[0][0];
	state[2][1][0] = tempSide1[2][1];
	state[2][1][2] = tempSide1[0][1];
	state[2][2][0] = tempSide1[2][2];
	state[2][2][1] = tempSide1[1][2];
	state[2][2][2] = tempSide1[0][2];
	temp1 = state[1][0][0];
	temp2 = state[1][0][1];
	temp3 = state[1][0][2];
	state[1][0][0] = state[0][0][0];
	state[1][0][1] = state[0][0][1];
	state[1][0][2] = state[0][0][2];
	temp4 = state[5][0][0];
	temp5 = state[5][0][1];
	temp6 = state[5][0][2];
	state[5][0][0] = temp1;
	state[5][0][1] = temp2;
	state[5][0][2] = temp3;
	temp7 = state[3][0][0];
	temp8 = state[3][0][1];
	temp9 = state[3][0][2];
	state[3][0][0] = temp4;
	state[3][0][1] = temp5;
	state[3][0][2] = temp6;
	state[0][0][0] = temp7;
	state[0][0][1] = temp8;
	state[0][0][2] = temp9;
}

// perspective changes
// does the exact same thing as turns

void Rubik::turnX() {
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[2][i];
	}
	state[2][0][0] = tempSide1[2][0];
	state[2][0][1] = tempSide1[1][0];
	state[2][0][2] = tempSide1[0][0];
	state[2][1][0] = tempSide1[2][1];
	state[2][1][2] = tempSide1[0][1];
	state[2][2][0] = tempSide1[2][2];
	state[2][2][1] = tempSide1[1][2];
	state[2][2][2] = tempSide1[0][2];
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[4][i];
	}
	state[4][2][0] = tempSide1[0][0];
	state[4][1][0] = tempSide1[0][1];
	state[4][0][0] = tempSide1[0][2];
	state[4][2][1] = tempSide1[1][0];
	state[4][0][1] = tempSide1[1][2];
	state[4][2][2] = tempSide1[2][0];
	state[4][1][2] = tempSide1[2][1];
	state[4][0][2] = tempSide1[2][2];
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[0][i];
	}
	state[0][0] = state[3][0];
	state[0][1] = state[3][1];
	state[0][2] = state[3][2];
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide2[i] = state[1][i];
	}
	state[1][0] = tempSide1[0];
	state[1][1] = tempSide1[1];
	state[1][2] = tempSide1[2];
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[5][i];
	}
	state[5][0] = tempSide2[0];
	state[5][1] = tempSide2[1];
	state[5][2] = tempSide2[2];
	state[3][0] = tempSide1[0];
	state[3][1] = tempSide1[1];
	state[3][2] = tempSide1[2];
}

void Rubik::turnY() {
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[1][i];
	}
	state[1][2][0] = tempSide1[0][0];
	state[1][1][0] = tempSide1[0][1];
	state[1][0][0] = tempSide1[0][2];
	state[1][2][1] = tempSide1[1][0];
	state[1][0][1] = tempSide1[1][2];
	state[1][2][2] = tempSide1[2][0];
	state[1][1][2] = tempSide1[2][1];
	state[1][0][2] = tempSide1[2][2];
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[3][i];
	}
	state[3][0][0] = tempSide1[2][0];
	state[3][0][1] = tempSide1[1][0];
	state[3][0][2] = tempSide1[0][0];
	state[3][1][0] = tempSide1[2][1];
	state[3][1][2] = tempSide1[0][1];
	state[3][2][0] = tempSide1[2][2];
	state[3][2][1] = tempSide1[1][2];
	state[3][2][2] = tempSide1[0][2];
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[0][i];
	}
	state[0][0] = state[4][0];
	state[0][1] = state[4][1];
	state[0][2] = state[4][2];
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide2[i] = state[2][i];
	}
	state[2][0] = tempSide1[0];
	state[2][1] = tempSide1[1];
	state[2][2] = tempSide1[2];
	for (int i = 0; i < consts::dimensions; i++) {
		tempSide1[i] = state[5][i];
	}
	state[5][2] = tempSide2[0];
	state[5][1] = tempSide2[1];
	state[5][0] = tempSide2[2];
	state[5][2][0] = tempSide2[0][2];
	state[5][1][0] = tempSide2[1][2];
	state[5][0][0] = tempSide2[2][2];
	state[5][2][2] = tempSide2[0][0];
	state[5][1][2] = tempSide2[1][0];
	state[5][0][2] = tempSide2[2][0];
	state[4][2] = tempSide1[0];
	state[4][1] = tempSide1[1];
	state[4][0] = tempSide1[2];
	state[4][2][0] = tempSide1[0][2];
	state[4][1][0] = tempSide1[1][2];
	state[4][0][0] = tempSide1[2][2];
	state[4][2][2] = tempSide1[0][0];
	state[4][1][2] = tempSide1[1][0];
	state[4][0][2] = tempSide1[2][0];
}
