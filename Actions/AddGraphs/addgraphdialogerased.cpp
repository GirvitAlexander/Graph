#include "addgraphdialogerased.h"
#include "ui_addgraphdialogerased.h"
#include "qmap.h"
#include <iostream>
#include <map>

using namespace std;


AddGraphDialogErased::AddGraphDialogErased(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddGraphDialogErased), val1(-100.0, 100.0, 2, this), val2(-100.0, 100.0, 2, this)
{
  ui->setupUi(this);
  ui->ForX->setValidator(&val1);
  ui->ForY->setValidator(&val2);

  connect(ui->addPoint, &QPushButton::clicked, this, &AddGraphDialogErased::clicked);
}

void AddGraphDialogErased::clicked()
{
  if ((ui->ForX->text().isEmpty()) and (ui->ForY->text().isEmpty()))
    return;
  float num, num2;
  num = ui->ForX->text().toFloat();
  num2 = ui->ForY->text().toFloat();

  map.insert(num, num2);

  cout << map[num];

  ui->ForX->clear();
  ui->ForY->clear();

}

QMap<float, float> AddGraphDialogErased::getMap()
{
  return map;
}


AddGraphDialogErased::~AddGraphDialogErased()
{
  delete ui;
}

