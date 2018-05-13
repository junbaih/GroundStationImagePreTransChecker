#include "ImgWidget.h"
#include <QPainter>
#include <QMessageBox>
#include <QThread>
ImgWidget::ImgWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//img.load("C:/Users/Houjunbai/Pictures/Donald Trump.jpg");
	ContainerSize = this->size();
	LoadImg();
	// img = img.scaled(ContainerSize);
	newimg = img;
	//img.load("F:/UCI/UAV/Avionics/Object_Detection/cpp_branch/field_image.png");
	//ui.imgContainer->update();
}

void ImgWidget::paintEvent(QPaintEvent* e)
{
	/*
	QSize size = this->size();
	QImage newimg = img.scaled(size);*/
	QPainter p(this);
	p.drawImage(0,0,newimg);
	
	QPen pen(Qt::black,4);
	p.setPen(pen);
	//pen.setWidth(60);
	//pen.setCosmetic(true);
	p.drawRect(QRect(lastpoint,endpoint));
}

void ImgWidget::mousePressEvent(QMouseEvent* event)
{
	//QMessageBox box(this);
	//if (EditEnable)
	//{
	QPainter p(this);
	p.drawRect(50, 50, 100, 100);
		if (event->button() == Qt::LeftButton)
		{
			lastpoint = event->pos();
			MouseHolding = true;
		}
	//}
}

void ImgWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (EditEnable)
	{
		if ((event->buttons() & Qt::LeftButton) && MouseHolding)
		{
			endpoint = event->pos();
			update();
		}
	}
}

void ImgWidget::mouseReleaseEvent(QMouseEvent* event)
{
	//QMessageBox box(this);

	if ( MouseHolding)
	{
		endpoint = event->pos();
		MouseHolding = false;
		update();
		QThread::sleep(2);
		CropToFill();

		/*
		QPainter painter(this);
		QPen pen(Qt::black);
		pen.setWidth(6);
		pen.setCosmetic(true);
		QRect selectArea(lastpoint,endpoint);
		painter.drawRect(selectArea);*/
	}
}

void ImgWidget::setEditMode()
{
	EditEnable = true;
}

void ImgWidget::CropToFill()
{
	newimg = newimg.copy(QRect(lastpoint, endpoint));
	newimg = newimg.scaled(ContainerSize);
	ResetFocusPoint();
	update();
	ImgSave();
}
void ImgWidget::ResetFocusPoint()
{
	lastpoint = QPoint(0, 0);
	endpoint = QPoint(0, 0);
}

void ImgWidget::LoadImg()
{
	img.load("C:/Users/Houjunbai/Pictures/Donald Trump.jpg");
	img = img.scaled(ContainerSize);
}

void ImgWidget::UndoEdit()
{
	newimg = img;
	update();
}		

void ImgWidget::ImgSave()
{
	if (!newimg.save("new_img.jpeg"))
		QMessageBox(QMessageBox::Warning, "image not saved", "image not saved, try again");
}