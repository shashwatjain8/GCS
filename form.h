#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QRubberBand>
#include <QDialog>


namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QDialog *parent = 0);
    QImage img;
        bool scribbling;
        QPoint lastPoint;
        QPoint endPoint;
        QRubberBand *rubberBand;
        QRect myRect;
        QPoint a;
        QPoint b;
        void drawLineTo(const QPoint &endPoin);
    void update();
    ~Form();

protected :
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    //void paintEvent(QPaintEvent *event);



private:
    Ui::Form *ui;
};

#endif // FORM_H
