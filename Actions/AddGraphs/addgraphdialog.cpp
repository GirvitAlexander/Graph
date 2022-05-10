#include "addgraphdialog.h"
#include "ui_addgraphdialog.h"

AddGraphDialog::AddGraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGraphDialog)
{
    ui->setupUi(this);
}

void AddGraphDialog::accept()
{
  if (ui->numEdit->text().isEmpty())
    return;
  num = ui->numEdit->text();
  close();
}

QString AddGraphDialog::getNum()
{
    return num;
}

QMap<float, float> AddGraphDialog::genMap()
{
    QMap<float, float> points;
    bool ok;
    float x, y, a = 0.5;

    for (int i = 0; i < num.toInt(&ok); i++)
    {
        x = float(arc4random() % 500) / float(RAND_MAX) * a;
        y = float(arc4random() % 500) / float(RAND_MAX) * a;
        points.insert(x, y);
    }
    return points;
}

AddGraphDialog::~AddGraphDialog()
{
    delete ui;
}

