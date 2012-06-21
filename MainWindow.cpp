#include <QtGui>
#include <QDesktopWidget>

#include "GLWidget.h"
#include "MainWindow.h"

MainWindow::MainWindow()
{
    setWindowTitle(tr("Studio Bench Tool"));
    setAttribute(Qt::WA_DeleteOnClose);

    glWidget = new GLWidget(0, this);

    remoteRenderArea.resize(QApplication::desktop()->screenCount());
    for (int i=1; i<remoteRenderArea.size(); i++) {
        remoteRenderArea[i] = new GLWidget(i, QApplication::desktop()->screen(i));
        remoteRenderArea[i]->showFullScreen();
    }

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(glWidget);
    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    foreach(GLWidget* w, remoteRenderArea) {
        delete w;
    }
}
