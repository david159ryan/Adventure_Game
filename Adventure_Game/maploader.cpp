#include "maploader.h"

MapLoader::MapLoader()
{

}

void MapLoader::LoadMap(string filename)
{
    cout << "MapLoader Started!" << endl;
    string line;
    std::ifstream inFile;
    string chunk;
    std::vector<string> chunks;
    bool read=false;
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
            if(line=="{")
            {
                read=true;
            }
            else if(line=="}")
            {
                read=false;
                chunks.push_back(chunk.substr(0,chunk.length()-1));
                chunk="";
            }
            if(read&&line!="{")
            {
                chunk+=line+"/";
            }
        }
    }
    inFile.close();
    for(size_t i = 0;i<chunks.size();i++)
    {
        ProcessChunk(chunks[i]);
    }
    for(size_t i = 0;i<locations_.size();i++)
    {
        cout<<locations_[i]->GetName()<<endl;
        July5::GetInstance().AddLocation(locations_[i]);
    }
    July5::GetInstance().GoToLocation("livingroom");
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

void MapLoader::ProcessChunk(string chunk)
{
    std::vector<string> input = Split(chunk,'/');
    std::vector<string> type = Split(input[0],':');
    if(type[TAG]=="type")
    {
        if(type[DESC]=="location")
        {
            Location *l = new Location("???");
            for(size_t i=1;i<input.size();i++)
            {
                std::vector<string> line = Split(input[i],':');
                if(line[TAG]=="name")
                    l->SetName(line[DESC]);
            }
            locations_.push_back(l);
        }
        else
        {
            Object *o;
            if(type[DESC]=="object")
                o=new Object("Mysterious Object");
            else if(type[DESC]=="door")
                o=new Door("Mysterious Door","???");
            else if(type[DESC]=="key")
                o=new Key("Mysterious Key");


            for(size_t i=1;i<input.size();i++)
            {
                std::vector<string> line = Split(input[i],':');
                if(line[TAG]=="action")
                {
                    std::vector<string> out = Split(line[DESC],';');
                    //o->yourmethod(out[0],out[1]);
                }
                else if(line[TAG]=="location")
                    ((Door*)o)->SetLocation(line[DESC]);
                else if(line[TAG]=="key")
                    ((Door*)o)->SetKey(line[TAG]);
            }
            locations_.back()->AddObject(o);
        }
    }
}
