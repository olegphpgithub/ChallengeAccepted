#ifndef BROWSEFORM_H
#define BROWSEFORM_H

#include <QWidget>

namespace Ui {
class BrowseForm;
}

class BrowseForm : public QWidget
{
    Q_OBJECT

public:
    explicit BrowseForm(QWidget *parent = nullptr);
    ~BrowseForm();

private:
    Ui::BrowseForm *ui;
};

#endif // BROWSEFORM_H
