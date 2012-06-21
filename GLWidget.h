#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#ifndef M_PI
#define M_PI 3.14159265
#endif

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(int screen, QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void gear(float inner_radius, float outer_radius, float width, int teeth, float tooth_depth);

    int m_screen;

    float view_rotx, view_roty, view_rotz;
    int gear1, gear2, gear3;
    float angle;

    friend class MainWindow;
};

#endif
