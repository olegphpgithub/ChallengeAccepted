#include "SoundPlayer.h"

#include "MainCore.h"

#include <Windows.h>

#include <QDir>
#include <QFontInfo>

SoundPlayer::SoundPlayer(QObject *parent) : QThread(parent)
{
    qDebug() << "SoundPlayer +";
}

void SoundPlayer::run()
{
    QFileInfo audio_file(m_file);
    if (!audio_file.isAbsolute())
    {
        QString path("%1%2%3");
        path = path.arg(MainCore::file.absoluteDir().path());
        path = path.arg(QDir::separator());
        path = path.arg(audio_file.filePath());
        audio_file = path;
        audio_file = audio_file.canonicalFilePath();
    }
    PlaySoundA(audio_file.filePath().toStdString().c_str(), NULL, SND_FILENAME);
}
