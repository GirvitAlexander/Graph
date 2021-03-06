#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

public slots:
  void AddGraphAction();
  void AddGraphErasedAction();
  void signAxesAction(bool);

private:
  Ui::MainWindow *ui;
  QString code;
};
#endif // MAINWINDOW_H
