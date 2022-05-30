#ifndef ADDGRAPHDIALOGERASED_H
#define ADDGRAPHDIALOGERASED_H

#include <QDialog>
#include <QMap>
#include <QDoubleValidator>

namespace Ui {
  class AddGraphDialogErased;
}

class AddGraphDialogErased : public QDialog
{
  Q_OBJECT

public:
  explicit AddGraphDialogErased(QWidget *parent = nullptr);
  ~AddGraphDialogErased();
  QMap<float, float> getMap();
  QString getColor();
  void changed(int index);
  void blockBox(const QString &t);
  void blockLine(int t);

private:
  Ui::AddGraphDialogErased *ui;
  QMap<float, float> map;
  QDoubleValidator val1, val2;
  QRegularExpressionValidator val3;
  QString code;

protected:
  void clicked();
  void accept();
};

#endif // ADDGRAPHDIALOGERASED_H
