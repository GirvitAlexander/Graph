#include "addgraphdialogerased.h"
#include "ui_addgraphdialogerased.h"
#include "qmap.h"
#include <iostream>
#include <map>

using namespace std;


AddGraphDialogErased::AddGraphDialogErased(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddGraphDialogErased), val1(-100.0, 100.0, 2, this), val2(-100.0, 100.0, 2, this),
  val3(QRegularExpression{"[a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9]"})
{
  ui->setupUi(this);
  ui->comboBox->addItem("Выберите цвет...", 0);
  ui->comboBox->addItem("Синий", 1);
  ui->comboBox->addItem("Красный", 2);
  ui->comboBox->addItem("Зелёный", 3);
  ui->comboBox->addItem("Жёлтый", 4);
  ui->comboBox->addItem("Фиолетовый", 5);
  ui->comboBox->addItem("Чёрный", 6);
  ui->ForX->setValidator(&val1);
  ui->ForY->setValidator(&val2);
  ui->colorEdit->setValidator(&val3);
  connect(ui->addPoint, &QPushButton::clicked, this, &AddGraphDialogErased::clicked);
}

void AddGraphDialogErased::clicked()
{
  if ((ui->ForX->text().isEmpty()) || (ui->ForY->text().isEmpty()))
    return;
  float num, num2;
  num = ui->ForX->text().toFloat();
  num2 = ui->ForY->text().toFloat();
  code = ui->colorEdit->text();

  map.insert(num, num2);

  cout << map[num];

  ui->ForX->clear();
  ui->ForY->clear();

}

QMap<float, float> AddGraphDialogErased::getMap()
{
  return map;
}

QString AddGraphDialogErased::getColor()
{
  return code;
}

AddGraphDialogErased::~AddGraphDialogErased()
{
  delete ui;
}

