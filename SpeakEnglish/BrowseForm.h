#ifndef BROWSEFORM_H
#define BROWSEFORM_H

#include <QWidget>
#include <QXmlStreamReader>

#include "MainCore.h"
#include "UniversalModel.h"

namespace Ui {
class BrowseForm;
}

class BrowseForm : public QWidget
{
    Q_OBJECT

public:
    explicit BrowseForm(QWidget *parent = nullptr);
    ~BrowseForm();
    bool parseFile(QString filePath);
    EnglishWord parseParagraph(QXmlStreamReader *xml);

    UniversalModel m_model;

private:
    Ui::BrowseForm *ui;
};

#endif // BROWSEFORM_H
