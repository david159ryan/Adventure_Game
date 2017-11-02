#ifndef MAPLOADER_H
#define MAPLOADER_H

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
    void LoadMap(string filename, LocationManager lm);

private:
    void ProcessLine(string line);
    std::vector<string> Split(string str, char delimiter);

    std::vector<Location> locations_;
    LocationManager lm_;

};

#endif // MAPLOADER_H
