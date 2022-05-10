#include <pch.h>
#include "Actions/AddGraphs/addgraphdialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  connect(ui->newGraphs, &QPushButton::clicked, this, &MainWindow::AddGraphAction);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::AddGraphAction()
{
  AddGraphDialog dialog(this);
  if (dialog.exec() == QDialog::Accepted)
    ui->testNum->setText(dialog.getNum());
}
