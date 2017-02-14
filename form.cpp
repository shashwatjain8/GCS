#include "form.h"
#include "ui_form.h"
#include <QtGui>

Form::Form(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    scribbling = false;
}

void Form::update()
{

        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),Qt::KeepAspectRatio, Qt::FastTransformation));

}

void Form::mousePressEvent(QMouseEvent *event)
{
    if(ui->label->underMouse())
    {
            lastPoint = event->pos();
            rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
            rubberBand->show();
    }
}

void Form::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand->setGeometry(QRect(lastPoint, event->pos()).normalized());
}

void Form::mouseReleaseEvent(QMouseEvent *event)
{

    a = mapToGlobal(lastPoint);
    b = event->globalPos();

    a = ui->label->mapFromGlobal(a);
    b = ui->label->mapFromGlobal(b);

    QPixmap OriginalPix(*ui->label->pixmap());
    double sx = ui->label->rect().width();
    double sy = ui->label->rect().height();
    sx = OriginalPix.width() / sx;
    sy = OriginalPix.height() / sy;

    a.setX(a.x() * sx);
    b.setX(b.x() * sx);
    a.setY(a.y() * sy);
    b.setY(b.y() * sy);

    myRect = QRect(a,b);



        rubberBand->hide();

        QPainter painter(&img);
        painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap,
                            Qt::RoundJoin));
        //QRect rect = QRect(lastPoint , endPoint);
        painter.drawRect(myRect);

        //QPixmap OriginalPix(*ui->imageLabel->pixmap());

        /*
        QImage newImage;
        newImage = OriginalPix.toImage();

        QImage copyImage;
        copyImage = copyImage.copy(myRect);
        */

        ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),Qt::KeepAspectRatio, Qt::FastTransformation));
        ui->label->repaint();

        this->hide();
}

/*
void Form::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, img, dirtyRect);
}
*/

void Form::closeEvent(QCloseEvent *event)
{

}

void Form::drawLineTo(const QPoint &endPoin)
{
    /*
    QPainter painter(&img);
    painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    QRect rect = QRect(lastPoint , endPoint);
    painter.drawRect(rect);
    ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),Qt::KeepAspectRatio, Qt::FastTransformation));
    */

    /*
    modified = true;

    int rad = (1 / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
    */

}





Form::~Form()
{
    delete ui;
}
