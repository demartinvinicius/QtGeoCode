#ifndef GOOGLEMAP_H
#define GOOGLEMAP_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QTextStream>
#include <QUrl>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>

class GoogleMap : QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager *GerenciadorConexao;
public slots:
    void RespostaRecebida( QNetworkReply *resposta );

signals:
    void Decodificado( double latidude, double longitude);

public:
    explicit GoogleMap(QString endereco,QObject *parent = 0);




};

#endif // GOOGLEMAP_H