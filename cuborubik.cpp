#include<iostream>
#include "rlutil.h"
using namespace rlutil;
using namespace std;

void graficar(string cubo[6][3])
{
    int x, y;
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
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
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                switch (cubo[i][j][k])
                {
                case 65:
                    setColor(BLUE);
                    setBackgroundColor(BLUE);
                    break;
                case 82:
                    setColor(RED);
                    setBackgroundColor(RED);
                    break;
                case 66:
                    setColor(WHITE);
                    setBackgroundColor(WHITE);
                    break;
                case 86:
                    setColor(LIGHTGREEN);
                    setBackgroundColor(LIGHTGREEN);
                    break;
                case 77:
                    setColor(BROWN);
                    setBackgroundColor(BROWN);
                    break;
                case 78:
                    setColor(LIGHTMAGENTA);
                    setBackgroundColor(LIGHTMAGENTA);
                    break;


                }
                locate(x + k + k*2, y + j + j);
                cout << cubo[i][j][k];
            }

        }
    }
    setBackgroundColor(BLACK);
    setColor(WHITE);
}

int main()
{
    setColor(GREEN);
    cout << "//EL MOVIMIENTO NO FUNCIONA SI SE TIENE BLOQ MAYUS ACTIVADO\n//TODOS LOS MOVIMIENTOS SON EN EL SENTIDO HORARIO\n";
    locate(50, 8);
    cout << "S // MOVER LA CAPA FRONTAL";
    locate(50, 9);
    cout << "A // MOVER LA CAPA IZQUIERDA";
    locate(50, 10);
    cout << "W // MOVER LA CAPA SUPERIOR";
    locate(50, 11);
    cout << "D // MOVER LA CAPA DERECHA";
    locate(50, 12);
    cout << "X // MOVER LA CAPA INFERIOR";
    locate(50, 13);
    cout << "F // MOVER LA CAPA TRASERA";
    locate(50, 14);
    cout << "E // GIRAR EL CUBO EN EL EJE X";
    locate(50, 15);
    cout << "R // GIRAR EL CUBO EN EL EJE Y";
    locate(50, 16);
    cout << "M // RESOLVER EL CUBO";
    locate(50, 17);
    cout << "N // MEZCLAR EL CUBO";
    locate(1, 24);
    cout << "TIP: PRESIONAR 3 VECES PARA REALIZAR MOVIMIENTOS EN SENTIDO ANTIHORARIO";
    hidecursor();
    int mezclar = 0;
    string cubo[6][3] = {{"BBB", "BBB", "BBB"}, {"RRR", "RRR", "RRR"}, {"VVV", "VVV", "VVV"}, {"NNN", "NNN", "NNN"}, {"AAA", "AAA", "AAA"}, {"MMM", "MMM", "MMM"}};
    while(true)
    {
        char entrada;
        graficar(cubo);
        setColor(BLACK);
        if (mezclar > 0 && mezclar < 25)
        {
            mezclar++;
            msleep(10);
            switch (rand() % 6)
            {
            case 0:
                entrada = 's';
                break;
            case 1:
                entrada = 'w';
                break;
            case 2:
                entrada = 'a';
                break;
            case 3:
                entrada = 'd';
                break;
            case 4:
                entrada = 'x';
                break;
            case 5:
                entrada = 'f';
                break;

            }
        }
        else
        {
            entrada = getch();
        }
        string tempCara1[3], tempCara2[3];
        char temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;
        switch (entrada)
        {
        case 's': // s
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[0][i];
            }
            cubo[0][0][0] = tempCara1[2][0];
            cubo[0][0][1] = tempCara1[1][0];
            cubo[0][0][2] = tempCara1[0][0];
            cubo[0][1][0] = tempCara1[2][1];
            cubo[0][1][2] = tempCara1[0][1];
            cubo[0][2][0] = tempCara1[2][2];
            cubo[0][2][1] = tempCara1[1][2];
            cubo[0][2][2] = tempCara1[0][2];
            temp1 = cubo[1][2][2];
            temp2 = cubo[1][1][2];
            temp3 = cubo[1][0][2];
            cubo[1][0][2] = cubo[4][0][0];
            cubo[1][1][2] = cubo[4][0][1];
            cubo[1][2][2] = cubo[4][0][2];
            temp4 = cubo[2][2][0];
            temp5 = cubo[2][2][1];
            temp6 = cubo[2][2][2];
            cubo[2][2][0] = temp1;
            cubo[2][2][1] = temp2;
            cubo[2][2][2] = temp3;
            temp7 = cubo[3][2][0];
            temp8 = cubo[3][1][0];
            temp9 = cubo[3][0][0];
            cubo[3][0][0] = temp4;
            cubo[3][1][0] = temp5;
            cubo[3][2][0] = temp6;
            cubo[4][0][0] = temp7;
            cubo[4][0][1] = temp8;
            cubo[4][0][2] = temp9;
            break;

        case 'a': // a
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[1][i];
            }
            cubo[1][0][0] = tempCara1[2][0];
            cubo[1][0][1] = tempCara1[1][0];
            cubo[1][0][2] = tempCara1[0][0];
            cubo[1][1][0] = tempCara1[2][1];
            cubo[1][1][2] = tempCara1[0][1];
            cubo[1][2][0] = tempCara1[2][2];
            cubo[1][2][1] = tempCara1[1][2];
            cubo[1][2][2] = tempCara1[0][2];
            temp1 = cubo[5][2][2];
            temp2 = cubo[5][1][2];
            temp3 = cubo[5][0][2];
            cubo[5][0][2] = cubo[4][2][0];
            cubo[5][1][2] = cubo[4][1][0];
            cubo[5][2][2] = cubo[4][0][0];
            temp4 = cubo[2][0][0];
            temp5 = cubo[2][1][0];
            temp6 = cubo[2][2][0];
            cubo[2][0][0] = temp1;
            cubo[2][1][0] = temp2;
            cubo[2][2][0] = temp3;
            temp7 = cubo[0][0][0];
            temp8 = cubo[0][1][0];
            temp9 = cubo[0][2][0];
            cubo[0][0][0] = temp4;
            cubo[0][1][0] = temp5;
            cubo[0][2][0] = temp6;
            cubo[4][0][0] = temp7;
            cubo[4][1][0] = temp8;
            cubo[4][2][0] = temp9;
            break;

        case 'd': // d
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[3][i];
            }
            cubo[3][0][0] = tempCara1[2][0];
            cubo[3][0][1] = tempCara1[1][0];
            cubo[3][0][2] = tempCara1[0][0];
            cubo[3][1][0] = tempCara1[2][1];
            cubo[3][1][2] = tempCara1[0][1];
            cubo[3][2][0] = tempCara1[2][2];
            cubo[3][2][1] = tempCara1[1][2];
            cubo[3][2][2] = tempCara1[0][2];
            temp1 = cubo[0][2][2];
            temp2 = cubo[0][1][2];
            temp3 = cubo[0][0][2];
            cubo[0][0][2] = cubo[4][0][2];
            cubo[0][1][2] = cubo[4][1][2];
            cubo[0][2][2] = cubo[4][2][2];
            temp4 = cubo[2][0][2];
            temp5 = cubo[2][1][2];
            temp6 = cubo[2][2][2];
            cubo[2][2][2] = temp1;
            cubo[2][1][2] = temp2;
            cubo[2][0][2] = temp3;
            temp7 = cubo[5][0][0];
            temp8 = cubo[5][1][0];
            temp9 = cubo[5][2][0];
            cubo[5][2][0] = temp4;
            cubo[5][1][0] = temp5;
            cubo[5][0][0] = temp6;
            cubo[4][2][2] = temp7;
            cubo[4][1][2] = temp8;
            cubo[4][0][2] = temp9;
            break;

        case 'f':
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[5][i];
            }
            cubo[5][0][0] = tempCara1[2][0];
            cubo[5][0][1] = tempCara1[1][0];
            cubo[5][0][2] = tempCara1[0][0];
            cubo[5][1][0] = tempCara1[2][1];
            cubo[5][1][2] = tempCara1[0][1];
            cubo[5][2][0] = tempCara1[2][2];
            cubo[5][2][1] = tempCara1[1][2];
            cubo[5][2][2] = tempCara1[0][2];
            temp1 = cubo[3][2][2];
            temp2 = cubo[3][1][2];
            temp3 = cubo[3][0][2];
            cubo[3][2][2] = cubo[4][2][0];
            cubo[3][1][2] = cubo[4][2][1];
            cubo[3][0][2] = cubo[4][2][2];
            temp4 = cubo[2][0][2];
            temp5 = cubo[2][0][1];
            temp6 = cubo[2][0][0];
            cubo[2][0][2] = temp1;
            cubo[2][0][1] = temp2;
            cubo[2][0][0] = temp3;
            temp7 = cubo[1][2][0];
            temp8 = cubo[1][1][0];
            temp9 = cubo[1][0][0];
            cubo[1][0][0] = temp4;
            cubo[1][1][0] = temp5;
            cubo[1][2][0] = temp6;
            cubo[4][2][2] = temp7;
            cubo[4][2][1] = temp8;
            cubo[4][2][0] = temp9;
            break;
        case 'w':
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[2][i];
            }
            cubo[2][0][0] = tempCara1[2][0];
            cubo[2][0][1] = tempCara1[1][0];
            cubo[2][0][2] = tempCara1[0][0];
            cubo[2][1][0] = tempCara1[2][1];
            cubo[2][1][2] = tempCara1[0][1];
            cubo[2][2][0] = tempCara1[2][2];
            cubo[2][2][1] = tempCara1[1][2];
            cubo[2][2][2] = tempCara1[0][2];
            temp1 = cubo[1][0][0];
            temp2 = cubo[1][0][1];
            temp3 = cubo[1][0][2];
            cubo[1][0][0] = cubo[0][0][0];
            cubo[1][0][1] = cubo[0][0][1];
            cubo[1][0][2] = cubo[0][0][2];
            temp4 = cubo[5][0][0];
            temp5 = cubo[5][0][1];
            temp6 = cubo[5][0][2];
            cubo[5][0][0] = temp1;
            cubo[5][0][1] = temp2;
            cubo[5][0][2] = temp3;
            temp7 = cubo[3][0][0];
            temp8 = cubo[3][0][1];
            temp9 = cubo[3][0][2];
            cubo[3][0][0] = temp4;
            cubo[3][0][1] = temp5;
            cubo[3][0][2] = temp6;
            cubo[0][0][0] = temp7;
            cubo[0][0][1] = temp8;
            cubo[0][0][2] = temp9;
            break;
        case 'x':
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[4][i];
            }
            cubo[4][0][0] = tempCara1[2][0];
            cubo[4][0][1] = tempCara1[1][0];
            cubo[4][0][2] = tempCara1[0][0];
            cubo[4][1][0] = tempCara1[2][1];
            cubo[4][1][2] = tempCara1[0][1];
            cubo[4][2][0] = tempCara1[2][2];
            cubo[4][2][1] = tempCara1[1][2];
            cubo[4][2][2] = tempCara1[0][2];
            temp1 = cubo[0][2][2];
            temp2 = cubo[0][2][1];
            temp3 = cubo[0][2][0];
            cubo[0][2][2] = cubo[1][2][2];
            cubo[0][2][1] = cubo[1][2][1];
            cubo[0][2][0] = cubo[1][2][0];
            temp4 = cubo[3][2][2];
            temp5 = cubo[3][2][1];
            temp6 = cubo[3][2][0];
            cubo[3][2][2] = temp1;
            cubo[3][2][1] = temp2;
            cubo[3][2][0] = temp3;
            temp7 = cubo[5][2][2];
            temp8 = cubo[5][2][1];
            temp9 = cubo[5][2][0];
            cubo[5][2][2] = temp4;
            cubo[5][2][1] = temp5;
            cubo[5][2][0] = temp6;
            cubo[1][2][2] = temp7;
            cubo[1][2][1] = temp8;
            cubo[1][2][0] = temp9;
            break;
        case 'm':
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    switch (i)
                    {
                    case 0:
                        cubo[i][j] = "BBB";
                        break;
                    case 1:
                        cubo[i][j] = "RRR";
                        break;
                    case 2:
                        cubo[i][j] = "VVV";
                        break;
                    case 3:
                        cubo[i][j] = "NNN";
                        break;
                    case 4:
                        cubo[i][j] = "AAA";
                        break;
                    case 5:
                        cubo[i][j] = "MMM";
                        break;
                    }
                }
            }
            break;
        case 'e':
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[2][i];
            }
            cubo[2][0][0] = tempCara1[2][0];
            cubo[2][0][1] = tempCara1[1][0];
            cubo[2][0][2] = tempCara1[0][0];
            cubo[2][1][0] = tempCara1[2][1];
            cubo[2][1][2] = tempCara1[0][1];
            cubo[2][2][0] = tempCara1[2][2];
            cubo[2][2][1] = tempCara1[1][2];
            cubo[2][2][2] = tempCara1[0][2];
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[4][i];
            }
            cubo[4][2][0] = tempCara1[0][0];
            cubo[4][1][0] = tempCara1[0][1];
            cubo[4][0][0] = tempCara1[0][2];
            cubo[4][2][1] = tempCara1[1][0];
            cubo[4][0][1] = tempCara1[1][2];
            cubo[4][2][2] = tempCara1[2][0];
            cubo[4][1][2] = tempCara1[2][1];
            cubo[4][0][2] = tempCara1[2][2];
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[0][i];
            }
            cubo[0][0] = cubo[3][0];
            cubo[0][1] = cubo[3][1];
            cubo[0][2] = cubo[3][2];
            for (int i = 0; i < 3; i++)
            {
                tempCara2[i] = cubo[1][i];
            }
            cubo[1][0] = tempCara1[0];
            cubo[1][1] = tempCara1[1];
            cubo[1][2] = tempCara1[2];
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[5][i];
            }
            cubo[5][0] = tempCara2[0];
            cubo[5][1] = tempCara2[1];
            cubo[5][2] = tempCara2[2];
            cubo[3][0] = tempCara1[0];
            cubo[3][1] = tempCara1[1];
            cubo[3][2] = tempCara1[2];
            break;
        case 'r':
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[1][i];
            }
            cubo[1][2][0] = tempCara1[0][0];
            cubo[1][1][0] = tempCara1[0][1];
            cubo[1][0][0] = tempCara1[0][2];
            cubo[1][2][1] = tempCara1[1][0];
            cubo[1][0][1] = tempCara1[1][2];
            cubo[1][2][2] = tempCara1[2][0];
            cubo[1][1][2] = tempCara1[2][1];
            cubo[1][0][2] = tempCara1[2][2];
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[3][i];
            }
            cubo[3][0][0] = tempCara1[2][0];
            cubo[3][0][1] = tempCara1[1][0];
            cubo[3][0][2] = tempCara1[0][0];
            cubo[3][1][0] = tempCara1[2][1];
            cubo[3][1][2] = tempCara1[0][1];
            cubo[3][2][0] = tempCara1[2][2];
            cubo[3][2][1] = tempCara1[1][2];
            cubo[3][2][2] = tempCara1[0][2];
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[0][i];
            }
            cubo[0][0] = cubo[4][0];
            cubo[0][1] = cubo[4][1];
            cubo[0][2] = cubo[4][2];
            for (int i = 0; i < 3; i++)
            {
                tempCara2[i] = cubo[2][i];
            }
            cubo[2][0] = tempCara1[0];
            cubo[2][1] = tempCara1[1];
            cubo[2][2] = tempCara1[2];
            for (int i = 0; i < 3; i++)
            {
                tempCara1[i] = cubo[5][i];
            }
            cubo[5][2] = tempCara2[0];
            cubo[5][1] = tempCara2[1];
            cubo[5][0] = tempCara2[2];
            cubo[5][2][0] = tempCara2[0][2];
            cubo[5][1][0] = tempCara2[1][2];
            cubo[5][0][0] = tempCara2[2][2];
            cubo[5][2][2] = tempCara2[0][0];
            cubo[5][1][2] = tempCara2[1][0];
            cubo[5][0][2] = tempCara2[2][0];
            cubo[4][2] = tempCara1[0];
            cubo[4][1] = tempCara1[1];
            cubo[4][0] = tempCara1[2];
            cubo[4][2][0] = tempCara1[0][2];
            cubo[4][1][0] = tempCara1[1][2];
            cubo[4][0][0] = tempCara1[2][2];
            cubo[4][2][2] = tempCara1[0][0];
            cubo[4][1][2] = tempCara1[1][0];
            cubo[4][0][2] = tempCara1[2][0];
            break;
        case 'n':
            mezclar = 1;
            break;
        }
    }
}
