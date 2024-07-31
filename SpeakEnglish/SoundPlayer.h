#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>
#include <QThread>
#include <QDebug>

class SoundPlayer : public QThread
{
    Q_OBJECT
public:
    SoundPlayer(QObject *parent = nullptr);
    void run();

    QString m_file;
};

#endif // SOUNDPLAYER_H
