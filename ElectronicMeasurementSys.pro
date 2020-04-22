#-------------------------------------------------
#
# Project created by QtCreator 2018-03-15T14:04:53
#
#-------------------------------------------------

QT       += core gui network sql opengl
QT       += datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ElectronicMeasurementSys
TEMPLATE = app

DESTDIR = $$PWD/build/

LIBS+=-lopengl32 -lglu32

SOURCES += main.cpp\
        mainwindow.cpp \
    statusbar.cpp \
    logindlg.cpp \
    usermanagerdlg.cpp \
    configmanagerdlg.cpp \
    argumentmanagerdlg.cpp \
    argumentinfodlg.cpp \
    runtimeconfig.cpp \
    configcmdpacket.cpp \
    forwordcmdpacket.cpp \
    recvuppacket.cpp \
    parsedata.cpp \
    dbinterface.cpp \
    choosetestdlg.cpp \
    userinfodlg.cpp \
    localconfig.cpp \
    recvresolvresult.cpp \
    showrcsdlg.cpp \
    qcustomplot.cpp \
    model/colormap.cpp \
    model/glwidget.cpp \
    playbackdlg.cpp \
    view/graphicsview.cpp \
    pulse/PulseCompressionImage.cpp \
    pulse/ReceivePulseData.cpp \
    pulse/PulseScene.cpp \
    ParaAgument.cpp \
    model/ScatterWidget.cpp \
    SelectPath.cpp \
    aboutdlg.cpp

HEADERS  += mainwindow.h \
    statusbar.h \
    logindlg.h \
    usermanagerdlg.h \
    configmanagerdlg.h \
    argumentmanagerdlg.h \
    argumentinfodlg.h \
    Packet.h \
    runtimeconfig.h \
    configcmdpacket.h \
    forwordcmdpacket.h \
    recvuppacket.h \
    parsedata.h \
    dbinterface.h \
    choosetestdlg.h \
    userinfodlg.h \
    localconfig.h \
    recvresolvresult.h \
    showrcsdlg.h \
    qcustomplot.h \
    model/colormap.h \
    model/glwidget.h \
    playbackdlg.h \
    view/graphicsview.h \
    pulse/PulseCompressionImage.h \
    pulse/ReceivePulseData.h \
    pulse/PulseScene.h \
    ParaAgument.h \
    model/ScatterWidget.h \
    SelectPath.h \
    aboutdlg.h

FORMS    += mainwindow.ui \
    logindlg.ui \
    usermanagerdlg.ui \
    configmanagerdlg.ui \
    argumentmanagerdlg.ui \
    argumentinfodlg.ui \
    choosetestdlg.ui \
    userinfodlg.ui \
    showrcsdlg.ui \
    playbackdlg.ui \
    ParaAgument.ui \
    SelectPath.ui \
    aboutdlg.ui

RESOURCES += \
    res.qrc

RC_FILE = logo.rc

win32:CONFIG(release, debug|release): LIBS += $$PWD/lib/Qt5Ftp.lib
else:win32:CONFIG(debug, debug|release): LIBS += $$PWD/lib/Qt5Ftpd.lib

INCLUDEPATH += $$PWD/include


