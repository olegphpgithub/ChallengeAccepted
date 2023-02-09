#ifndef CHALLENGEFORM_H
#define CHALLENGEFORM_H

#include <QWidget>

namespace Ui {
class ChallengeForm;
}

class ChallengeForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChallengeForm(QWidget *parent = nullptr);
    ~ChallengeForm();

private:
    Ui::ChallengeForm *ui;
};

#endif // CHALLENGEFORM_H
