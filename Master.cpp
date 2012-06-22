#include "Master.h"

#include <QtGui>
#include <QDesktopWidget>
#include <QApplication>

Master::Master(QWidget *parent) :
    GLWidget(0, parent)
{
    remoteRenderArea.resize(QApplication::desktop()->screenCount() - 1);
    for (int i=0; i<remoteRenderArea.size(); i++) {
        remoteRenderArea[i] = new GLWidget(i+1, QApplication::desktop()->screen(i+1));
        remoteRenderArea[i]->showFullScreen();
    }
}

Master::~Master()
{
    foreach(GLWidget* w, remoteRenderArea) {
        delete w;
    }
}

void Master::initializeGL()
{
   GLWidget::initializeGL();

   startTimer(0);
}

void Master::timerEvent(QTimerEvent *)
{
    /* next frame */
    angle += 2.0;

    foreach(GLWidget* w, remoteRenderArea) {
        w->angle = angle;
        w->glDraw();
    }
    glDraw();

    foreach(GLWidget* w, remoteRenderArea) {
        w->swapBuffers();
    }
    swapBuffers();

    /* calc framerate */
    {
        static int t0 = -1;
        static int frames = 0;
        int t = QTime::currentTime().second();

        if (t0 < 0)
            t0 = t;

        frames++;

        if (t - t0 >= 5.0) {
            GLfloat seconds = t - t0;
            GLfloat fps = frames / seconds;
            printf("%d frames in %3.1f seconds = %6.3f FPS\n", frames, seconds, fps);
            t0 = t;
            frames = 0;
        }
    }
}
