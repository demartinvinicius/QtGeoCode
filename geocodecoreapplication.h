#ifndef GEOCODECOREAPPLICATION_H
#define GEOCODECOREAPPLICATION_H

#include <QCoreApplication>
#include <QTextStream>

class GeoCodeCoreApplication : public QCoreApplication
{
    Q_OBJECT
public:
    explicit GeoCodeCoreApplication(int &argc, char **argv);
    
signals:
    
public slots:
    void Decodificado( double latidude, double longitude);
    
};

#endif // GEOCODECOREAPPLICATION_H
