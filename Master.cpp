#include "Master.h"

#include <QtGui>
#include <QDesktopWidget>
#include <QApplication>

Master::Master(QWidget *parent) :
    GLWidget(QGLFormat(QGL::NoStereoBuffers), parent)
{
    remoteRenderArea.resize(QApplication::desktop()->screenCount() - 1);
    for (int i=0; i<remoteRenderArea.size(); i++) {
        remoteRenderArea[i] = new GLWidget(QGLFormat(QGL::StereoBuffers), QApplication::desktop()->screen(i+1));
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
   time.start();
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
        w->makeCurrent();
        w->swapBuffers();
    }
    makeCurrent();
    swapBuffers();

    /* calc framerate */
    {
        static int frames = 0;

        frames++;

	float seconds = time.elapsed() / 1000;
        if (seconds >= 5.0) {
            GLfloat fps = frames / seconds;
            printf("%d frames in %3.1f seconds = %6.3f FPS\n", frames, seconds, fps);
            frames = 0;
            time.restart();
        }
    }
}
