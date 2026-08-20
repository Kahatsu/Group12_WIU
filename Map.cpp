#include "Map.h"
#include <iostream>
#include <windows.h>
#include "player.h"

Map::Map()
{
    playerXCoord = 17;
    playerYCoord = 33;
    for (int row = 0; row < 80; row++)
        for (int col = 0; col < 90; col++)
            map[row][col] = 'o';

    for (int row = 0; row < 11; row++)
        for (int col = 0; col < 11; col++)
            displayMap[row][col] = 'o';
}

void Map::loadMap(int floorNum)
{
    for (int row = 0; row < 80; row++)
        for (int col = 0; col < 90; col++)
            map[row][col] = 'o';

    for (int row = 0; row < 80; row++)
    {
        for (int col = 0; col < 80; col++)
        {
            if (row < 10 || row >= 60 || col < 10 || col >= 60)
            {
                map[row][col] = '.';
            }
        }
    }

    // Purple 2

    map[10][10] = '#'; 	map[10][11] = '#'; 	map[10][12] = '#'; 	map[10][13] = '#'; 	map[10][14] = '#';
    map[10][15] = '#';  map[10][16] = '#';  map[10][17] = '#';  map[10][18] = '#';  map[10][19] = '#';
    map[11][10] = '#';  map[12][10] = '#';  map[13][10] = '#';  map[14][10] = '#';  map[15][10] = '#';
    map[16][10] = '#';  map[17][10] = '#';  map[18][10] = '#';  map[19][10] = '#';  map[19][10] = '#';
    map[19][14] = '#';  map[19][14] = '#';  map[18][14] = '#';  map[16][15] = '#';  map[16][16] = '#';
    map[16][17] = '#';  map[16][18] = '#';  map[16][19] = '#';  map[16][18] = '#';  map[17][14] = '#';

    // Purple 3

    map[10][20] = '#'; 	map[10][21] = '#'; 	map[10][22] = '#'; 	map[10][23] = '#'; 	map[10][24] = '#';
    map[10][25] = '#'; 	map[10][26] = '#'; 	map[10][27] = '#'; 	map[10][28] = '#'; 	map[10][29] = '#';
    map[18][21] = '#';  map[18][21] = '#';  map[19][21] = '#';  map[16][20] = '#';  map[17][21] = '#';
    map[19][21] = '#';  map[11][25] = '#';  map[12][25] = '#';  map[13][25] = '#';  map[14][25] = '#';
    map[15][25] = '#';  map[16][25] = '#';  map[11][29] = '#';  map[12][29] = '#';
    map[19][29] = '#';  map[18][29] = '#';

    // Purple 4
    map[10][30] = '.';  map[10][32] = '.';  map[10][33] = '.';  map[10][34] = '.';  map[10][35] = '.';
    map[10][36] = '.';  map[10][37] = '.';  map[10][38] = '.';  map[10][31] = '.';
    map[11][30] = '.';  map[11][32] = '.';  map[11][33] = '.';  map[11][34] = '.';  map[10][35] = '.';
    map[11][36] = '.';  map[11][37] = '.';  map[11][38] = '.';  map[11][31] = '.';  map[11][35] = '.';
    map[18][30] = '#';  map[18][31] = '#';  map[18][32] = '#';  map[18][33] = '#';  map[18][34] = '#';
    map[18][35] = '#';  map[18][36] = '#';  map[18][37] = '#';  map[18][38] = '#';  map[18][39] = '#';
    map[12][30] = '#';  map[12][31] = '#';  map[12][32] = '#';  map[12][33] = '#';  map[12][34] = '#';
    map[12][35] = '#';  map[12][36] = '#';  map[12][37] = '#';  map[12][38] = '#';  map[12][39] = '#';


    // Purple 5

    map[12][39] = '#';  map[11][39] = '#'; map[10][39] = '#';   map[12][40] = '#';  map[12][41] = '#';
    map[12][42] = '#';  map[12][43] = '#'; map[12][44] = '#';   map[11][45] = '#';  map[10][46] = '#';
    map[10][47] = '#';  map[10][48] = '#'; map[10][49] = '#';   map[11][49] = '#';  map[12][49] = '#';
    map[13][49] = '#';  map[14][49] = '#'; map[15][49] = '#';   map[16][49] = '#';  map[17][49] = '#';
    map[18][49] = '#';  map[19][49] = '#'; map[19][48] = '#';   map[19][47] = '#';  map[19][46] = '#';
    map[18][45] = '#';  map[18][44] = '#'; map[18][43] = '#';   map[18][42] = '#';  map[18][41] = '#';
    map[18][40] = '#';  map[18][39] = '#'; map[19][39] = '#';

    // Blank spaces A5
    for (int row = 10; row < 20; row++)
    {
        for (int col = 50; col < 60; col++)
        {
            map[row][col] = '.';
        }

        map[10][40] = '.';  map[10][41] = '.';  map[10][42] = '.';  map[10][43] = '.';  map[10][44] = '.';
        map[10][45] = '.';  map[11][40] = '.';  map[11][41] = '.';  map[11][42] = '.';  map[11][43] = '.';
        map[11][44] = '.';  map[17][15] = '.';  map[17][16] = '.';  map[17][17] = '.';  map[17][18] = '.';
        map[17][19] = '.';  map[17][20] = '.';  map[18][15] = '.';  map[18][16] = '.';  map[18][17] = '.';
        map[18][18] = '.';  map[18][19] = '.';  map[18][20] = '.';  map[19][15] = '.';  map[19][16] = '.';
        map[19][17] = '.';  map[19][18] = '.';  map[19][19] = '.';  map[19][20] = '.';  map[20][15] = '.';
        map[20][16] = '.';  map[20][17] = '.';  map[20][18] = '.';  map[20][19] = '.';  map[20][20] = '.';
        map[21][15] = '.';  map[21][16] = '.';  map[21][17] = '.';  map[21][18] = '.';  map[21][19] = '.';
        map[21][20] = '.';  map[26][22] = '.';  map[26][23] = '.';  map[26][24] = '.';  map[27][22] = '.';
        map[27][23] = '.';  map[27][24] = '.';  map[27][21] = '.';  map[28][22] = '.';  map[28][23] = '.';
        map[28][24] = '.';  map[28][21] = '.';  map[29][22] = '.';  map[29][23] = '.';  map[29][24] = '.';
        map[29][21] = '.';

    }

    // Purple 1

    map[20][10] = '#'; 	map[21][10] = '#'; 	map[22][10] = '#'; 	map[23][10] = '#'; 	map[24][10] = '#';
    map[25][10] = '#'; 	map[26][10] = '#'; 	map[27][10] = '#'; 	map[28][10] = '#'; 	map[29][10] = '#';
    map[20][14] = '#'; 	map[21][14] = '#'; 	map[22][15] = '#'; 	map[22][16] = '#'; 	map[22][17] = '#';
    map[22][18] = '#'; 	map[22][19] = '#';  map[26][19] = '#';  map[26][18] = '#';  map[26][17] = '#';
    map[26][16] = '#';  map[26][15] = '#';  map[27][14] = '#';  map[28][14] = '#';  map[29][14] = '#';

    // Blue 1

    map[22][20] = '#';  map[21][21] = '#';  map[20][21] = '#';  map[20][22] = '#';  map[20][23] = '#';
    map[20][24] = '#';  map[20][25] = '#';  map[20][26] = '#';  map[20][22] = '#';  map[20][28] = '#';
    map[20][27] = '#';  map[20][29] = '#';  map[26][20] = '#';  map[27][20] = '#';  map[28][20] = '#';
    map[29][20] = '#';  map[26][21] = '#';  map[25][23] = '#';  map[25][24] = '#';  map[25][25] = '#';
    map[26][25] = '#';  map[27][25] = '#';  map[28][25] = '#';  map[25][29] = '#';  map[26][29] = '#';
    map[27][29] = '#';  map[28][29] = '#';  map[25][22] = '#';  map[24][29] = '#';  map[23][29] = '#';
    map[22][29] = '#';  map[21][29] = '#';  map[29][29] = '#';  map[29][25] = '#';

    // Blank Spaces B3
    map[19][30] = '.';  map[19][32] = '.';  map[19][33] = '.';  map[19][34] = '.';  map[19][35] = '.';
    map[19][36] = '.';  map[19][37] = '.';  map[19][38] = '.';  map[19][31] = '.';  map[19][39] = '.';
    map[20][30] = '.';  map[20][32] = '.';  map[20][33] = '.';  map[20][34] = '.';  map[20][35] = '.';
    map[20][36] = '.';  map[20][37] = '.';  map[20][38] = '.';  map[20][39] = '.';  map[20][31] = '.';
    map[21][30] = '.';  map[21][32] = '.';  map[21][33] = '.';  map[21][34] = '.';  map[21][35] = '.';
    map[21][36] = '.';  map[21][37] = '.';  map[21][38] = '.';  map[21][39] = '.';  map[21][31] = '.';
    map[22][30] = '.';  map[22][32] = '.';  map[22][33] = '.';  map[22][34] = '.';  map[22][35] = '.';
    map[22][36] = '.';  map[22][37] = '.';  map[22][38] = '.';  map[22][39] = '.';  map[22][31] = '.';
    map[23][30] = '.';  map[23][32] = '.';  map[23][33] = '.';  map[23][34] = '.';  map[23][35] = '.';
    map[23][36] = '.';  map[23][37] = '.';  map[23][38] = '.';  map[23][39] = '.';  map[23][31] = '.';
    map[24][30] = '.';  map[24][32] = '.';  map[24][33] = '.';  map[24][34] = '.';  map[24][35] = '.';
    map[24][36] = '.';  map[24][37] = '.';  map[24][38] = '.';  map[24][39] = '.';  map[24][31] = '.';
    map[25][30] = '.';  map[25][32] = '.';  map[25][33] = '.';  map[25][34] = '.';  map[25][35] = '.';
    map[25][36] = '.';  map[25][37] = '.';  map[25][38] = '.';  map[25][39] = '.';  map[25][31] = '.';
    map[26][30] = '.';  map[26][32] = '.';  map[26][33] = '.';  map[26][34] = '.';  map[26][35] = '.';
    map[26][36] = '.';  map[26][37] = '.';  map[26][38] = '.';  map[26][39] = '.';  map[26][31] = '.';
    map[27][30] = '.';  map[27][32] = '.';  map[27][33] = '.';  map[27][34] = '.';  map[27][35] = '.';
    map[27][36] = '.';  map[27][37] = '.';  map[27][38] = '.';  map[27][39] = '.';  map[27][31] = '.';
    map[28][30] = '.';  map[28][32] = '.';  map[28][33] = '.';  map[28][34] = '.';  map[28][35] = '.';
    map[28][36] = '.';  map[28][37] = '.';  map[28][38] = '.';  map[28][39] = '.';  map[28][31] = '.';
    map[29][30] = '.';  map[29][32] = '.';  map[29][33] = '.';  map[29][34] = '.';  map[29][35] = '.';
    map[29][36] = '.';  map[29][37] = '.';  map[29][38] = '.';  map[29][39] = '.';  map[29][31] = '.';

    // Starting Area / Bkue 2

    map[30][10] = '#';  map[31][10] = '#';  map[32][10] = '#';  map[33][10] = '#';  map[34][10] = '#';
    map[35][10] = '#';  map[36][10] = '#';  map[37][10] = '#';  map[38][10] = '#';  map[39][10] = '#';
    map[30][14] = '#';  map[31][14] = '#';  map[35][20] = '#';  map[36][20] = '#';  map[37][20] = '#';
    map[35][14] = '#';  map[36][14] = '#';  map[37][14] = '#';  map[38][14] = '#';  map[39][14] = '#';
    map[38][20] = '#';  map[39][20] = '#';  map[34][20] = '#';  map[33][20] = '#';  map[32][20] = '#';
    map[31][20] = '#';  map[30][20] = '#';  map[39][15] = '#';  map[39][16] = '#';  map[39][17] = '#';
    map[39][18] = '#';  map[39][19] = '#';  map[30][24] = '#';  map[30][23] = '#';  map[30][22] = '#';
    map[30][21] = '#';  map[30][25] = '#';  map[39][22] = '#';  map[39][21] = '#';  map[39][23] = '#';
    map[39][24] = '#';  map[39][25] = '#';  map[39][26] = '#';  map[39][27] = '#';  map[39][28] = '#';
    map[39][29] = '#';  map[30][29] = '#';  map[31][29] = '#';  map[32][29] = '#';  map[33][29] = '#';
    map[34][29] = '#';  map[35][29] = '#';  map[35][28] = '#';  map[35][27] = '#';  map[35][26] = '#';
    map[35][25] = '#';  map[35][24] = '#';  map[33][17] = 'P';  map[28][17] = 'M';  map[37][17] = 'C';


    // Blue 3

    map[39][30] = '#';  map[39][31] = '#';  map[39][32] = '#';  map[39][33] = '#';  map[39][34] = '#';
    map[39][35] = '#';  map[39][36] = '#';  map[38][37] = '#';  map[37][38] = '#';  map[36][39] = '#';
    map[35][30] = '#';  map[35][31] = '#';  map[35][32] = '#';  map[35][33] = '#';  map[35][34] = '#';
    map[35][35] = '#';  map[34][36] = '#';  map[33][37] = '#';  map[32][38] = '#';  map[32][39] = '#';

    // Blue 4

    map[32][40] = '#';  map[32][41] = '#';  map[32][42] = '#';  map[32][43] = '#';  map[32][44] = '#';
    map[32][45] = '#';  map[31][45] = '#';  map[30][45] = '#';  map[33][45] = '#';  map[34][45] = '#';
    map[35][45] = '#';  map[36][40] = '#';  map[36][41] = '#';  map[37][42] = '#';  map[38][43] = '#';
    map[39][43] = '#';  map[39][44] = '#';  map[39][45] = '#';  map[39][46] = '#';  map[39][47] = '#';
    map[39][48] = '#';  map[39][49] = '#';  map[38][49] = '#';  map[37][49] = '#';  map[36][49] = '#';
    map[35][49] = '#';  map[34][49] = '#';  map[33][49] = '#';  map[32][49] = '#';  map[31][49] = '#';
    map[30][49] = '#';

    // Blue 5

    map[29][49] = '#';  map[29][45] = '#';  map[29][44] = '#';  map[29][43] = '#';  map[29][42] = '#';
    map[29][41] = '#';  map[29][40] = '#';  map[28][40] = '#';  map[27][40] = '#';  map[26][40] = '#';
    map[25][40] = '#';  map[24][40] = '#';  map[23][40] = '#';  map[22][40] = '#';  map[21][40] = '#';
    map[30][49] = '#';  map[28][49] = '#';  map[27][49] = '#';  map[26][49] = '#';  map[21][41] = '#';
    map[25][49] = '#';  map[25][48] = '#';  map[25][47] = '#';  map[25][46] = '#';  map[25][45] = '#';
    map[25][44] = '#';  map[21][42] = '#';  map[21][43] = '#';  map[21][44] = '#';  map[21][45] = '#';
    map[21][46] = '#';  map[21][47] = '#';  map[21][48] = '#';  map[21][49] = '#';

    // Blue 6

    map[21][50] = '#';  map[21][51] = '#';  map[21][52] = '#';  map[21][53] = '#';  map[21][54] = '#';
    map[21][55] = '#';  map[21][56] = '#';  map[21][57] = '#';  map[22][57] = '#';  map[23][57] = '#';
    map[24][57] = '#';  map[25][57] = '#';  map[26][57] = '#';  map[27][57] = '#';  map[28][57] = '#';
    map[29][57] = '#';  map[25][50] = '#';  map[25][51] = '#';  map[25][52] = '#';  map[25][53] = '#';
    map[26][53] = '#';  map[27][53] = '#';  map[28][53] = '#';  map[29][53] = '#';  map[26][52] = '.';
    map[27][52] = '.';  map[28][52] = '.';  map[29][52] = '.';  map[26][51] = '.';  map[27][51] = '.';
    map[28][51] = '.';  map[29][51] = '.';  map[26][50] = '.';  map[27][50] = '.';  map[28][50] = '.';
    map[29][50] = '.';  map[20][59] = '.';  map[20][58] = '.';  map[20][57] = '.';  map[20][56] = '.';
    map[20][55] = '.';  map[20][54] = '.';  map[20][53] = '.';  map[20][52] = '.';  map[20][51] = '.';
    map[20][50] = '.';  map[20][49] = '.';  map[20][48] = '.';  map[20][47] = '.';  map[20][46] = '.';
    map[20][45] = '.';  map[20][44] = '.';  map[20][43] = '.';  map[20][42] = '.';  map[20][41] = '.';
    map[20][40] = '.';  map[19][40] = '.';  map[19][41] = '.';  map[19][42] = '.';  map[19][43] = '.';
    map[19][44] = '.';  map[19][45] = '.';  map[21][59] = '.';  map[22][59] = '.';  map[21][58] = '.';
    map[22][58] = '.';  map[23][58] = '.';  map[24][58] = '.';  map[25][58] = '.';  map[26][58] = '.';
    map[27][58] = '.';  map[28][58] = '.';  map[29][58] = '.';  map[23][59] = '.';  map[24][59] = '.';
    map[25][59] = '.';  map[26][59] = '.';  map[27][59] = '.';  map[28][59] = '.';  map[29][59] = '.';

    // pre made boss

    map[30][57] = '#';  map[31][57] = '#';  map[30][53] = '#';  map[31][53] = '#';  map[32][58] = '#';
    map[32][59] = '#';  map[32][52] = '#';  map[32][51] = '#';  map[32][50] = '#';  map[32][50] = '#';
    map[33][50] = '#';  map[34][50] = '#';  map[35][50] = '#';  map[36][50] = '#';  map[37][50] = '#';
    map[37][51] = '#';  map[37][52] = '#';  map[38][53] = '#';  map[39][53] = '#';  map[39][57] = '#';
    map[38][57] = '#';  map[37][58] = '#';  map[37][59] = '#';  map[38][59] = '.';  map[39][59] = '.';
    map[39][58] = '.';  map[38][58] = '.';  map[31][58] = '.';  map[30][58] = '.';  map[30][59] = '.';
    map[31][59] = '.';  map[31][52] = '.';  map[31][51] = '.';  map[31][50] = '.';  map[30][52] = '.';
    map[30][51] = '.';  map[30][50] = '.';  map[38][52] = '.';  map[38][51] = '.';  map[38][50] = '.';
    map[39][52] = '.';  map[39][51] = '.';  map[39][50] = '.';

    // Yellow 1

    map[40][10] = '#';  map[41][10] = '#';  map[42][10] = '#';  map[43][10] = '#';  map[44][10] = '#';
    map[45][11] = '#';  map[45][12] = '#';  map[45][13] = '#';  map[45][14] = '#';  map[46][15] = '#';
    map[47][15] = '#';  map[48][15] = '#';  map[49][15] = '#';  map[40][14] = '#';  map[41][14] = '#';
    map[42][15] = '#';  map[42][16] = '#';  map[42][17] = '#';  map[42][18] = '#';  map[48][19] = '#';
    map[43][19] = '#';  map[44][19] = '#';  map[45][19] = '#';  map[46][19] = '#';  map[47][19] = '#';
    map[49][19] = '#';


}

