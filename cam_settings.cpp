#include "cam_settings.h"
#include "ui_cam_settings.h"
#include"fstream"
int ozoom=1,dzoom=1,shut=1,focus=1,iris=1,aperture=1;
using namespace std;
CAM_Settings::CAM_Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CAM_Settings)
{
    ui->setupUi(this);
    setdef();
    horizontalSlider_2=new QSlider();
    //connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->label_17, SLOT(setValue(int)));
}
void CAM_Settings::setdef()
{
    ofstream zoom;
    zoom.open("/home/shashwat/Downloads/pyftpdlib-1.4.0/demo/camset.json");
    zoom<<"{\"Cam_set\":[{\"ozoom\":"<<ozoom<<",\"dzoom\":"<<dzoom<<",\"shut\":"<<shut<<",\"focus\":"<<focus<<",\"iris\":"<<iris<<",\"aperture\":"<<aperture<<"}]}";
    zoom.close();
}

CAM_Settings::~CAM_Settings()
{
    delete ui;
}

void CAM_Settings::on_horizontalSlider_2_sliderReleased()
{
    int  x =horizontalSlider_2->value();
    fstream f;
    f.open("/home/shashwat/Desktop/aa.txt");
    f<<x;
    f.close();
}

void CAM_Settings::on_horizontalSlider_2_actionTriggered(int action)
{
    ui->label_17->setText(QString::number(horizontalSlider_2->value()));

}

void CAM_Settings::on_pushButton_clicked()
{
    if(ozoom!=36)
    {
        ozoom++;
        ofstream zoom;
         zoom.open("/home/shashwat/Downloads/pyftpdlib-1.4.0/demo/camset.json");
        zoom<<"{\"Cam_set\":[{\"ozoom\":"<<ozoom<<",\"dzoom\":"<<dzoom<<",\"shut\":"<<shut<<",\"focus\":"<<focus<<",\"iris\":"<<iris<<",\"aperture\":"<<aperture<<"}]}";
        zoom.close();
        ui->label_12->setText(QString::number(ozoom)+"x");
    }

}

void CAM_Settings::on_pushButton_2_clicked()
{
    if(ozoom!=0)
    {
        ozoom--;
        ofstream zoom;
        zoom.open("/home/shashwat/Desktop/camset.json");
        zoom<<"{\"Cam_set\":[{\"ozoom\":"<<ozoom<<",\"dzoom\":"<<dzoom<<",\"shut\":"<<shut<<",\"focus\":"<<focus<<",\"iris\":"<<iris<<",\"aperture\":"<<aperture<<"}]}";
        zoom.close();
        ui->label_12->setText(QString::number(ozoom)+"x");
    }

}

void CAM_Settings::on_pushButton_4_clicked()
{
    if(dzoom!=12)
    {
        dzoom++;
        ofstream zoom;
        zoom.open("/home/shashwat/Desktop/camset.json");
        zoom<<"{\"Cam_set\":[{\"ozoom\":"<<ozoom<<",\"dzoom\":"<<dzoom<<",\"shut\":"<<shut<<",\"focus\":"<<focus<<",\"iris\":"<<iris<<",\"aperture\":";
        zoom<<aperture<<"}]}";
        zoom.close();
        ui->label_18->setText(QString::number(dzoom)+"x");
    }
}

void CAM_Settings::on_pushButton_3_clicked()
{
    if(dzoom!=0)
    {
        dzoom--;
        ofstream zoom;
        zoom.open("/home/shashwat/Desktop/camset.json");
        zoom<<"{\"Cam_set\":[{\"ozoom\":"<<ozoom<<",\"dzoom\":"<<dzoom<<",\"shut\":"<<shut<<",\"focus\":"<<focus<<",\"iris\":"<<iris<<",\"aperture\":"<<aperture<<"}]}";
        zoom.close();
        ui->label_18->setText(QString::number(dzoom)+"x");
    }
}

void CAM_Settings::on_pushButton_5_clicked()
{

        focus=23;
        ofstream zoom;
        zoom.open("/home/shashwat/Desktop/camset.json");
        zoom<<"{\"Cam_set\":[{\"ozoom\":"<<ozoom<<",\"dzoom\":"<<dzoom<<",\"shut\":"<<shut<<",\"focus\":"<<focus<<",\"iris\":"<<iris<<",\"aperture\":"<<aperture<<"}]}";
        zoom.close();
        ui->label_7->setText("Auto");

}

void CAM_Settings::on_pushButton_6_clicked()
{

        focus=22;
        ofstream zoom;
        zoom.open("/home/shashwat/Desktop/camset.json");
        zoom<<"{\"Cam_set\":[{\"ozoom\":"<<ozoom<<",\"dzoom\":"<<dzoom<<",\"shut\":"<<shut<<",\"focus\":"<<focus<<",\"iris\":"<<iris<<",\"aperture\":"<<aperture<<"}]}";
        zoom.close();
        ui->label_7->setText("Manual");
}
