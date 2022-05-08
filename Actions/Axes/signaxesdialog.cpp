#include <pch.h>

#include "signaxesdialog.h"
#include "ui_signaxesdialog.h"

signAxesDialog::signAxesDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::signAxesDialog)
{
  ui->setupUi(this);
}

void signAxesDialog::accept()
{
  if (ui->absLineEdit->text().isEmpty() && ui->ordLineEdit->text().isEmpty())
    return;
  abs = ui->absLineEdit->text();
  ord = ui->ordLineEdit->text();
  close();
}

QString signAxesDialog::getAbs()
{
  return abs;
}

QString signAxesDialog::getOrd()
{
  return ord;
}

signAxesDialog::~signAxesDialog()
{
  delete ui;
}
