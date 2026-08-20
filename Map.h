#pragma once

class Map
{
private:
    char map[80][90];

public:
    Map();
    void loadMap(int floorNum);
    void drawMap();

    char checkMap(int x_coord, int y_coord);

    void updateMap(char symbol, int x_coord, int y_coord);
};
