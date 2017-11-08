#include "maploader.h"

MapLoader::MapLoader()
{

}

void MapLoader::LoadMap(string filename)
{
    QString qFileName = QString::fromStdString(filename);
    cout << "MapLoader Started!" << endl;
    string line;
    string chunk;
    std::vector<string> chunks;
    bool read=false;

    QFile file(qFileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cerr << "Unable to open file q"<<filename;
        exit(1);   // call system to stop
    }
    while (!file.atEnd())
    {
        QByteArray qline = file.readLine();
        line = qline.data();
        line=line.substr(0,line.length()-1);
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
        else if(read&&line!="{")
        {
            chunk+=line+"/";
        }
    }
    for(size_t i = 0;i<chunks.size();i++)
    {
        ProcessChunk(chunks[i]);
    }
    for(size_t i = 0;i<locations_.size();i++)
    {
        cout<<locations_[i]->GetName()<<endl;
        July5::GetInstance().AddLocation(locations_[i]);
    }
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
    string tag = type[TAG];
    string desc = type[DESC];

    if(tag=="type")
    {
        if(desc=="location")
        {
            Location *l = new Location("???");
            for(size_t i=1;i<input.size();i++)
            {
                std::vector<string> line = Split(input[i],':');
                if(line[TAG]=="name")
                    l->SetName(line[DESC]);
                //else if(line[TAG]=="music")
                  //  l->SetMusic(line[DESC]);
            }
            locations_.push_back(l);
        }
        else
        {
            Object *o;
            if(desc=="object")
                o=new Object("Mysterious Object");
            else if(desc=="door")
                o=new Door("Mysterious Door","???");
            else if(desc=="key")
                o=new Key("Mysterious Key");
            else if(desc=="porkers")
                o=new Porkers("Porkers");
            else if(desc=="cookiejar")
                o=new CookieJar("Cookie Jar");

            for(size_t i=1;i<input.size();i++)
            {
                std::vector<string> line = Split(input[i],':');
                //All Objects
                if(line[TAG]=="action")
                {
                    std::vector<string> out = Split(line[DESC],';');
                    o->setActionText(out[0],out[1]);
                }
                else if(line[TAG]=="name")
                    o->SetName(line[DESC]);
                else if(line[TAG]=="x")
                    o->SetX(stoi(line[DESC]));
                else if(line[TAG]=="y")
                    o->SetY(stoi(line[DESC]));
                else if(line[TAG]=="tex")
                    o->SetTexture(line[DESC]);
                else if(line[TAG]=="sfx")
                    o->SetSound(line[DESC]);

                //Door specific
                else if(line[TAG]=="location")
                    ((Door*)o)->SetLocation(line[DESC]);
                else if(line[TAG]=="key")
                    ((Door*)o)->SetKey(line[DESC]);
            }
            locations_.back()->AddObject(o);
        }
    }
}
