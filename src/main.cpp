#include<iostream>
#include "..\include\rlutil.h"
#include "..\include\controls.h"
#include "..\include\consts.h"
#include "..\include\functions.h"
#include "..\include\rubik.h"

void checkMove(char input);
int checkOption(char input);
Rubik cube;

int main(){
	rlutil::hidecursor();
	instructions::showEnglish();
	char input;
	while (true) {
        cube.Draw();
        input = getch();
        checkMove(input);
        if (checkOption(input) == 0) return 0;
    }
}

int checkOption(char input) {
    switch (tolower(input)) {
        case SCRAMBLE:
            cube.Scramble();
            break;
        case SOLVE:
            cube.setState(consts::solved);
            break;
        case LANG:
            instructions::handleLangChange();
            break;
        case EXIT:
            return 0;
    }
    return 1;
}

void checkMove(char input) {
    int i = 0;
    switch(input) {
        case L:
            cube.turnL();
            break;
		case R:
            cube.turnR();
            break;
        case U:
            cube.turnU();
            break;
        case D:
            cube.turnD();
            break;
        case F:
            cube.turnF();
            break;
        case B:
            cube.turnB();
            break;
        case X:
            cube.turnX();
            break;
        case Y:
            cube.turnY();
            break;
        case U_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnU();
            }
            break;
        case L_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnL();
            }
            break;
        case R_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnR();
            }
            break;
        case D_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnD();
            }
            break;
        case F_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnF();
            }
            break;
        case B_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnB();
            }
            break;
        case X_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnX();
            }
            break;
        case Y_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnY();
            }
            break;
    }
}
