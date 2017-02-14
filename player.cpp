#include "player.h"
#include<videostab.h>
Player::Player(QObject *parent)
   : QThread(parent)
{
    stop = true;
    stab=false;
    tracking=false;
    top = Point2f(100,100);
    bottom = Point2f(400,400);
    count = 0;
}


bool Player::loadVideo(string filename)
{
    capture.open(1);
    capture.set(CV_CAP_PROP_FPS , 25);
    capture.read(frame_1);
    writer.open("output.avi",CV_FOURCC('X','V','I','D'),25,frame_1.size());



    cvtColor(frame_1,im_gray,CV_BGR2GRAY);

    //cmt.initialize(im_gray,rect);
    if (capture.isOpened())
    {
        frameRate = (int) capture.get(CV_CAP_PROP_FPS);
        return true;
    }
    else
        return false;
}


void Player::Play()
{
    if (!isRunning()) {
        if (isStopped()){
            stop = false;
        }
        start(LowPriority);

    }
}


void Player::run()
{
     VideoStab stab_1(0);
    int delay = (1000/frameRate);
    while(!stop){
        if (!capture.read(frame_2))
        {
            stop = true;
        }

        if(stab)
          {
            frame=stab_1.stabilize(frame_1,frame_2);
        }
        else
        {
            //stab_1.stabilize(frame_1,frame_2);
            frame = frame_2.clone();
        }

        cvtColor(frame,im_gray,CV_BGR2GRAY);

        if(tracking)
        {
            system("/home/shashwat/Desktop/CppMT/cmt");


            /*
            if(count==0)
            {
                const Rect rect = Rect(100,100,200,200);
                cmt.initialise(im_gray,top,bottom);
                //cmt.initialize(im_gray,rect);
                count++;
            }

            else
             {
            cmt.processFrame(im_gray);

            cv::line(frame, cmt.topLeft, cmt.topRight, cv::Scalar(255,255,255));
            cv::line(frame, cmt.topRight, cmt.bottomRight, cv::Scalar(255,255,255));
            cv::line(frame, cmt.bottomRight, cmt.bottomLeft, cv::Scalar(255,255,255));
            cv::line(frame, cmt.bottomLeft, cmt.topLeft, cv::Scalar(255,255,255));


            /*
            //cmt.consensus.estimate_rotation=true;
            Point2f vertices[4];
            cmt.bb_rot.points(vertices);
            cout<<cmt.bb_rot.center<<"\n";

            for (int i = 0; i < 4; i++)
            {
                cv::line(frame, vertices[i], vertices[(i+1)%4], Scalar(255,0,0));
            }

            for(size_t i = 0; i < cmt.points_active.size(); i++)
            {
                cv::circle(frame, cmt.points_active[i], 2, Scalar(255,0,0));
            }

            }
                */



        }

        //frame_2.copyTo(frame);
        //frame = stab_1.stabilize(frame_1,frame_2);
            if (frame.channels()== 3){
            cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
            img = QImage((const unsigned char*)(RGBframe.data),
                              RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
        }
        else
        {
            img = QImage((const unsigned char*)(frame_2.data),
                                 frame_2.cols,frame_2.rows,QImage::Format_Indexed8);
        }
        frame_2.copyTo(frame_1);
        writer.write(frame);
        emit processedImage(img);
        this->msleep(delay);
    }
}


Player::~Player()
{
    mutex.lock();
    stop = true;
    capture.release();
    condition.wakeOne();
    mutex.unlock();
    file.close();
    wait();
}


void Player::Stop()
{
    stop = true;
}
void Player::msleep(int ms){
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}
bool Player::isStopped() const{
    return this->stop;
}
