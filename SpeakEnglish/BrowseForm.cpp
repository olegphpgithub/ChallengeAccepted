#include "BrowseForm.h"
#include "ui_BrowseForm.h"

#include <QFile>
#include <QXmlStreamReader>

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

bool BrowseForm::parseFile(QString filePath)
{
    QFile* file = new QFile(filePath);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    QXmlStreamReader xml(file);
    return false;
}
