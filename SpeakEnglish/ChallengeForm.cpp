#include "ChallengeForm.h"
#include "ui_ChallengeForm.h"

#include <random>
#include <algorithm>

ChallengeForm::ChallengeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChallengeForm)
{
    ui->setupUi(this);
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
    EnglishWord word = MainCore::table[index];
    ui->questionLineEdit->setText(word.ru);
}

