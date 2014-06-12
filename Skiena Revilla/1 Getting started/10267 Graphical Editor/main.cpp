/* 
 * File:   main.cpp
 * Author: aleksi13
 *
 * Created on 12 Июнь 2014 г., 20:16
 */

#include <iostream>
#include <fstream>
const int maxSize = 250;
using namespace std;

char picture[ maxSize + 1 ][ maxSize + 1 ];
bool filled[ maxSize + 1 ][ maxSize + 1 ];

void fill(char (&pic)[ maxSize + 1 ][ maxSize + 1 ], int x, int y, int sizeM, int sizeN, char c)
{
    filled[x][y] = true;
    if ( x > 1 ) 
        if ( ( pic[x][y] == pic[ x - 1 ][   y   ] ) and ( not filled[ x - 1 ][   y   ] ) )
            fill(pic, x - 1,   y  , sizeM, sizeN, c );
    if ( y > 1 )
        if ( ( pic[x][y] == pic[   x   ][ y - 1 ] ) and ( not filled[ x ][   y - 1   ] ) )
            fill(pic,   x  , y - 1, sizeM, sizeN, c );
    if ( ( x < maxSize ) and ( x < sizeM ) ) 
        if ( ( pic[x][y] == pic[ x + 1 ][   y   ] ) and ( not filled[ x + 1 ][   y   ] ) )
            fill(pic, x + 1,   y  , sizeM, sizeN, c );
    if ( ( y < maxSize ) and ( y < sizeN ) ) 
        if ( ( pic[x][y] == pic[   x   ][ y + 1 ] ) and ( not filled[ x ][   y + 1   ] ) )
            fill(pic,   x  , y + 1, sizeM, sizeN, c );
    pic[x][y] = c;
}

/*
 * 
 */
int main(int argc, char** argv) {
    //std::ifstream cin ("input.inp", std::ifstream::in);
    
    int sizeM = 0, sizeN = 0;
    char command = ' ';
    while ( 'X' != command )
    {
        cin >> command;
        switch (command) {
            int x, y, x1, x2, y1, y2;
            char c;
            case 'I':
                int m, n;
                cin >> m >> n;
                sizeM = m; sizeN = n;
                for (int i = 1; i <= sizeM; i++)
                    for (int j = 1; j <= sizeN; j++)
                        picture[i][j] = 'O';
                break;
            case 'C':
                for (int i = 1; i <= sizeM; i++)
                    for (int j = 1; j <= sizeN; j++)
                        picture[i][j] = 'O';
                break;
            case 'L':
                cin >> x >> y >> c;
                if ( ( x >= 1 ) and ( x <= sizeM ) and ( y >= 1 ) and ( y <= sizeN ) )
                        picture[x][y] = c;
                break;
            case 'V':
                cin >> x >> y1 >> y2 >> c;
                if ( y1 > y2 ) 
                {
                    int y_tmp = y1;
                    y1 = y2;
                    y2 = y_tmp;
                }
                for (int i = y1; i <= y2; i++)
                    picture[x][i] = c;
                break;
            case 'H':
                cin >> x1 >> x2 >> y >> c;
                if ( x1 > x2 )
                {
                    int x_tmp = x1;
                    x1 = x2;
                    x2 = x_tmp;
                }
                for (int i = x1; i <= x2; i++)
                    picture[i][y] = c;
                break;
            case 'K':
                cin >> x1 >> y1 >> x2 >> y2 >> c;
                for (int i = x1; i <= x2; i++)
                    for (int j = y1; j <= y2; j++)
                        picture[i][j] = c;
                break;
            case 'F':
                cin >> x >> y >> c;
                if ( ( x >= 1 ) and ( x <= sizeM ) and ( y >= 1 ) and ( y <= sizeN ) )
                {
                    for (int i = 1; i <= sizeM; i++)
                        for (int j = 1; j <= sizeN; j++)
                            filled[i][j] = false;
                    fill(picture, x, y, sizeM, sizeN, c);
                }
                break;
            case 'S':
                char fName[256];
                cin.getline(fName, 256);
                cout << fName + 1 << endl;
                for (int j = 1; j <= sizeN; j++)
                {
                  for (int i = 1; i <= sizeM; i++) cout << picture[i][j];
                  cout << endl;
                }
                break;
            default:
                char wrong_command[32];
                cin.getline(wrong_command,32);
                true;
        }
    }
    return 0;
}

