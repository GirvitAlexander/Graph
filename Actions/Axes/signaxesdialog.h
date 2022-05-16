#ifndef SIGNAXESDIALOG_H
#define SIGNAXESDIALOG_H

#include <QDialog>
#include <QString>
#include <QDoubleValidator>

namespace Ui {
  class signAxesDialog;
}

class signAxesDialog : public QDialog
{
  Q_OBJECT

public:
  explicit signAxesDialog(QWidget *parent = nullptr);
  ~signAxesDialog();
  QString getAbs();
  QString getOrd();

private:
  Ui::signAxesDialog *ui;
  QString abs, ord;

protected:
  void accept();
};

#endif // SIGNAXESDIALOG_H
