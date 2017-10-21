#ifndef LOCATIONUI_H
#define LOCATIONUI_H
#include "updateable.h"
#include <string>
#include "cliframe.h"
#include <QBoxLayout>
#include <QString>

using namespace std;

class LocationUI : public virtual Updateable
{
public:
    LocationUI(QString title, QHBoxLayout *layout);
    void Update(void);
private:
    CliFrame *frame;
};

#endif // LOCATIONUI_H
