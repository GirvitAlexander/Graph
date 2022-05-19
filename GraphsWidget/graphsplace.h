#ifndef GRAPHSPLACE_H
#define GRAPHSPLACE_H

#include <QWidget>
#include <QPainter>

namespace Ui {
  class GraphsPlace;
}

class GraphsPlace : public QWidget
{
  Q_OBJECT

public:
  explicit GraphsPlace(QWidget *parent = nullptr);
  ~GraphsPlace();

private:
  Ui::GraphsPlace *ui;
  int x_0, y_0;  //center
  int measure;
  float scale;
  bool axesOn = true, gridOn = true;
  QPainter paint;

  void updateCenter();
  void drawAxes();
  void drawGrid();
  float convertToScreeen(float y);

public slots:
  void changeAxes(int);
  void changeGrid(int);
protected:
  void paintEvent(QPaintEvent *);
};

#endif // GRAPHSPLACE_H
