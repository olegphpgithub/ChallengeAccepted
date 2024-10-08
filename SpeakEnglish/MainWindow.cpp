#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "MainCore.h"
#include "WelcomeForm.h"
#include "BrowseForm.h"
#include "ChallengeForm.h"

#include <QStackedWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionChallengeBegin, SIGNAL(triggered()), this, SLOT(ChallengeBegin()));
    connect(ui->actionChallengeInterrupt, SIGNAL(triggered()), this, SLOT(ChallengeInterrupt()));
    connect(ui->actionOpenFile, SIGNAL(triggered()), this, SLOT(OpenFile()));

    welcomeForm = new WelcomeForm();
    browseForm = new BrowseForm();
    challengeForm = new ChallengeForm();

    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(welcomeForm);
    stackedWidget->addWidget(browseForm);
    stackedWidget->addWidget(challengeForm);

    connect(challengeForm, SIGNAL(Finish()), this, SLOT(Home()));

    setCentralWidget(stackedWidget);

    Welcome();
    UpdateToolbar(ChallengeState::Welcome);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenFile()
{
    QSettings settings("nnrus", "SpeakEnglish");
    QString directory_path = settings.value("path").value<QString>();
    if(directory_path.isNull()) {
        directory_path = QCoreApplication::applicationDirPath();
    }

    QString ssml_file_path = QFileDialog::getOpenFileName(
                this,
                tr("Open SSML File"),
                directory_path,
                tr("SSML Files (*.xml *.ssml)"));

    if (ssml_file_path.isEmpty())
    {
        return;
    }

    settings.setValue("path", ssml_file_path);

    if (!browseForm->parseFile(ssml_file_path))
    {
        QString csMsg(QObject::tr("Failed to open '%1' file"));
        csMsg = csMsg.arg(ssml_file_path);
        QString csTitle("Error");
        QMessageBox msgBox;
        msgBox.critical(nullptr, csTitle, csMsg);
        return;
    }

    stackedWidget->setCurrentWidget(browseForm);
    UpdateToolbar(ChallengeState::Browse);

    QFileInfo fileInfo(ssml_file_path);
    setWindowTitle(fileInfo.fileName());

    MainCore::file = fileInfo;
}

void MainWindow::ChallengeBegin()
{
    stackedWidget->setCurrentWidget(challengeForm);
    challengeForm->Start();
    UpdateToolbar(ChallengeState::Challenge);
}

void MainWindow::ChallengeInterrupt()
{
    challengeForm->Interrupt();
    stackedWidget->setCurrentWidget(browseForm);
    UpdateToolbar(ChallengeState::Browse);
}

void MainWindow::Welcome()
{
    stackedWidget->setCurrentWidget(welcomeForm);
}

void MainWindow::UpdateToolbar(ChallengeState::State state)
{
    if (state == ChallengeState::Welcome)
    {
        ui->actionOpenFile->setEnabled(true);
        ui->actionChallengeBegin->setEnabled(false);
        ui->actionChallengeInterrupt->setEnabled(false);
    }

    if (state == ChallengeState::Browse)
    {
        ui->actionOpenFile->setEnabled(true);
        ui->actionChallengeBegin->setEnabled(true);
        ui->actionChallengeInterrupt->setEnabled(false);
    }

    if (state == ChallengeState::Challenge)
    {
        ui->actionOpenFile->setEnabled(false);
        ui->actionChallengeBegin->setEnabled(false);
        ui->actionChallengeInterrupt->setEnabled(true);
    }
}

void MainWindow::Home()
{
    stackedWidget->setCurrentWidget(browseForm);
    UpdateToolbar(ChallengeState::Browse);
}
