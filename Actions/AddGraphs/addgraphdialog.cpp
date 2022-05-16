#include "addgraphdialog.h"
#include "ui_addgraphdialog.h"
#include "pch.h"
#include <iostream>
#include <ctime>

AddGraphDialog::AddGraphDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddGraphDialog), val(1, 100, this)
{
  ui->setupUi(this);
  ui->numEdit->setValidator(&val);
}

void AddGraphDialog::accept()
{
  if (ui->numEdit->text().isEmpty())
    return;
  num = ui->numEdit->text().toInt();
  QDialog::accept();
}

int AddGraphDialog::getNum()
{
  return num;
}

QMap<float, float> AddGraphDialog::genMap()
{
  QMap<float, float> points;
  srand((unsigned int)time(NULL));
  float x, y;
  float a = 5.0;

  for (int i = 0; i < num; i++)
    {
      x = float(arc4random())/float((RAND_MAX)) * a;
      y = float(arc4random())/float((RAND_MAX)) * a;
      points.insert(x, y);
      std::cout << "[" << i + 1 << "] " << x << ": " << y << std::endl;
    }

  return points;
}

QString AddGraphDialog::getKey()
{
  auto i = AddGraphDialog::genMap().begin();
  return QString::number(i.key());
}

QString AddGraphDialog::getValue()
{
  auto i = AddGraphDialog::genMap().begin();
  return QString::number(i.value());
}

AddGraphDialog::~AddGraphDialog()
{
  delete ui;
}

