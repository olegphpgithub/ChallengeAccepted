#ifndef WELCOMEFORM_H
#define WELCOMEFORM_H

#include <QWidget>

namespace Ui {
class WelcomeForm;
}

class WelcomeForm : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeForm(QWidget *parent = nullptr);
    ~WelcomeForm();

private:
    Ui::WelcomeForm *ui;
};

#endif // WELCOMEFORM_H
