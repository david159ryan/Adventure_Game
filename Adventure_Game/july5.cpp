#include "july5.h"

July5::July5()
{
//    TEST_MakeSomeItems();
      // Setting up locations

    MapLoader * ml = new MapLoader();
    ml -> LoadMap("map.txt", locationManager);

    Location * newLocation = new Location("kitchen");
    // use newLocation to add objects to the location
    newLocation->AddObject(new Door("door", "hallway"));
    locationManager.AddLocation(*newLocation);

    Location * newLocation2 = new Location("hallway");
    newLocation2->AddObject(new Door("door", "kitchen"));
    locationManager.AddLocation(*newLocation2);

    locationManager.GoToLocation("hallway");
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
