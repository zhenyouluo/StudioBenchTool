#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVector>

#include "GLWidget.h"

class MainWindow : public GLWidget
{
    Q_OBJECT

public:
    MainWindow();

    ~MainWindow();
protected:
    void initializeGL();
    //void paintGL();
    void timerEvent(QTimerEvent*);
private:

    QVector<GLWidget*> remoteRenderArea;
};

#endif
