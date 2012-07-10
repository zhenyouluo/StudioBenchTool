#ifndef MASTER_H
#define MASTER_H

#include <QVector>
#include <QTime>
#include "GLWidget.h"

class Master : public GLWidget
{
    Q_OBJECT
public:
    Master(QWidget *parent = 0);

    ~Master();
protected:
    void initializeGL();
    //void paintGL();
    void timerEvent(QTimerEvent*);
private:
    QVector<GLWidget*> remoteRenderArea;
    QTime time;
};

#endif // MASTER_H
