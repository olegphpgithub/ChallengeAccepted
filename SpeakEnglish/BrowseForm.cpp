#include "BrowseForm.h"
#include "ui_BrowseForm.h"

BrowseForm::BrowseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BrowseForm)
{
    ui->setupUi(this);
}

BrowseForm::~BrowseForm()
{
    delete ui;
}
