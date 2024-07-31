#include "SoundPlayer.h"

#include "MainCore.h"

#include <Windows.h>


SoundPlayer::SoundPlayer(QObject *parent) : QThread(parent)
{
}

void SoundPlayer::run()
{
    QFile file(m_file.toStdString().c_str());
    if (file.open(QIODevice::ReadOnly))
    {
        char* buffer = new char[file.size()];
        file.read(buffer, file.size());
        PlaySoundA(buffer, NULL, SND_MEMORY);
        delete[] buffer;
    }
}
