#ifndef UPDATEABLE_H
#define UPDATEABLE_H

class Updateable
{
public:
    Updateable();
    ~Updateable();
    void virtual Update(void)=0;
};

#endif // UPDATEABLE_H
