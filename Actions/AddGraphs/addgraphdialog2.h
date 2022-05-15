#ifndef ADDGRAPHDIALOG_H
#define ADDGRAPHDIALOG_H

#include <QDialog>
#include <QMap>
#include <map>

namespace Ui {
  class AddGraphDialog;
}

class AddGraphDialog : public QDialog
{
  Q_OBJECT

public:
  explicit AddGraphDialog(QWidget *parent = nullptr);
  ~AddGraphDialog();
  QString getNum();
  QString num;
  QString num2;

private:
  Ui::AddGraphDialog *ui;


protected:
  void clicked();
};

#endif // ADDGRAPHDIALOG_H
