#ifndef CONTROLS_H_INCLUDED
#define CONTROLS_H_INCLUDED

namespace enums {

    namespace controls {
        enum Controls {
            U = 'w',
            D = 'x',
            L = 'a',
            R = 'd',
            F = 's',
            B = 'f',
            X = 'e',
            Y = 'r',
            U_PRIME = 'W',
            D_PRIME = 'X',
            L_PRIME = 'A',
            R_PRIME = 'D',
            F_PRIME = 'S',
            B_PRIME = 'B',
            X_PRIME = 'E',
            Y_PRIME = 'R',
            SCRAMBLE = 'n',
            SOLVE = 'm',
            LANG = 'l',
            EXIT = '0'
        };
    }
    namespace languages {
        enum Languages: char {
            ES = '1',
            EN  = '2'
        };
    }

}

#endif // CONTROLS_H_INCLUDED
