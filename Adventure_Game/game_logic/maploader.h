#ifndef MAPLOADER_H
#define MAPLOADER_H

#define TAG 0
#define DESC 1

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

#include <QString>
#include <QFile>

#include "location.h"
#include "july5.h"

#include "objects/object.h"
#include "objects/door.h"
#include "objects/inventoryobject.h"
#include "objects/porkers.h"
#include "objects/cookiejar.h"
#include "objects/chicken.h"
#include "objects/gibby.h"
#include "objects/menudoor.h"

class MapLoader
{
public:
    MapLoader();
    void LoadMap(string filename);

private:
    void ProcessChunk(string line);
    std::vector<string> Split(string str, char delimiter);
    std::vector<Location *> locations_;
};

#endif // MAPLOADER_H
