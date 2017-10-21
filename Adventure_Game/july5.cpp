#include "july5.h"

July5::July5()
{
    TEST_MakeSomeItems();
      // Setting up locations
    Location * newLocation;
    newLocation = locationManager.AddLocation("kitchen");
    // use newLocation to add objects to the location
    newLocation = locationManager.AddLocation("hallway");
    locationManager.GoToLocation("kitchen");
}

string July5::ProcessCommand(string command)
{
    string result = "";
        if(command=="pick clothing")
        {
            result = "adding clothing";
            playerInventory.AddItem((InventoryObject*)items[4]);
        }
        if(command=="pick watch")
            playerInventory.AddItem((InventoryObject*)items[3]);
        if(command=="pick key")
            playerInventory.AddItem((InventoryObject*)items[1]);
        if(command=="pick knife")
            playerInventory.AddItem((InventoryObject*)items[0]);
        if(command=="showitems")
            result = playerInventory.ToString();
        if(command=="open door")
            result = items[2]->Use();
        if(command=="use key on door")
        {
            Door* x = (Door*)items[2];
            if(x->Unlock((Key*)items[1]))
                result = "The door clicks ominously...";
            result = "It didnt unlock...";
        }
    return result;
}

void July5::TEST_MakeSomeItems()
{
    items = new Object*[5];

    items[0] = new InventoryObject(0,"Rusty Knife",this);

    items[1] = new Key(1,"Rusty Old Key",this,1);

    items[2] = new Door(2,"Heavy Rusty Door",this,0,"hallway");

    items[3] = new InventoryObject(3,"Father's Pocket Watch",this);

    items[4] = new InventoryObject(4,"Clothing",this);
}
