#ifndef PLAYER_H
#define PLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>
#include <videostab.h>
#include <CMT.h>
#include <CMT1.h>
using namespace cv;
using namespace std;
using cmt::CMT;

class Player : public QThread
{    Q_OBJECT

 private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame,frame_1,frame_2;
    int frameRate;
     VideoWriter writer;

    Mat RGBframe;
    QImage img;
     int count;



 signals:
 //Signal to output frame to be displayed
      void processedImage(const QImage &image);
 protected:
     void run();
     void msleep(int ms);
 public:
    //Constructor
       bool stab;
        bool tracking;
        CMT cmt;
        Point2f top;
        Point2f bottom;
        Mat im_gray;
        VideoCapture capture;

    Player(QObject *parent = 0);
    //Destructor
    ~Player();
    //Load a video from memory
    bool loadVideo(string filename);

     fstream file;
    //Play the video
    void Play();
    //Stop the video
    void Stop();
    //check if the player has been stopped
    bool isStopped() const;
};
#endif // VIDEOPLAYER_H
