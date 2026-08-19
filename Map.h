#pragma once

class Map
{
private:
    char map[10][10];

public:
    Map();
    void loadMap(int floorNum);
    void drawMap();
};