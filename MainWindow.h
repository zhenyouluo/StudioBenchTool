#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "GLWidget.h"
#include "Master.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
private:
    Master *master;
};

#endif
