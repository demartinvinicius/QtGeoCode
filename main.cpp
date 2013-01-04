#include <QCoreApplication>
#include "googlemap.h"
#include <geocodecoreapplication.h>



int main(int argc, char *argv[])
{
    GeoCodeCoreApplication a(argc, argv);
    GoogleMap teste("Rua Jose Zappi, 988");

    
    return a.exec();
}
