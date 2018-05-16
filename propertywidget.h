#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H

#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
namespace Ui {
class PropertyWidget;
}

class PropertyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PropertyWidget(QWidget *parent = 0);
    ~PropertyWidget();
    void loadProperty(QString filename);

private:
    Ui::PropertyWidget *ui;
    QJsonDocument ImgProperty;
    QJsonObject PropertyObject;
    QString settings;
    void DisplayProperty();
};

#endif // PROPERTYWIDGET_H
