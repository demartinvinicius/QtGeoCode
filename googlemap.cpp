#include "googlemap.h"

GoogleMap::GoogleMap(QObject *parent) : QObject(parent)
{
    GerenciadorConexao = new QNetworkAccessManager(NULL);

    QNetworkProxy proxy(QNetworkProxy::HttpProxy,"proxy.polici2121amilitar.sp.gov.br",3128,"teste","teste");

   // GerenciadorConexao->setProxy(proxy);

    connect(GerenciadorConexao,SIGNAL(finished(QNetworkReply*)),this,SLOT(RespostaRecebida(QNetworkReply*)));
}

void GoogleMap::executa(QString endereco) {


    QTextStream qout(stdout);

    QUrl uendereco;
    uendereco.setScheme("http");
    uendereco.setHost("maps.googleapis.com");
    uendereco.setPath("/maps/api/geocode/json");

    QUrlQuery qendereco;
    qendereco.addQueryItem("address",QUrl::toPercentEncoding(endereco));
    qendereco.addQueryItem("sensor","false");


    qout << qendereco.query();

    uendereco.setQuery(qendereco);

    GerenciadorConexao->get(QNetworkRequest(uendereco));

}

void GoogleMap::RespostaRecebida(QNetworkReply *resposta) {

    QTextStream qout(stdout);
    if (resposta->error() != QNetworkReply::NoError) {
        qout << resposta->errorString();
        return;
    }
    // qout << resposta->readAll() << endl;

    QJsonDocument dados = QJsonDocument::fromJson(resposta->readAll());
    if (dados.isNull()) {
        qout << "Erro no Processamento Json" << endl;
        resposta->deleteLater();
        return;
    }



    QJsonObject objeto = dados.object();

    if (objeto["status"].toString() != "OK") {
        qout << "Erro na consulta google" << endl;
    }
    else {
        qout << "Consulta Google OK" << endl;
    }



    QJsonArray resultado = objeto["results"].toArray();

    for(int j=0;j<resultado.size();j++) {
        double latitude;
        double longitude;
        QJsonObject item = resultado[j].toObject();
        QJsonObject geometria = item["geometry"].toObject();
        QJsonObject localizacao = geometria["location"].toObject();

        latitude = localizacao["lat"].toDouble();
        longitude = localizacao["lng"].toDouble();

        qout << "latitude=" << latitude << endl;
        qout << "longitude=" << longitude << endl;

        emit( Decodificado(latitude,longitude) );

    }

    resposta->deleteLater();




}
