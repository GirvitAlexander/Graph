#include <pch.h>
#include "Actions/AddGraphs/addgraphdialog.h"
#include "Actions/AddGraphs/addgraphdialogerased.h"
#include "graphswidget/graphsplace.h"
#include "Actions/Axes/signaxesdialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->testNum->setText("Здесь будут точки");
  connect(ui->newGraphs, &QPushButton::clicked, this, &MainWindow::AddGraphAction);

  connect(ui->newGraphsErased, &QPushButton::clicked, this, &MainWindow::AddGraphErasedAction);

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
  if (dialog.exec() == QDialog::Accepted)
  {
    ui->abs->setText(dialog.getAbs());
    ui->ord->setText(dialog.getOrd());
  }
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

void MainWindow::AddGraphErasedAction()
{
  AddGraphDialogErased dialog(this);
  if (dialog.exec() == QDialog::Accepted)
    return;
}
