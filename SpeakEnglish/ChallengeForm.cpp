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
}

void ChallengeForm::Check()
{
    if (index == -1)
    {
        return;
    }
    QString answer = ui->AnswerLineEdit->text();
    if (answer == MainCore::table[index].en)
    {
        right++;
    }
    else
    {
        wrong++;
    }
    emit Step("4444444444");
}
