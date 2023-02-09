#include "WelcomeForm.h"
#include "ui_WelcomeForm.h"

WelcomeForm::WelcomeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeForm)
{
    ui->setupUi(this);
}

WelcomeForm::~WelcomeForm()
{
    delete ui;
}
