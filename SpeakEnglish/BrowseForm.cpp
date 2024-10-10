#include "BrowseForm.h"
#include "ui_BrowseForm.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamReader>

#include "UniversalModel.h"

BrowseForm::BrowseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BrowseForm)
{
    ui->setupUi(this);

    ui->tableView->setModel(&m_model);
}

BrowseForm::~BrowseForm()
{
    delete ui;
}

bool BrowseForm::parseFile(QString filePath)
{
    QFile* file = new QFile(filePath);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }

    QList<EnglishWord> list;

    QXmlStreamReader xml(file);

    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement)
        {
            if (xml.name() == "speak")
                continue;
            if (xml.name() == "p")
            {
                EnglishWord word = parseParagraph(&xml);

                if (word.en.isNull() || word.en.isEmpty())
                    continue;

                QFileInfo audio_file(word.en_audio);
                if (!audio_file.isAbsolute())
                {
                    QString path("%1%2%3");
                    path = path.arg(QFileInfo(filePath).absoluteDir().path());
                    path = path.arg(QDir::separator());
                    path = path.arg(audio_file.filePath());
                    audio_file = path;
                    audio_file = audio_file.canonicalFilePath();
                    word.en_audio = audio_file.filePath();
                }

                list.push_back(word);
            }
        }
    }

    if (list.count() != 0)
    {
        m_model.beginResetModel();
        MainCore::table.clear();
        MainCore::table = list;
        m_model.endResetModel();
        return true;
    }

    return false;
}

EnglishWord BrowseForm::parseParagraph(QXmlStreamReader *xml)
{
    EnglishWord eWord;
    if (xml->tokenType() != QXmlStreamReader::StartElement && xml->name() == "p")
        return eWord;

    QXmlStreamAttributes attributes = xml->attributes();
    if (attributes.hasAttribute("ru"))
        eWord.ru = attributes.value("ru").toString();
    xml->readNext();

    while (!(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == "p"))
    {
        if (xml->tokenType() == QXmlStreamReader::StartElement)
        {
            if (xml->name() == "s")
            {
                QXmlStreamAttributes attributes = xml->attributes();
                if (attributes.hasAttribute("meaning"))
                {
                    QString meaning = attributes.value("meaning").toString();
                    if (meaning == "word")
                    {
                        xml->readNext();
                        eWord.en = xml->text().toString();
                    }
                    if (meaning == "example")
                    {
                        xml->readNext();
                        eWord.example = xml->text().toString();
                    }
                }
                if (attributes.hasAttribute("audio"))
                {
                    QString audio = attributes.value("audio").toString();
                    eWord.en_audio = audio;
                }
                if (attributes.hasAttribute("hide"))
                {
                    QString hide = attributes.value("hide").toString();
                    eWord.en_hide = hide;
                }
            }
        }
        xml->readNext();
    }

    QString hint = eWord.example;
    QStringList hide_list;
    if (eWord.en_hide.isEmpty()) {
        hint = hint.replace(eWord.en, QString("<...>"), Qt::CaseInsensitive);
        hide_list.append(eWord.en);
    }
    else {
        hide_list = eWord.en_hide.split("|");
    }

    for(int i = 0; i < hide_list.count(); i++) {
        hint = hint.replace(hide_list[i], QString("<...>"), Qt::CaseInsensitive);
    }
    eWord.hint = hint;

    return eWord;
}
