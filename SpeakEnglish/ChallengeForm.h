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
    void Check();

public slots:
    void Next();

private:
    Ui::ChallengeForm *ui;
    int index;
    int right;
    int wrong;

signals:
    void Finish();
    void Step(QString status);
};

#endif // CHALLENGEFORM_H
