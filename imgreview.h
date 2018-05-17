#ifndef IMGREVIEW_H
#define IMGREVIEW_H

#include <QMainWindow>
#include "ImgWidget.h"
#include "propertywidget.h"
namespace Ui {
class ImgReview;
}

class ImgReview : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImgReview(QWidget *parent = 0);
    ~ImgReview();


private:
    Ui::ImgReview *ui;
    ImgWidget* ImgContainer;
    PropertyWidget* PropertyContainer;

public slots:
    void ImgEditingEnable();
    void ImgSave();
    void ImgReset();
    // void ImgSend();
    // void ImgNext();
    void PropertyReset();
    void PropertySave();
    //void PropertySend();
    //void PropertyNext();
};

#endif // IMGREVIEW_H
