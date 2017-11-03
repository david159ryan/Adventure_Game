#ifndef MAPLOADER_H
#define MAPLOADER_H

#define TAG 0
#define DESC 1

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

#include "locationmanager.h"

#include "location.h"
#include "object.h"
#include "door.h"

class MapLoader
{
public:
    MapLoader();
    void LoadMap(string filename);

private:
    void ProcessLine(string line);
    std::vector<string> Split(string str, char delimiter);
    std::vector<Location> locations_;
};

#endif // MAPLOADER_H
