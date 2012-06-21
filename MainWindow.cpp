#include <QtGui>

#include "GLWidget.h"
#include "MainWindow.h"

MainWindow::MainWindow()
{
    setWindowTitle(tr("Studio Bench Tool"));

    glWidget = new GLWidget;

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(glWidget);
    setLayout(mainLayout);
}
