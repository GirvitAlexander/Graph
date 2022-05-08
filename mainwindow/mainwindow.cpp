#include <pch.h>
#include "graphswidget/graphsplace.h"
#include "Actions/Axes/signaxesdialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->axesOn, SIGNAL(stateChanged(int)),
          ui->graphPlace, SLOT(changeAxes(int)));

  connect(ui->gridOn, SIGNAL(stateChanged(int)),
          ui->graphPlace, SLOT(changeGrid(int)));

  connect(ui->signAxes, &QPushButton::clicked,
          this, &MainWindow::signAxesAction);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::signAxesAction(bool checked)
{
  signAxesDialog dialog(this);
  dialog.exec();
  ui->abs->setText(dialog.getAbs());
  ui->ord->setText(dialog.getOrd());
}

