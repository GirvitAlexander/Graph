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
  ui->comboBox->addItem("Выберите цвет...", 0);
  ui->comboBox->addItem("Синий", 1);
  ui->comboBox->addItem("Красный", 2);
  ui->comboBox->addItem("Зелёный", 3);
  ui->comboBox->addItem("Жёлтый", 4);
  ui->comboBox->addItem("Фиолетовый", 5);
  ui->comboBox->addItem("Чёрный", 6);
  ui->testNum->setText("Здесь будут точки");

  connect(ui->newGraphs, &QPushButton::clicked, this, &MainWindow::AddGraphAction);

  connect(ui->newGraphsErased, &QPushButton::clicked, this, &MainWindow::AddGraphErasedAction);

  connect(ui->htmlButton, &QPushButton::clicked, this, &MainWindow::AddHTMLAction);

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
    ui->graphPlace->addGraph(a);
  }
}

void MainWindow::AddGraphErasedAction()
{
  AddGraphDialogErased dialog(this);
  if (dialog.exec() == QDialog::Accepted)
    ui->graphPlace->addGraph(dialog.getMap());
}

void MainWindow::AddHTMLAction()
{
  html dialog(this);
  if (dialog.exec() == QDialog::Accepted)
    return;
}

void MainWindow::on_comboBox_activated(int index)
{
  switch(index)
    {
      case 1:
        code = "0000ff";
        break;
      case 2:
        code = "ff0000";
        break;
      case 3:
        code = "008000";
        break;
      case 4:
        code = "ffff00";
        break;
      case 5:
        code = "8b00ff";
        break;
      case 6:
        code = "000000";
        break;
    }
}

