#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class GLWidget;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private:
    GLWidget *glWidget;
};

#endif
