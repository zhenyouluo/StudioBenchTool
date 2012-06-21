#include <QApplication>
#include <QDesktopWidget>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setQuitOnLastWindowClosed (true);

    MainWindow window;
    window.show();

    return app.exec();
}
