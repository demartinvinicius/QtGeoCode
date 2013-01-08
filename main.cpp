#include <QCoreApplication>
#include <QObject>
#include "googlemap.h"
#include <geocodecoreapplication.h>
#include <QTextStream>


int main(int argc, char *argv[])
{

    GeoCodeCoreApplication a(argc, argv);



    
    return a.exec();
}
