#ifndef MAINCORE_H
#define MAINCORE_H

#include <QObject>
#include <QMap>
#include <QFileInfo>

class EnglishWord
{
public:
    QString en;
    QString en_audio;
    QString ru;
    QString example;
    QString hint;
};

class MainCore : public QObject
{
    Q_OBJECT
public:
    explicit MainCore(QObject *parent = nullptr);
    static QList<EnglishWord> table;
    static QFileInfo file;
signals:

};

#endif // MAINCORE_H
