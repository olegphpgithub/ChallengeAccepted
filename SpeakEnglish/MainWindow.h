#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QStackedWidget;
class WelcomeForm;
class ChallengeForm;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ChallengeBegin();
    void Welcome();

private:
    Ui::MainWindow *ui;

    QStackedWidget *stackedWidget;

    ChallengeForm *challengeForm;
    WelcomeForm * welcomeForm;
};
#endif // MAINWINDOW_H
