#include "consts.h"
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "enums.h"

namespace text {
    void showInstructions(char);

    char langChange() {
        char lang;
        system("cls");
        for (int i = 1; i <= consts::langs; i++) {
            std::cout << i << " // " << consts::languageNames[i - 1] << std::endl;
        }
        lang = getch();
        system("cls");
        showInstructions(lang);
        return lang;
    }

    void showInstructions(char lang) {
        switch (lang) {
        case enums::languages::ES:
                rlutil::locate(50, 8);
                std::cout << (char)toupper(enums::controls::F) << " // MOVER LA CAPA FRONTAL";
                rlutil::locate(50, 9);
                std::cout << (char)enums::controls::L_PRIME << " // MOVER LA CAPA IZQUIERDA";
                rlutil::locate(50, 10);
                std::cout << (char)toupper(enums::controls::U) << " // MOVER LA CAPA SUPERIOR";
                rlutil::locate(50, 11);
                std::cout << (char)enums::controls::R_PRIME << " // MOVER LA CAPA DERECHA";
                rlutil::locate(50, 12);
                std::cout << (char)enums::controls::D_PRIME << "  // MOVER LA CAPA INFERIOR";
                rlutil::locate(50, 13);
                std::cout << (char)enums::controls::B_PRIME << " // MOVER LA CAPA TRASERA";
                rlutil::locate(50, 14);
                std::cout << (char)enums::controls::X_PRIME << " // GIRAR EL CUBO EN EL EJE X";
                rlutil::locate(50, 15);
                std::cout << (char)enums::controls::Y_PRIME << " // GIRAR EL CUBO EN EL EJE Y";
                rlutil::locate(50, 16);
                std::cout << (char)toupper(enums::controls::SOLVE) << " // RESOLVER EL CUBO";
                rlutil::locate(50, 17);
                std::cout << (char)toupper(enums::controls::SCRAMBLE) << " // MEZCLAR EL CUBO";
                rlutil::locate(50, 18);
                std::cout << (char)toupper(enums::controls::LANG) << " // CAMBIAR DE IDIOMA";
                rlutil::locate(50, 19);
                std::cout << (char)toupper(enums::controls::EXIT) << " // SALIR";
                rlutil::locate(1, 25);
                std::cout << "// ACTIVAR BLOQ MAYUS PARA REALIZAR MOVIMIENTOS ANTIHORARIOS";
                break;
        case enums::languages::EN:
                rlutil::locate(50, 8);
                std::cout << (char)enums::controls::F_PRIME << " // MOVE THE FRONT LAYER";
                rlutil::locate(50, 9);
                std::cout << (char)enums::controls::L_PRIME << " // MOVE THE LEFT LAYER";
                rlutil::locate(50, 10);
                std::cout << (char)enums::controls::U_PRIME << " // MOVE THE UPPER LAYER";
                rlutil::locate(50, 11);
                std::cout << (char)enums::controls::R_PRIME << " // MOVE THE RIGHT LAYER";
                rlutil::locate(50, 12);
                std::cout << (char)enums::controls::D_PRIME << "  // MOVE THE BOTTOM LAYER";
                rlutil::locate(50, 13);
                std::cout << (char)enums::controls::B_PRIME << " // MOVE THE REAR LAYER";
                rlutil::locate(50, 14);
                std::cout << (char)enums::controls::X_PRIME << " // ROTATE CUBE IN THE X AXIS";
                rlutil::locate(50, 15);
                std::cout << (char)enums::controls::Y_PRIME << " // ROTATE CUBE IN THE Y AXIS";
                rlutil::locate(50, 16);
                std::cout << (char)toupper(enums::controls::SOLVE) << " // SOLVE";
                rlutil::locate(50, 17);
                std::cout << (char)toupper(enums::controls::SCRAMBLE) << " // SCRAMBLE";
                rlutil::locate(50, 18);
                std::cout << (char)toupper(enums::controls::LANG) << " // CHANGE LANGUAGE";
                rlutil::locate(50, 19);
                std::cout << (char)toupper(enums::controls::EXIT) << " // EXIT";
                rlutil::locate(1, 25);
                std::cout << "// USE CAPS LOCK TO DO COUNTERCLOCKWISE MOVEMENTS";
                break;
        default:
                langChange();
                break;
        }
    }

    void showCapsLockLabel(char lang) {
        switch (lang) {
        case enums::languages::EN:
                std::cout << "COUNTERCLOCKWISE MOVEMENTS ENABLED";
                break;
        case enums::languages::ES:
                std::cout << "MOVIMIENTOS ANTIHORARIOS ACTIVADOS";
        }
    }
}

#endif // FUNCTIONS_H_INCLUDED
