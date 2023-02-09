#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "WelcomeForm.h"
#include "BrowseForm.h"
#include "ChallengeForm.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionChallengeBegin, SIGNAL(triggered()), this, SLOT(ChallengeBegin()));
    connect(ui->actionOpenFile, SIGNAL(triggered()), this, SLOT(OpenFile()));

    welcomeForm = new WelcomeForm();
    browseForm = new BrowseForm();
    challengeForm = new ChallengeForm();

    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(welcomeForm);
    stackedWidget->addWidget(browseForm);
    stackedWidget->addWidget(challengeForm);

    setCentralWidget(stackedWidget);

    Welcome();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenFile()
{
    stackedWidget->setCurrentWidget(browseForm);
}

void MainWindow::ChallengeBegin()
{
    stackedWidget->setCurrentWidget(challengeForm);
}

void MainWindow::Welcome()
{
    stackedWidget->setCurrentWidget(welcomeForm);
}
