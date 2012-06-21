#include <QApplication>
#include <QDesktopWidget>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setQuitOnLastWindowClosed (true);

    MainWindow *window = new MainWindow;
    window->show();

    return app.exec();
}
