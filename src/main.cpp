#include<iostream>
#include "..\include\rlutil.h"
#include "..\include\enums.h"
#include "..\include\consts.h"
#include "..\include\functions.h"
#include "..\include\rubik.h"

void checkMove(char input);
Rubik cube;

int main(){
	rlutil::hidecursor();
	char input;
	char lang = enums::languages::EN;
	text::showInstructions(lang);
	while (true) {
        cube.Draw();
        input = getch();
        rlutil::locate(30, 5);
        if (input == toupper(input)) text::showCapsLockLabel(lang);
        else std::cout << consts::clearLine;
        switch (tolower(input)) {
        case enums::controls::SCRAMBLE:
            cube.Scramble();
            break;
        case enums::controls::SOLVE:
            cube.setState(consts::solved);
            break;
        case enums::controls::LANG:
            lang = text::langChange();
            break;
        case enums::controls::EXIT:
            return 0;
        }
        checkMove(input);

    }
}

void checkMove(char input) {
    int i = 0;
    switch(input) {
        case enums::controls::L:
            cube.turnL();
            break;
		case enums::controls::R:
            cube.turnR();
            break;
        case enums::controls::U:
            cube.turnU();
            break;
        case enums::controls::D:
            cube.turnD();
            break;
        case enums::controls::F:
            cube.turnF();
            break;
        case enums::controls::B:
            cube.turnB();
            break;
        case enums::controls::X:
            cube.turnX();
            break;
        case enums::controls::Y:
            cube.turnY();
            break;
        case enums::controls::U_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnU();
            }
            break;
        case enums::controls::L_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnL();
            }
            break;
        case enums::controls::R_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnR();
            }
            break;
        case enums::controls::D_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnD();
            }
            break;
        case enums::controls::F_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnF();
            }
            break;
        case enums::controls::B_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnB();
            }
            break;
        case enums::controls::X_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnX();
            }
            break;
        case enums::controls::Y_PRIME:
            for (i = 0; i < 3; i++) {
                cube.turnY();
            }
            break;
    }
}
