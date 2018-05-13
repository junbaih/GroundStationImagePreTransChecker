#pragma once

#include <QtWidgets/QWidget>
#include "ui_ImgWidget.h"
#include <QtCore>
#include <QImage>
#include <QMouseEvent>
class ImgWidget : public QWidget 
{
	Q_OBJECT

public:
	ImgWidget(QWidget *parent = Q_NULLPTR);
	QImage img,newimg;
	void setEditMode();
	void LoadImg();
	void UndoEdit();
	void ImgSave();
private:
	Ui::imgContainer ui;
	QPoint lastpoint = QPoint(0,0);
	QPoint endpoint = QPoint(0, 0);
	bool EditEnable = true;
	bool MouseHolding = false;
	void CropToFill();
	QSize ContainerSize;
	void ResetFocusPoint();
protected:
	void paintEvent(QPaintEvent* e) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
};
