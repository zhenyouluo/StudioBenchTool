#include <QtGui>

#include "GLWidget.h"
#include "MainWindow.h"

MainWindow::MainWindow()
    : QMainWindow()
{
    setWindowTitle(tr("Studio Bench Tool"));
    setAttribute(Qt::WA_DeleteOnClose);

    master = new Master(this);
    master->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *centralWidget = new QWidget(this);
    QWidget *rightPanel = new QWidget(this);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(master);
    mainLayout->addWidget(rightPanel);

    QCheckBox *useDisplayListCheckBox = new QCheckBox(tr("Use Display Lists"), rightPanel);
    useDisplayListCheckBox->setChecked(GLWidget::useDisplayLists);
    connect(useDisplayListCheckBox, SIGNAL(clicked(bool)), SLOT(useDisplayListsChanged(bool)));

    QCheckBox *useStereoCheckBox = new QCheckBox(tr("Use Stereo"), rightPanel);
    useStereoCheckBox->setChecked(GLWidget::useStereo);
    connect(useStereoCheckBox, SIGNAL(clicked(bool)), SLOT(useStereoChanged(bool)));

    QVBoxLayout *rightLayout = new QVBoxLayout(rightPanel);
    rightLayout->addWidget(useDisplayListCheckBox, Qt::AlignTop);

    setCentralWidget(centralWidget);
}

void MainWindow::useDisplayListsChanged(bool state)
{
    GLWidget::useDisplayLists = state;
}

void MainWindow::useStereoChanged(bool state)
{
    GLWidget::useStereo = state;
}
