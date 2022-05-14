#include "addgraphdialog.h"
#include "ui_addgraphdialog.h"
#include "pch.h"
#include <iostream>

AddGraphDialog::AddGraphDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddGraphDialog)
{
  ui->setupUi(this);
  ui->numEdit->setValidator(new QIntValidator(1, 100, this));
}

void AddGraphDialog::accept()
{
  if (ui->numEdit->text().isEmpty())
    return;
  num = ui->numEdit->text();
  QDialog::accept();
}

QString AddGraphDialog::getNum()
{
  return num;
}

QMap<float, float> AddGraphDialog::genMap()
{
  QMap<float, float> points;
  bool ok;
  float x, y;

  for (int i = 0; i < num.toInt(&ok); i++)
    {
      x = float(arc4random());
      y = float(arc4random());
      points.insert(x, y);
      std::cout << "[" << i << "] " << x << ": " << y << std::endl;
    }
  return points;
}

QString AddGraphDialog::getKey()
{
  QMap<float, float>::const_iterator i = AddGraphDialog::genMap().begin();
  return QString::number(i.key());
}

QString AddGraphDialog::getValue()
{
  QMap<float, float>::const_iterator i = AddGraphDialog::genMap().begin();
  return QString::number(i.value());
}

AddGraphDialog::~AddGraphDialog()
{
  delete ui;
}

