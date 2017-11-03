#include "july5.h"

July5::July5()
{
    MapLoader ml;
    ml.LoadMap("map.txt");
}

string July5::ProcessCommand(string command)
{
    string result = "";
        if(command=="open door")
        {
            result = locationManager.GetCurrentLocation()->GetObject("door")->Use();
        }
    return result;
}
