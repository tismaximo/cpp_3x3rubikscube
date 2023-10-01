#include "consts.h"
#ifndef RUBIK_H_INCLUDED
#define RUBIK_H_INCLUDED

class Rubik {

private:
    std::string** state;
    // temporary states to move the pieces around
    std::string tempSide1[consts::dimensions], tempSide2[consts::dimensions];
    char temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;
public:
    Rubik(const std::string state[6][consts::dimensions]);
    Rubik();
    ~Rubik();
    void setState(const std::string state[6][consts::dimensions]);
    std::string** getState();
    void Draw();
    void Scramble();
    //turns
    void turnU();
    void turnL();
    void turnR();
    void turnD();
    void turnF();
    void turnB();
    //perspective change
    void turnX();
    void turnY();

};

#endif // RUBIK_H_INCLUDED
