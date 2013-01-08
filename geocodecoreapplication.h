#ifndef GEOCODECOREAPPLICATION_H
#define GEOCODECOREAPPLICATION_H

#include <QCoreApplication>
#include <QTextStream>
#include "googlemap.h"
#include <mysql/mysql.h>
#include <QString>

class GeoCodeCoreApplication : public QCoreApplication
{
    Q_OBJECT
public:
    explicit GeoCodeCoreApplication(int &argc, char **argv);
    int exec();

signals:
    
public slots:
    void Decodificado( double latidude, double longitude);
private:
    GoogleMap *ConexaoGoogle;
    MYSQL *ConexaoDB;
    MYSQL_RES *Pesquisa;
    MYSQL_ROW linha;




    
};

#endif // GEOCODECOREAPPLICATION_H
