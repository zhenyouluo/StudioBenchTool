#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVector>

class GLWidget;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

    ~MainWindow();
private:
    GLWidget *glWidget;

    QVector<GLWidget*> remoteRenderArea;
};

#endif
