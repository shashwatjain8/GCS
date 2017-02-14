#ifndef CAM_SETTINGS_H
#define CAM_SETTINGS_H
#include<QSlider>
#include <QWidget>
#include"fstream"
namespace Ui {
class CAM_Settings;
}

class CAM_Settings : public QWidget
{
    Q_OBJECT

public:
    explicit CAM_Settings(QWidget *parent = 0);
    ~CAM_Settings();

private slots:
    void on_horizontalSlider_2_sliderReleased();
    void on_horizontalSlider_2_actionTriggered(int action);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void setdef();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::CAM_Settings *ui;
    QSlider *horizontalSlider_2;
};

#endif // CAM_SETTINGS_H
