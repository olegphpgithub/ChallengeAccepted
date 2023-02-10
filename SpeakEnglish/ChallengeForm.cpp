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

void ChallengeForm::Next()
{
    Check();

    if ( (right + wrong) == MainCore::table.count() )
    {
        QMessageBox::information(this,
                              tr("Test"),
                              tr("The file name must be specified."),
                              QMessageBox::Ok);
        emit Finish();
        return;
    }

    index++;
    EnglishWord word = MainCore::table[index];
    ui->questionLineEdit->setText(word.ru);
    ui->ExampleLineEdit->setText(word.hint);
}

void ChallengeForm::Check()
{
    ui->WrongLineEdit->clear();
    ui->RightLineEdit->clear();

    if (index == -1)
    {
        return;
    }

    QString answer;
    answer = ui->AnswerLineEdit->text();
    ui->AnswerLineEdit->clear();
    if (answer == MainCore::table[index].en)
    {
        right++;
    }
    else
    {
        wrong++;
        ui->WrongLineEdit->setText(answer);
        QString eeee = ui->WrongLineEdit->text();
        ui->RightLineEdit->setText(MainCore::table[index].en);
    }
    QString result("%1/%2");
    result = result.arg(right).arg(wrong);
    ui->statusLabel->setText(result);
    emit Step(result);
}
