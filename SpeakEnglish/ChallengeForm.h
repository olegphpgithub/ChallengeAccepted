#ifndef CHALLENGEFORM_H
#define CHALLENGEFORM_H

#include <QWidget>

#include "MainCore.h"

namespace Ui {
class ChallengeForm;
}

class ChallengeForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChallengeForm(QWidget *parent = nullptr);
    ~ChallengeForm();
    void Start();
    void Next();

private:
    Ui::ChallengeForm *ui;
    unsigned int index;
};

#endif // CHALLENGEFORM_H
