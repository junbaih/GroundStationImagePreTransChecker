#include "propertywidget.h"
#include "ui_propertywidget.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
PropertyWidget::PropertyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertyWidget)
{
    ui->setupUi(this);
    loadProperty("test_property.json");
    DisplayProperty();

}

PropertyWidget::~PropertyWidget()
{
    delete ui;
}

void PropertyWidget::loadProperty(QString filename)
{
    QFile file;
    file.setFileName(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    qDebug()<<"opened!";

    QTextStream ReadFile(&file);
    //settings = ReadFile.readAll();
    settings = file.readAll();
    file.close();
    ImgProperty = QJsonDocument::fromJson(settings.toUtf8());
    PropertyObject = ImgProperty.object();
}

void PropertyWidget::DisplayProperty()
{
    QTextDocument* doc = new QTextDocument(settings);
    ui->textEdit->setDocument(doc);
    //ui->textEdit->setText(settings);
    qDebug()<<settings;
}
