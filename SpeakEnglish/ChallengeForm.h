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
    void Interrupt();
    void Check();
    void Summarizing();

public slots:
    void Next();

private:
    Ui::ChallengeForm *ui;
    int index;
    int right;
    int wrong;
    void Return();

signals:
    void Finish();
};

#endif // CHALLENGEFORM_H
