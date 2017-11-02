#include "maploader.h"

MapLoader::MapLoader()
{

}

void MapLoader::LoadMap(string filename, LocationManager lm)
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
        cout<<locations_[i].ToString()<<endl;
    }
    exit(1);
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

    if(input[0]=="l")
    {
        Location l(input[1]);




        locations_.push_back(l);
    }
    else if(input[0]=="o")
    {
        Object *o = new Object(input[1]);





        locations_.back().AddObject(o);
    }
    else if(input[0]=="d")
    {
        Door *d = new Door(input[1],input[2]);





        locations_.back().AddObject(d);
    }
}
