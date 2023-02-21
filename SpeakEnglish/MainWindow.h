#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QStackedWidget;
class WelcomeForm;
class BrowseForm;
class ChallengeForm;

class ChallengeState
{
public:
    enum State
    {
        Welcome = 0,
        Browse = 1,
        Challenge = 2
    };
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void OpenFile();
    void ChallengeBegin();
    void ChallengeInterrupt();
    void Welcome();
    void UpdateToolbar(ChallengeState::State state);
    void Home();

private:
    Ui::MainWindow *ui;

    QStackedWidget *stackedWidget;

    ChallengeForm *challengeForm;
    WelcomeForm *welcomeForm;
    BrowseForm *browseForm;
};
#endif // MAINWINDOW_H
