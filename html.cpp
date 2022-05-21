#include "html.h"
#include "ui_html.h"

html::html(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::html), val(QRegularExpression{"[a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9]"})
{
  ui->setupUi(this);
  ui->htmlEdit->setValidator(&val);
}

void html::accept()
{
  if (ui->htmlEdit->text().isEmpty())
    return;
  code = ui->htmlEdit->text();
  QDialog::accept();
}

QString html::getCode()
{
  return code;
}


html::~html()
{
  delete ui;
}
