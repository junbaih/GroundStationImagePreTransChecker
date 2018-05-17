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
    ui->ImgContainer->setGeometry(0,10,800,600);

    ImgContainer->setMaximumSize(800,600);
   // ImgContainer->setMaximumSize(800,this->height());
   // ImgContainer->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    ui->ImgContainer = ImgContainer;
    PropertyContainer = new PropertyWidget(this);
   //PropertyContainer = nullptr;
    ui->PropertyContainer = PropertyContainer;
    ui->PropertyContainer->setGeometry(820,10,PropertyContainer->width(),600);
    qDebug()<<"outer container size"<<ui->ImgContainer->size();
    connect(ui->IEditButton,SIGNAL(clicked()),this,SLOT(ImgEditingEnable()));
    connect(ui->IResetButton,SIGNAL(clicked()),this,SLOT(ImgReset()));
    connect(ui->ISaveButton,SIGNAL(clicked()),this,SLOT(ImgSave()));
    connect(ui->PresetButton,SIGNAL(clicked()),this,SLOT(PropertyReset()));
    connect(ui->PSaveButton,SIGNAL(clicked()),this,SLOT(PropertySave()));
    connect(ui->IEditButton,SIGNAL(clicked()),this,SLOT(ImgEditingEnable()));
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

void ImgReview::PropertyReset()
{
    PropertyContainer->resetProperty();
}

void ImgReview::PropertySave()
{
    PropertyContainer->saveProperty();
}

