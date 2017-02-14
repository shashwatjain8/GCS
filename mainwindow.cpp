#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fstream"
#include <QPushButton>
#include<QLabel>
#include<QPalette>
int val=1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    myPlayer = new Player();
    w = new Form();
    cam = new CAM_Settings();


    QObject::connect(myPlayer, SIGNAL(processedImage(QImage)),
                              this, SLOT(updatePlayerUI(QImage)));
    ui->setupUi(this);
    lat = new std::string("00.0000000");
    lon = new std::string("00.0000000");
}


MainWindow::~MainWindow()
{
    delete ui;
    delete myPlayer;
}
void MainWindow::Json_initialize()
{
    test.open("/home/lakshya/Downloads/pyftpdlib-1.4.0/demo/gps.json" , std::ifstream::binary);

    bool parsedSuccess = reader.parse(test,root,  false);

    if(not parsedSuccess)

    {

    // Report failures and their locations

    // in the document.

    std::cout<<"Failed to parse JSON"<<std::endl

    <<reader.getFormatedErrorMessages()

    <<std::endl;

    }
    test.close();
}


void MainWindow::updatePlayerUI(QImage img)
{
    if (!img.isNull())
    {
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),Qt::KeepAspectRatio, Qt::FastTransformation));
        w->img = img;
        this->Json_initialize();
        this->getData();
        ui->label_4->setText(QString::fromUtf8(lon->c_str()));
        ui->label_6->setText(QString::fromUtf8(lat->c_str()));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (myPlayer->isStopped())
    {
        myPlayer->Play();
        ui->pushButton_2->setText(tr("Stop"));
    }else
    {
        myPlayer->Stop();
        ui->pushButton_2->setText(tr("Play"));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(val!=10)
    {
        val++;
        ofstream zoom;
        zoom.open("/home/shashwat/Desktop/zoom.json");
        zoom<<"{\"zoom\": [{\"value\": ";
        zoom<<val;
        zoom<<"}]}";
        zoom.close();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(val!=1)
       {
            val--;
            ofstream zoom;
            zoom.open("/home/shashwat/Desktop/zoom.json");
            zoom<<"{\"zoom\": [{\"value\": ";
            zoom<<val;
            zoom<<"}]}";
            zoom.close();
       }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(!myPlayer->stab)
    {
        myPlayer->stab=true;
    }
    else
        myPlayer->stab=false;
}
void MainWindow::on_actionTrack_Object_triggered()
{
    if(!myPlayer->tracking)
    {
        myPlayer->tracking = true;
        myPlayer->Stop();
        myPlayer->capture.release();
    }
    else
        myPlayer->tracking=false;
}

void MainWindow::on_actionLoad_Video_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                          tr("Open Video"), ".",
                                          tr("Video Files (*.avi *.mpg *.mp4)"));
    if (!filename.isEmpty()){
        myPlayer->loadVideo(filename.toStdString());
        /*
        if (!myPlayer->loadVideo(filename.toAscii().data()))
        {
            QMessageBox msgBox;
            msgBox.setText("The selected video could not be opened!");
            msgBox.exec();
        }
*/
    }
}

void MainWindow::on_actionOpen_triggered()
{
    cam->show();
}

void MainWindow::getData()
{
    const Json::Value gps1 = root["Lat"];

    const Json::Value gps2 = root["Lon"];

    const Json::Value timestamp = root["TimeStamp"];

    *lat = gps1.asString();
    *lon = gps2.asString();
}
