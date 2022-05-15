#include "addgraphdialog.h"
#include "ui_addgraphdialog.h"
#include "qmap.h"
#include <iostream>
#include <map>

using namespace std;


AddGraphDialog::AddGraphDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddGraphDialog)
{
  ui->setupUi(this);
  connect(ui->addPoint, &QPushButton::clicked, this, &AddGraphDialog::clicked);
}

void AddGraphDialog::clicked()
{
  if ((ui->ForX->text().isEmpty()) and (ui->ForY->text().isEmpty()))
    return;
  num = ui->ForX->text();
  num2 = ui->ForY->text();

  QMap<float, float> map;
  //cout << num << " ///" << num2;

  map.insert(num.toFloat(), num2.toFloat());

  cout << map[num.toFloat()];

  ui->ForX->clear();
  ui->ForY->clear();

}

QString AddGraphDialog::getNum()
{
  return 0;
}


AddGraphDialog::~AddGraphDialog()
{
  delete ui;
}

