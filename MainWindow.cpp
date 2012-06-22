#include <QtGui>

#include "GLWidget.h"
#include "MainWindow.h"

MainWindow::MainWindow()
    : QMainWindow()
{
    setWindowTitle(tr("Studio Bench Tool"));
    setAttribute(Qt::WA_DeleteOnClose);

    master = new Master(this);

    QWidget *centralWidget = new QWidget(this);
    QWidget *rightPanel = new QWidget(this);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(master);
    mainLayout->addWidget(rightPanel);

    QCheckBox *useDisplayListCheckBox = new QCheckBox(tr("Use Display Lists"), rightPanel);
    useDisplayListCheckBox->setChecked(GLWidget::useDisplayLists);

    QVBoxLayout *rightLayout = new QVBoxLayout(rightPanel);
    rightLayout->addWidget(useDisplayListCheckBox, Qt::AlignTop);

    setCentralWidget(centralWidget);
}


