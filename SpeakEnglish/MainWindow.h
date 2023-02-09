#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QStackedWidget;
class ChallengeForm;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ChallengeBegin();

private:
    Ui::MainWindow *ui;

    QStackedWidget *stackedWidget;

    ChallengeForm *challengeForm;
};
#endif // MAINWINDOW_H
