#include "addgraphdialog.h"
#include "ui_addgraphdialog.h"
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

AddGraphDialog::AddGraphDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddGraphDialog), val1(1, 100, this),
  val2(QRegularExpression{"[a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9]"})
{
  ui->setupUi(this);
  ui->comboBox->addItem("Выберите цвет...", 0);
  ui->comboBox->addItem("Синий", 1);
  ui->comboBox->addItem("Красный", 2);
  ui->comboBox->addItem("Зелёный", 3);
  ui->comboBox->addItem("Жёлтый", 4);
  ui->comboBox->addItem("Фиолетовый", 5);
  ui->comboBox->addItem("Чёрный", 6);
  ui->numEdit->setValidator(&val1);
  ui->colorEdit->setValidator(&val2);
  ui->colorEdit->setPlaceholderText("Введите HEX-код...");

  connect(ui->colorEdit, &QLineEdit::textChanged,
          this, &AddGraphDialog::blockBox);

  connect(ui->comboBox, &QComboBox::currentIndexChanged,
          this, &AddGraphDialog::blockLine);

  connect(ui->comboBox, &QComboBox::currentIndexChanged,
          this, &AddGraphDialog::changed);
}

void AddGraphDialog::blockBox(const QString &t)
{
  if (!t.isEmpty())
    ui->comboBox->setDisabled(true);
  else
    ui->comboBox->setDisabled(false);
}

void AddGraphDialog::blockLine(int t)
{
  if (t != 0)
    ui->colorEdit->setDisabled(true);
  else
    ui->colorEdit->setDisabled(false);
}

void AddGraphDialog::accept()
{
  if (ui->numEdit->text().isEmpty() || (ui->colorEdit->text().isEmpty() && code.isEmpty()))
    return;
  num = ui->numEdit->text().toInt();

  if (code.isEmpty())
    code = ui->colorEdit->text();

  QDialog::accept();
}

void AddGraphDialog::changed(int index)
{
    qDebug() << "index: " << index;

  switch(index)
    {
      case 0:
        code.clear();
        break;
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

QString AddGraphDialog::getColor()
{
  return code;
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
  float a = 12.0;
  int signX, signY;

  for (int i = 0; i < num; i++)
  {
    signX = rand() % 2; signY = rand() % 2;
    signX = signX == 0 ? -1 : 1;
    signY = signY == 0 ? -1 : 1;

    x = float(rand()) / float(RAND_MAX) * a * signX;
    y = float(rand()) / float(RAND_MAX) * a * signY;
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
