#pragma once

class Map
{
private:
    char map[80][90];
    int playerXCoord;
    int playerYCoord;
    char displayMap[11][11];
public:
    Map();
    void loadMap(int floorNum);
    void drawMap();

    char checkMap(int x_coord, int y_coord);

    void updateMap(char symbol, int x_coord, int y_coord);

    void setPlayerXCoord(int x);
    void setPlayerYCoord(int y);

    void updateDisplayMap();
};
