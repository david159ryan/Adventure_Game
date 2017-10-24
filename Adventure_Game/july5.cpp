#include "july5.h"

July5::July5()
{
//    TEST_MakeSomeItems();
      // Setting up locations

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

void July5::TEST_MakeSomeItems()
{
//    items = new Object*[5];

//    items[0] = new InventoryObject(0,"Rusty Knife",this);

//    items[1] = new Key(1,"Rusty Old Key",this,1);

//    items[2] = new Door(2,"Heavy Rusty Door",this,0,"hallway");

//    items[3] = new InventoryObject(3,"Father's Pocket Watch",this);

//    items[4] = new InventoryObject(4,"Clothing",this);
}
