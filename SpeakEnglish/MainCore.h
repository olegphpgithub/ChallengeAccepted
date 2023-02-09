#ifndef MAINCORE_H
#define MAINCORE_H

#include <QObject>
#include <QMap>

class EnglishWord
{
public:
    QString en;
    QString ru;
    QString sentence;
};

class MainCore : public QObject
{
    Q_OBJECT
public:
    explicit MainCore(QObject *parent = nullptr);
    static QMap<unsigned int, EnglishWord> table;
signals:

};

#endif // MAINCORE_H
