TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

QT += opengl

# Input
HEADERS += GLWidget.h MainWindow.h \
    Master.h
SOURCES += GLWidget.cpp main.cpp MainWindow.cpp \
    Master.cpp
