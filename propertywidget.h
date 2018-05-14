#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H

#include <QWidget>
#include <QJsonDocument>
namespace Ui {
class PropertyWidget;
}

class PropertyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PropertyWidget(QWidget *parent = 0);
    ~PropertyWidget();

private:
    Ui::PropertyWidget *ui;
    QJsonDocument Property;
};

#endif // PROPERTYWIDGET_H
