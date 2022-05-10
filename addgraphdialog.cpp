#include "addgraphdialog.h"
#include "ui_addgraphdialog.h"
#include <iostream>

AddGraphDialog::AddGraphDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddGraphDialog)
{
  ui->setupUi(this);
}

void AddGraphDialog::accept()
{
  if ((ui->ForX->text().isEmpty()) and (ui->ForY->text().isEmpty()))
    return;
  num = ui->ForX->text();
  num2 = ui->ForY->text();
  //QMap::genMap()
  QDialog::accept();
}

QString AddGraphDialog::getNum()
{
  return num2;
}


QMap<float, float> AddGraphDialog::genMap()
{
  QMap<float, float> points;
  //bool ok;
  float x, y;
  x = num.toFloat();
  y = num2.toFloat();


  //for (int i = 0; i < num.toInt(&ok); i++)
    //{
      //x = float(arc4random() % 500) / float(RAND_MAX) * a;
      //y = float(arc4random() % 500) / float(RAND_MAX) * a;
      points.insert(x, y);
      std::cout << x << ": " << y << std::endl;
    //}
  return points;
}

AddGraphDialog::~AddGraphDialog()
{
  delete ui;
}

