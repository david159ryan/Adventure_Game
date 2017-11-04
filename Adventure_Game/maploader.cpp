#include "maploader.h"

MapLoader::MapLoader()
{

}

void MapLoader::LoadMap(string filename)
{
    cout << "MapLoader Started!" << endl;
    string line;
    std::ifstream inFile;
    inFile.open(filename);

    if (!inFile)
    {
        cerr << "Unable to open file "<<filename;
        exit(1);   // call system to stop
    }
    else
    {
        while (std::getline(inFile, line))
        {
            if(line!="")
            {
                ProcessLine(line);
            }
        }
    }
    inFile.close();
    for(int i = 0;i<locations_.size();i++)
    {
        July5::GetInstance().AddLocation(locations_[i]);
    }
    July5::GetInstance().GoToLocation("kitchen");
    cout<<"Map Loaded!"<<endl;
}

std::vector<string> MapLoader::Split(string str,char delimiter)
{
    std::vector<string> result;
    std::stringstream ss(str);
    string temp;
    while(getline(ss, temp, delimiter))
    {
        result.push_back(temp);
    }
    return result;
}

void MapLoader::ProcessLine(string line)
{
    std::vector<string> input = Split(line,',');

    if(input[TAG]=="l")       //Location
    {
        Location* l;
        for(int i=1;i<input.size();i++)
        {
            std::vector<string> c = Split(input[i],':');
            if(c[TAG]=="name")
            {
                l = new Location(c[DESC]);
            }
            locations_.push_back(l);
        }
    }

    else if(input[TAG]=="o")  //Object
    {
        Object *o = new Object("Mysterious Object");
        for(int i=1;i<input.size();i++)
        {
            std::vector<string> c = Split(input[i],':');
            if(c[TAG]=="name")
                o->SetName(c[DESC]);
            else if(c[TAG]=="push")
                o->SetPushString(c[DESC]);
            else if(c[TAG]=="pull")
                o->SetPullString(c[DESC]);
            else if(c[TAG]=="pickup")
                o->SetPickUpString(c[DESC]);
            else if(c[TAG]=="usetarget")
                o->SetUseTargetString(c[DESC]);
            else if(c[TAG]=="use")
                o->SetUseString(c[DESC]);
            else if(c[TAG]=="open")
                o->SetOpenString(c[DESC]);
            else if(c[TAG]=="opentarget")
                o->SetOpenTargetString(c[DESC]);
            else if(c[TAG]=="close")
                o->SetCloseString(c[DESC]);
            else if(c[TAG]=="lick")
                o->SetLickString(c[DESC]);
            else if(c[TAG]=="lookat")
                o->SetLookAtString(c[DESC]);
            else if(c[TAG]=="talk")
                o->SetTalkToString(c[DESC]);
            else if(c[TAG]=="x")
                o->SetX(stoi(c[DESC]));
            else if(c[TAG]=="y")
                o->SetY(stoi(c[DESC]));
            else if(c[TAG]=="tex")
                o->SetTexture(c[DESC]);
        }
        locations_.back()->AddObject(o);
    }

    else if(input[TAG]=="d")  //Door
    {
        Door *d = new Door("Mysterious Door,","???");
        for(int i=1;i<input.size();i++)
        {
            std::vector<string> c = Split(input[i],':');
            if(c[TAG]=="name")
                d->SetName(c[DESC]);
            else if(c[TAG]=="location")
                d->SetLocation(c[DESC]);
            else if(c[TAG]=="key")
                d->SetKey(c[TAG]);
            else if(c[TAG]=="push")
                d->SetPushString(c[DESC]);
            else if(c[TAG]=="pull")
                d->SetPullString(c[DESC]);
            else if(c[TAG]=="pickup")
                d->SetPickUpString(c[DESC]);
            else if(c[TAG]=="usetarget")
                d->SetUseTargetString(c[DESC]);
            else if(c[TAG]=="use")
                d->SetUseString(c[DESC]);
            else if(c[TAG]=="open")
                d->SetOpenString(c[DESC]);
            else if(c[TAG]=="opentarget")
                d->SetOpenTargetString(c[DESC]);
            else if(c[TAG]=="close")
                d->SetCloseString(c[DESC]);
            else if(c[TAG]=="lick")
                d->SetLickString(c[DESC]);
            else if(c[TAG]=="lookat")
                d->SetLookAtString(c[DESC]);
            else if(c[TAG]=="talk")
                d->SetTalkToString(c[DESC]);
            else if(c[TAG]=="x")
                d->SetX(stoi(c[DESC]));
            else if(c[TAG]=="y")
                d->SetY(stoi(c[DESC]));
            else if(c[TAG]=="tex")
                d->SetTexture(c[DESC]);
        }
        locations_.back()->AddObject(d);
    }
}
