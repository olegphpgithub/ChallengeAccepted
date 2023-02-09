#include "ChallengeForm.h"
#include "ui_ChallengeForm.h"

#include <random>
#include <algorithm>

ChallengeForm::ChallengeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChallengeForm)
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
    index = 0;
    std::random_shuffle(MainCore::table.begin(), MainCore::table.end());
    Next();
}

void ChallengeForm::Next()
{
    if (index > (MainCore::table.count() + 1))
    {

    }
    if (index == 0)
    {
        EnglishWord word = MainCore::table[index];
        ui->questionLineEdit->setText(word.ru);
    } else
    {
        EnglishWord word = MainCore::table[index];
        ui->questionLineEdit->setText(word.ru);
    }
    index++;
}


