#-------------------------------------------------
#
# Project created by QtCreator 2015-04-15T15:48:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GCS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    videostab.cpp \
    CMT.cpp \
    form.cpp \
    fastcluster/fastcluster.cpp \
    common.cpp \
    Consensus.cpp \
    Fusion.cpp \
    gui.cpp \
    Matcher.cpp \
    Tracker.cpp \
    cam_settings.cpp

HEADERS  += mainwindow.h \
    player.h \
    videostab.h \
    CMT.h \
    form.h \
    fastcluster/fastcluster.h \
    logging/log.h \
    common.h \
    Consensus.h \
    Fusion.h \
    Matcher.h \
    Tracker.h \
    cam_settings.h

FORMS    += mainwindow.ui \
    form.ui \
    cam_settings.ui

INCLUDEPATH += /usr/local/include \
               /home/shashwat/Downloads/jsoncpp-src-0.6.0-rc2/include/
LIBS += -L/usr/local/libs \
        -L/home/shashwat/Downloads/jsoncpp-src-0.6.0-rc2/libs/linux-gcc-4.8 \
        -ljson_linux-gcc-4.8_libmt \
        -lopencv_core \
        -lopencv_video \
        -lopencv_highgui \
        -lopencv_imgproc \
        -lopencv_features2d \
        -lopencv_nonfree \


OTHER_FILES += \
    ../../Desktop/CAM_Settings
