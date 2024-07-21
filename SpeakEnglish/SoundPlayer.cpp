#include "SoundPlayer.h"

#include "MainCore.h"

#include <Windows.h>


SoundPlayer::SoundPlayer(QObject *parent) : QThread(parent)
{
    qDebug() << "SoundPlayer +";
}

void SoundPlayer::run()
{
    PlaySoundA(m_file.toStdString().c_str(), NULL, SND_FILENAME);
}
