#include "geocodecoreapplication.h"

GeoCodeCoreApplication::GeoCodeCoreApplication(int &argc, char **argv) :
    QCoreApplication(argc,argv)
{




}

int GeoCodeCoreApplication::exec() {

    QTextStream qout(stdout);


    ConexaoDB = mysql_init(NULL);


    mysql_real_connect(ConexaoDB,"localhost","root","tqbfjotld","localizacao",3306,NULL,0);



    QString sql("select endereco,ocor_id from ocorrencias where latitude is null or latitude=0");
    mysql_real_query(ConexaoDB,sql.toLatin1(),sql.length());


    Pesquisa = mysql_store_result(ConexaoDB);



    if (mysql_num_rows(Pesquisa)==0) {


        qout << "Nao ha dados para processar" <<endl;
        mysql_free_result(Pesquisa);
        mysql_close(ConexaoDB);
        QCoreApplication::exec();
        return 0;
    }


    linha = mysql_fetch_row(Pesquisa);

    ConexaoGoogle = new GoogleMap;
    connect(ConexaoGoogle,SIGNAL(Decodificado(double,double)),this,SLOT(Decodificado(double,double)));
    ConexaoGoogle->executa(linha[0]);

    QCoreApplication::exec();


    return 0;
}

void GeoCodeCoreApplication::Decodificado(double latidude, double longitude) {

        QTextStream qout(stdout);

        QString sql = QString("update ocorrencias set latitude=%1, longitude=%2 where ocor_id=%3").arg(latidude).arg(longitude).arg(linha[1]);
        qout<<sql<<endl;
        mysql_real_query(ConexaoDB,sql.toLatin1(),sql.length());
        qout << latidude << endl;
        qout << longitude << endl;

        linha = mysql_fetch_row(Pesquisa);
        if (linha) {
            ConexaoGoogle->executa(linha[0]);
        }
        else {
            this->quit();
        }


}
