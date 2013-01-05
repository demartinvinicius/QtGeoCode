#include "geocodecoreapplication.h"

GeoCodeCoreApplication::GeoCodeCoreApplication(int &argc, char **argv) :
    QCoreApplication(argc,argv)
{
}

void GeoCodeCoreApplication::Decodificado(double latidude, double longitude) {

        QTextStream qout(stdout);

        qout << latidude << endl;


}
