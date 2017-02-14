#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <player.h>
#include <form.h>
#include<QLabel>
#include <cam_settings.h>
#include <json/json.h>
#include <fstream>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //Display video frame in player UI
    void updatePlayerUI(QImage img);
    //Slot for the load video push button.
    // Slot for the play push button.
    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_actionTrack_Object_triggered();

    void on_actionLoad_Video_triggered();

    void on_actionOpen_triggered();

    //void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Player* myPlayer;
    CAM_Settings *cam;
    Form *w;
    QLabel *lab;

    std::ifstream test;

    Json::Value root;

    Json::Reader reader;

    std::string *lat;
    std::string *lon;

    void getData();
    void Json_initialize();
};
#endif // MAINWINDOW_H