void Map::drawMap()
{
    updateDisplayMap();
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (displayMap[i][j] == '#')
            {
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if (displayMap[i][j] == 'P')
            {
                SetConsoleTextAttribute(hConsole, 10);
            }
            else if (displayMap[i][j] == 'M')
            {
                SetConsoleTextAttribute(hConsole, 14);
            }
            else if (displayMap[i][j] == 'C')
            {
                SetConsoleTextAttribute(hConsole, 6);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 8);
            }

            std::cout << displayMap[i][j] << " ";
        }
        std::cout << std::endl;
    }

    /*for (int row = 0; row < 70; row++)
    {
        for (int col = 0; col < 70; col++)
        {
            if (map[row][col] == '#')
            {
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if (map[row][col] == 'P')
            {
                SetConsoleTextAttribute(hConsole, 10);
            }
            else if (map[row][col] == 'M')
            {
                SetConsoleTextAttribute(hConsole, 14);
            }
            else if (map[row][col] == 'C')
            {
                SetConsoleTextAttribute(hConsole, 6);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 8);
            }

            std::cout << map[row][col] << " ";
        }

        std::cout << std::endl;
    }*/

    SetConsoleTextAttribute(hConsole, 7);
}

char Map::checkMap(int x_coord, int y_coord)
{
    return map[y_coord][x_coord];
}

