#ifndef MAINCORE_H
#define MAINCORE_H

#include <QObject>
#include <QMap>

class EnglishWord
{
public:
    QString en;
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
signals:

};

#endif // MAINCORE_H
