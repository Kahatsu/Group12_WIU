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

    const char* mapLayout[50] =
    {
        "####################.........#......####..........",
        "#oooooooooooooo#ooo#.........#.....#ooo#..........",
        "#oooooooooooooo#ooo################oooo#..........",
        "#oooooooooooooo#ooooooooooooooooooooooo#..........",
        "#oooooooooooooo#ooooooooooooooooooooooo#..........",
        "#oooooooooooooo#ooooooooooooooooooooooo#..........",
        "#oooo######oooo#ooooooooooooooooooooooo#..........",
        "#ooo#......#ooooooooooooooooooooooooooo#..........",
        "#ooo#......#ooooooo#################ooo#..........",
        "#ooo#......#ooooooo#................####..........",
        "#ooo#......#########..............................",
        "#ooo#......#ooooooo#..........##################..",
        "#oooo######oooooooo#..........#oooooooooooooooo#..",
        "#oooooooooooooooooo#..........#oooooooooooooooo#..",
        "#oooooooooooooooooo#..........#oooooooooooooooo#..",
        "#ooooooooooo####ooo#..........#ooo##########ooo#..",
        "#oooo#######...#ooo#..........#oooooooo#...#ooo#..",
        "#ooo#ooooo#....#ooo#..........#oooooooo#...#ooo#..",
        "#ooo#ooMoo#....#ooo#..........#oooooooo#...#ooo#..",
        "#ooo#ooooo#....#ooo#..........######ooo#...#ooo#..",
        "#ooo#ooooo######ooo#...........oooo#ooo#...#ooo#..",
        "#ooo#ooooo#oooooooo#ooooooooooooooo#ooo#...#ooo#..",
        "#ooooooooo#oooooooo#oooooooo########ooo####ooooo##",
        "#ooooooPoo#oooooooo#ooooooo#ooooooo#ooo##ooooooooo",
        "#ooooooooo#oooooooo#oooooo#oooooooo#ooo##ooooooooo",
        "#ooo#ooooo#ooo############ooooooooo#ooo##ooooooooo",
        "#ooo#ooooo#oooooooooooooooooo###ooooooo##ooooooooo",
        "#ooo#ooCoo#ooooooooooooooooo#...#oooooo####ooooo##",
        "#ooo#ooooo#oooooooooooooooo#.....#ooooo#...#ooo#..",
        "#ooo########################.....#######...#ooo#..",
        "#ooo#..............#ooooooo#...............#ooo#..",
        "#ooo#..............#ooooooo##########......#ooo#..",
        "#oooo###############oooooooooooooooo#......#ooo#..",
        "#oooooooo#ooooooooo#oooooooooooooooo#......#ooo#..",
        "#oooooooo#ooooooooo#oooooooooooooooo#......#ooo#..",
        ".####oooo#ooooooooo#ooooooo######ooo#......#ooo#..",
        ".....#ooo#ooooooooo#ooooooo#....#ooo#......#ooo#..",
        ".....#ooo#ooooooooo#####ooo###..#ooo########ooo#..",
        ".....#ooo#ooooooooooooooooooo#..#oooooooooooooo#..",
        ".....#ooo######oooooooooooooo#..#oooooooooooooo#..",
        ".....#ooo#ooooooooooooooooooo#..#oooooooooooooo#..",
        "..####ooo#ooooooooo#####ooo###..################..",
        ".#ooooooo#ooooooooo#ooooooooo#....................",
        ".#ooooooo#ooooooooo#ooooooooo#########...######...",
        ".#ooooooo#ooooooooo#ooooooooooooooooo#...#oooo#...",
        ".#ooo########ooo####ooooooooooooooooo#####oooo#...",
        ".#oooooooooooooooooooooooooooooooooooooooooooo#...",
        ".#ooooooooooooooooooooooooooo#####oooooooooooo#...",
        ".#ooooooooooooooooooooooooooo#ooo#oooooooooooo#...",
        "..############################ooo##############..."
    };

    for (int row = 0; row < 50; row++)
    {
        for (int col = 0; col < 50; col++)
        {
            map[row + 10][col + 10] = mapLayout[row][col];
        }
    }
}



void Map::drawMap()
{
    updateDisplayMap();
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 11; i++) {
        std::cout << "        ";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << "|";
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
            else if (displayMap[i][j] == '.')
            {
                SetConsoleTextAttribute(hConsole, 0);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 8);
            }

            std::cout << displayMap[i][j] << " ";
        }
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << "|" << std::endl;
    }

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
