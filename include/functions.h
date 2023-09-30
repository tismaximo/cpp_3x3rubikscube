#include "consts.h"
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "controls.h"

namespace instructions {

    void showSpanish() {
        rlutil::locate(50, 8);
        std::cout << (char)toupper(F) << " // MOVER LA CAPA FRONTAL";
        rlutil::locate(50, 9);
        std::cout << (char)toupper(L) << " // MOVER LA CAPA IZQUIERDA";
        rlutil::locate(50, 10);
        std::cout << (char)toupper(U) << " // MOVER LA CAPA SUPERIOR";
        rlutil::locate(50, 11);
        std::cout << (char)toupper(R) << " // MOVER LA CAPA DERECHA";
        rlutil::locate(50, 12);
        std::cout << (char)toupper(D) << "  // MOVER LA CAPA INFERIOR";
        rlutil::locate(50, 13);
        std::cout << (char)toupper(B) << " // MOVER LA CAPA TRASERA";
        rlutil::locate(50, 14);
        std::cout << (char)toupper(X) << " // GIRAR EL CUBO EN EL EJE X";
        rlutil::locate(50, 15);
        std::cout << (char)toupper(Y) << " // GIRAR EL CUBO EN EL EJE Y";
        rlutil::locate(50, 16);
        std::cout << (char)toupper(SOLVE) << " // RESOLVER EL CUBO";
        rlutil::locate(50, 17);
        std::cout << (char)toupper(SCRAMBLE) << " // MEZCLAR EL CUBO";
        rlutil::locate(50, 18);
        std::cout << (char)toupper(LANG) << " // CAMBIAR DE IDIOMA";
        rlutil::locate(50, 19);
        std::cout << (char)toupper(EXIT) << " // SALIR";
        rlutil::locate(1, 24);
        std::cout << "// ACTIVAR BLOQ MAYUS PARA REALIZAR MOVIMIENTOS ANTIHORARIOS";
    }

    void showEnglish() {
        rlutil::locate(50, 8);
        std::cout << (char)toupper(F) << " // MOVE THE FRONT LAYER";
        rlutil::locate(50, 9);
        std::cout << (char)toupper(L) << " // MOVER THE LEFT LAYER";
        rlutil::locate(50, 10);
        std::cout << (char)toupper(U) << " // MOVER THE UPPER LAYER";
        rlutil::locate(50, 11);
        std::cout << (char)toupper(R) << " // MOVE THE RIGHT LAYER";
        rlutil::locate(50, 12);
        std::cout << (char)toupper(D) << "  // MOVE THE BOTTOM LAYER";
        rlutil::locate(50, 13);
        std::cout << (char)toupper(B) << " // MOVER THE REAR LAYER";
        rlutil::locate(50, 14);
        std::cout << (char)toupper(X) << " // ROTATE CUBE IN THE X AXIS";
        rlutil::locate(50, 15);
        std::cout << (char)toupper(Y) << " // ROTATE CUBE IN THE Y AXIS";
        rlutil::locate(50, 16);
        std::cout << (char)toupper(SOLVE) << " // SOLVE";
        rlutil::locate(50, 17);
        std::cout << (char)toupper(SCRAMBLE) << " // SCRAMBLE";
        rlutil::locate(50, 18);
        std::cout << (char)toupper(LANG) << " // CHANGE LANGUAGE";
        rlutil::locate(50, 19);
        std::cout << (char)toupper(EXIT) << " // EXIT";
        rlutil::locate(1, 25);
        std::cout << "// USE CAPS LOCK TO DO COUNTERCLOCKWISE MOVEMENTS";
    }

    void handleLangChange() {
        char input;
        system("cls");
        for (int i = 1; i <= consts::langs; i++) {
            std::cout << i << " // " << consts::languageNames[i - 1] << std::endl;
        }
        input = getch();
        system("cls");
        switch (input) {
        case ES:
            showSpanish();
            break;
        case EN:
            showEnglish();
            break;
        default:
            handleLangChange();
            break;
        }
    }
}

#endif // FUNCTIONS_H_INCLUDED
