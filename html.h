#ifndef HTML_H
#define HTML_H

#include <QDialog>
#include <QRegularExpressionValidator>

namespace Ui {
  class html;
}

class html : public QDialog
{
  Q_OBJECT

public:
  explicit html(QWidget *parent = nullptr);
  QString getCode();
  ~html();

private:
  Ui::html *ui;
  QRegularExpressionValidator val;
  QString code;

protected:
  void accept();
};

#endif // HTML_H
