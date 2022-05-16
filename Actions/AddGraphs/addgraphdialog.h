#ifndef ADDGRAPHDIALOG_H
#define ADDGRAPHDIALOG_H

#include <QDialog>
#include <QIntValidator>

namespace Ui {
  class AddGraphDialog;
}

class AddGraphDialog : public QDialog
{
  Q_OBJECT

public:
  explicit AddGraphDialog(QWidget *parent = nullptr);
  ~AddGraphDialog();
  int getNum();
  QMap<float, float> genMap();
  QString getKey();
  QString getValue();

private:
  Ui::AddGraphDialog *ui;
  int num;
  QIntValidator val;

protected:
  void accept();
};

#endif // ADDGRAPHDIALOG_H
