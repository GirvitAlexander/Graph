#include <pch.h>
#include "Actions/AddGraphs/addgraphdialog.h"
#include "Actions/AddGraphs/addgraphdialogerased.h"
#include "GraphsWidget/graphsplace.h"
#include "Actions/Axes/signaxesdialog.h"
#include "html.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->textBrowser->setPlaceholderText("Введите точки, и они появятся здесь...");

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
    ui->abs->setText(QStringLiteral("Абсцисса: ") + dialog.getAbs());
    ui->ord->setText(QStringLiteral("Ордината: ") + dialog.getOrd());
  }
}

void MainWindow::AddGraphAction()
{
  AddGraphDialog dialog(this);
  QString str;
  QString color = "#";

  if (dialog.exec() == QDialog::Accepted)
  {
    if (dialog.getNum() == 0)
      return;
    ui->testNum->setText("Точек: " + QString::number(dialog.getNum()));
    auto a = dialog.genMap();
    auto i = a.begin();
    ui->textBrowser->clear();
    while (i != a.end())
    {
      str = QString::number(i.key()) + ": " + QString::number(i.value()) + "\n";
      ui->textBrowser->append(str);
      ++i;
    }
    color.append(dialog.getColor());
    ui->graphPlace->addGraph(a, color);
  }
}

void MainWindow::AddGraphErasedAction()
{
  QString color = "#";
  QString str;
  AddGraphDialogErased dialog(this);

  if (dialog.exec() == QDialog::Accepted)
    {
      auto map = dialog.getMap();
      if (map.size() == 0) {
        return;
      }
      ui->testNum->setText("Точек: " + QString::number(map.size()));
      auto i = map.begin();
      ui->textBrowser->clear();
      while (i != map.end())
      {
        str = QString::number(i.key()) + ": " + QString::number(i.value()) + "\n";
        ui->textBrowser->append(str);
        ++i;
      }

      color.append(dialog.getColor());
      ui->graphPlace->addGraph(map, color);
    }
}