void Map::updateMap(char symbol, int x_coord, int y_coord)
{
    map[y_coord][x_coord] = symbol;
}

void Map::setPlayerXCoord(int x)
{
    playerXCoord = x;
}

void Map::setPlayerYCoord(int y)
{
    playerYCoord = y;
}

void Map::updateDisplayMap()
{
    int counter = 0;
    
    displayMap[5][5] = map[playerYCoord][playerXCoord];
    //below player
    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[6][counter] = map[playerYCoord + 1][playerXCoord + i];
        counter++;
    }

    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[7][counter] = map[playerYCoord + 2][playerXCoord + i];
        counter++;
    }

    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[8][counter] = map[playerYCoord + 3][playerXCoord + i];
        counter++;
    }

    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[9][counter] = map[playerYCoord + 4][playerXCoord + i];
        counter++;
    }

    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[10][counter] = map[playerYCoord + 5][playerXCoord + i];
        counter++;
    }
    
    //above player
    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[4][counter] = map[playerYCoord - 1][playerXCoord + i];
        counter++;
    }
    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[3][counter] = map[playerYCoord - 2][playerXCoord + i];
        counter++;
    }
    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[2][counter] = map[playerYCoord - 3][playerXCoord + i];
        counter++;
    }
    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[1][counter] = map[playerYCoord - 4][playerXCoord + i];
        counter++;
    }
    counter = 0;
    for (int i = -5; i <= 5; i++) {
        displayMap[0][counter] = map[playerYCoord - 5][playerXCoord + i];
        counter++;
    }

    //player row LEFT of player
    displayMap[5][0] = map[playerYCoord][playerXCoord - 5];
    displayMap[5][1] = map[playerYCoord][playerXCoord - 4];
    displayMap[5][2] = map[playerYCoord][playerXCoord - 3];
    displayMap[5][3] = map[playerYCoord][playerXCoord - 2];
    displayMap[5][4] = map[playerYCoord][playerXCoord - 1];

    //player row RIGHT of player
    displayMap[5][6] = map[playerYCoord][playerXCoord + 1];
    displayMap[5][7] = map[playerYCoord][playerXCoord + 2];
    displayMap[5][8] = map[playerYCoord][playerXCoord + 3];
    displayMap[5][9] = map[playerYCoord][playerXCoord + 4];
    displayMap[5][10] = map[playerYCoord][playerXCoord + 5];
}
