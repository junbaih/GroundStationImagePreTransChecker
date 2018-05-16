#include "imgreview.h"
#include "ui_imgreview.h"
#include <QDebug>
ImgReview::ImgReview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImgReview)
{
    ui->setupUi(this);
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ImgContainer = new ImgWidget(this);
    ImgContainer->setMaximumSize(800,this->height());
   // ImgContainer->setMaximumSize(800,this->height());
   // ImgContainer->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    ui->ImgContainer = ImgContainer;
    PropertyContainer = new PropertyWidget(this);
    ui->PropertyContainer = PropertyContainer;
    ui->PropertyContainer->setGeometry(820,10,PropertyContainer->width(),this->height());
    qDebug()<<"outer container size"<<ui->ImgContainer->size();
    connect(ui->IEditButton,SIGNAL(clicked()),this,SLOT(ImgEditingEnable()));
    connect(ui->IResetButton,SIGNAL(clicked()),this,SLOT(ImgReset()));
    connect(ui->ISaveButton,SIGNAL(clicked()),this,SLOT(ImgSave()));
//    connect(ui->IEditButton,SIGNAL(clicked()),this,SLOT(ImgEditingEnable()));
}

ImgReview::~ImgReview()
{
    delete ui;
}

void ImgReview::ImgEditingEnable()
{
    ImgContainer->setEditMode();
}

void ImgReview::ImgSave()
{
    ImgContainer->ImgSave();
}

void ImgReview::ImgReset()
{
    ImgContainer->UndoEdit();
}

