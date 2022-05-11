#ifndef ADDGRAPHDIALOG_H
#define ADDGRAPHDIALOG_H

#include <QDialog>

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
  QMap<float, float> genMap();
  QString num;
  QString num2;

private:
  Ui::AddGraphDialog *ui;
 // QString num;
 // QString num2;

protected:
  void accept();
};

#endif // ADDGRAPHDIALOG_H