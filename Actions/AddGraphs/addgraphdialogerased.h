#ifndef ADDGRAPHDIALOGERASED_H
#define ADDGRAPHDIALOGERASED_H

#include <QDialog>
#include <QMap>
#include <QDoubleValidator>
#include <map>

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

private:
  Ui::AddGraphDialogErased *ui;
  QMap<float, float> map;
  QDoubleValidator val1, val2;

protected:
  void clicked();
};

#endif // ADDGRAPHDIALOGERASED_H
