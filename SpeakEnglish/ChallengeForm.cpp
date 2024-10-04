#include "ChallengeForm.h"
#include "ui_ChallengeForm.h"

#include "SoundPlayer.h"

#include <ctime>
#include <random>
#include <algorithm>

#include <Windows.h>
#include <Mmsystem.h>

#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

ChallengeForm::ChallengeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChallengeForm),
    index(0), right(0), wrong(0)
{
    ui->setupUi(this);
    connect(ui->AnswerLineEdit, SIGNAL(returnPressed()), this, SLOT(Next()));
    connect(ui->PlayAgainPushButton, SIGNAL(pressed()), this, SLOT(PlayAgain()));
}

ChallengeForm::~ChallengeForm()
{
    delete ui;
}

void ChallengeForm::Start()
{
    index = -1;
    right = 0;
    wrong = 0;
    std::shuffle(MainCore::table.begin(), MainCore::table.end(), std::default_random_engine(std::time(0)));
    Next();
}

void ChallengeForm::Interrupt()
{
    Summarizing();
    emit Finish();
    index = -1;
    right = 0;
    wrong = 0;
}

void ChallengeForm::PlayAgain()
{
    if (SoundPlayer::m_mutex.tryLock()) {
        SoundPlayer::m_mutex.unlock();
        SoundPlayer *sp = new SoundPlayer(this);
        sp->m_file = MainCore::table[index].en_audio;
        sp->start();
        QObject::connect(sp, SIGNAL(finished()), sp, SLOT(deleteLater()));
    }
}

void ChallengeForm::Summarizing()
{
    QString message(QObject::tr("Test completed. Right: %1. Wrong: %2."));
    message = message.arg(right).arg(wrong);
    QMessageBox::information(this,
                          tr("Test"),
                          message,
                          QMessageBox::Ok);
}

void ChallengeForm::Next()
{
    if (ui->AnswerLineEdit->text().isEmpty() && (index > -1)) {
        return;
    }

    ui->WrongLineEdit->clear();
    ui->RightLineEdit->clear();

    if (index == -1) {
        Return();
    } else {
        Check();
    }

    if ( (right + wrong) == MainCore::table.count() )
    {
        Summarizing();
        emit Finish();
        return;
    }

    index++;
    EnglishWord word = MainCore::table[index];
    ui->questionLineEdit->setText(word.ru);
    ui->questionLineEdit->setCursorPosition(0);
    ui->ExampleLineEdit->setText(word.hint);
    ui->ExampleLineEdit->setCursorPosition(0);
    ui->AnswerLineEdit->setFocus();

    SoundPlayer *sp = new SoundPlayer(this);
    sp->m_file = word.en_audio;
    sp->start();
    QObject::connect(sp, SIGNAL(finished()), sp, SLOT(deleteLater()));
}

void ChallengeForm::Check()
{
    DisableInterface();

    QString answer = ui->AnswerLineEdit->text();

    if (QString::compare(answer, MainCore::table[index].en, Qt::CaseInsensitive) == 0)
    {
        right++;
        EnableInterface();
    }
    else
    {
        wrong++;
        ui->WrongLineEdit->setText(answer);
        ui->WrongLineEdit->setCursorPosition(0);
        ui->RightLineEdit->setText(MainCore::table[index].en);
        ui->RightLineEdit->setCursorPosition(0);

        SoundPlayer *sp = new SoundPlayer(this);
        sp->m_file = ":/res/wav/Error.wav";
        sp->start();
        QObject::connect(sp, SIGNAL(finished()), sp, SLOT(deleteLater()));
        QObject::connect(sp, SIGNAL(finished()), this, SLOT(EnableInterface()));
    }
    Return();
}

void ChallengeForm::Return()
{
    ui->AnswerLineEdit->clear();
    ui->rightLabel->setText(QString::number(right));
    ui->wrongLabel->setText(QString::number(wrong));
    ui->remainLabel->setText(QString::number(MainCore::table.count() - right - wrong));
    ui->totalLabel->setText(QString::number(MainCore::table.count()));
}

void ChallengeForm::EnableInterface()
{
    ui->AnswerLineEdit->setEnabled(true);
    ui->AnswerLineEdit->setFocus();
}

void ChallengeForm::DisableInterface()
{
    ui->AnswerLineEdit->setEnabled(false);
}
