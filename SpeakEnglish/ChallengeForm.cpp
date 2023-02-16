#include "ChallengeForm.h"
#include "ui_ChallengeForm.h"

#include <random>
#include <algorithm>

#include <QMessageBox>

ChallengeForm::ChallengeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChallengeForm),
    index(0), right(0), wrong(0)
{
    ui->setupUi(this);
    connect(ui->AnswerLineEdit, SIGNAL(returnPressed()), this, SLOT(Next()));
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
    std::random_shuffle(MainCore::table.begin(), MainCore::table.end());
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
    Check();

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
}

void ChallengeForm::Check()
{
    ui->WrongLineEdit->clear();
    ui->RightLineEdit->clear();

    if (index == -1)
    {
        Return();
        return;
    }

    QString answer;
    answer = ui->AnswerLineEdit->text();
    if (answer == MainCore::table[index].en)
    {
        right++;
    }
    else
    {
        wrong++;
        ui->WrongLineEdit->setText(answer);
        ui->WrongLineEdit->setCursorPosition(0);
        ui->RightLineEdit->setText(MainCore::table[index].en);
        ui->RightLineEdit->setCursorPosition(0);
    }
    Return();
}

void ChallengeForm::Return()
{
    ui->AnswerLineEdit->clear();
    QString result("%1/%2");
    result = result.arg(right).arg(wrong);
    ui->rightLabel->setText(QString::number(right));
    ui->wrongLabel->setText(QString::number(wrong));
    ui->remainLabel->setText(QString::number(MainCore::table.count() - right - wrong));
    ui->totalLabel->setText(QString::number(MainCore::table.count()));
    emit Step(result);
}
