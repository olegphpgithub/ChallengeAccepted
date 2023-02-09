#include "ChallengeForm.h"
#include "ui_ChallengeForm.h"

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
