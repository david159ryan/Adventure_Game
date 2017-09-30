#ifndef JULY5_H
#define JULY5_H

#include "locationmanager.h"
#include "consoleutilities.h"
#include "object.h"

class July5
{
public:
    July5();
    LocationManager locationManager;

public:
    std::string processCommand(std::string command);
};

#endif // JULY5_H
