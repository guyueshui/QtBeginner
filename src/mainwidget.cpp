#include <QtWidgets>
#include "mainwidget.h"

// Constructor for main widget
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
   button_ = new QPushButton(tr("Push Me!"));
   textBrowser_ = new QTextBrowser();

   QGridLayout *mainLayout = new QGridLayout;
   mainLayout->addWidget(button_,0,0);
   mainLayout->addWidget(textBrowser_,1,0);
   setLayout(mainLayout);
   setWindowTitle(tr("Connecting buttons to processes.."));

   // connect
   connect(button_, SIGNAL(released()), this, SLOT(onButtonReleased()));
   connect(&process_, SIGNAL(readyReadStandardOutput()), this, SLOT(onCaptureProcessOutput()));
}

// Destructor
MainWidget::~MainWidget()
{
   delete button_;
   delete textBrowser_;
}

void MainWidget::onButtonReleased()
{
    textBrowser_->clear();
    textBrowser_->append(tr("Running command:"));

    process_.setCurrentWriteChannel(QProcess::StandardOutput);
    process_.start("ls", {"-alh", "/home/yychi/Pictures"});
}

void MainWidget::onCaptureProcessOutput()
{
    QProcess* process = qobject_cast<QProcess*>(sender());
    if (process)
        textBrowser_->append(process->readAllStandardOutput());
}
