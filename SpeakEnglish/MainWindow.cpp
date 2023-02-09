#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ChallengeForm.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionChallengeBegin, SIGNAL(triggered()), this, SLOT(ChallengeBegin()));

    challengeForm = new ChallengeForm();

    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(challengeForm);

    setCentralWidget(stackedWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChallengeBegin()
{
    stackedWidget->setCurrentWidget(challengeForm);
}
