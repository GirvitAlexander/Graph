#include <pch.h>
#include "Actions/AddGraphs/addgraphdialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->testNum->setText("Здесь будут точки");
  connect(ui->newGraphs, &QPushButton::clicked, this, &MainWindow::AddGraphAction);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::AddGraphAction()
{
  AddGraphDialog dialog(this);
  QString str;
  if (dialog.exec() == QDialog::Accepted)
    {
      ui->testNum->setText("Точек: " + QString::number(dialog.getNum()));
      auto a = dialog.genMap();
      auto i = a.begin();
      while (i != a.end())
        {
          str = QString::number(i.key()) + ": " + QString::number(i.value()) + "\n";
          ui->textBrowser->append(str);
          ++i;
        }
    }
}
