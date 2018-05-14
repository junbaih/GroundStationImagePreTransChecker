#include "imgreview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImgReview w;
    w.show();

    return a.exec();
}
