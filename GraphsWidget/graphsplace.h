#ifndef GRAPHSPLACE_H
#define GRAPHSPLACE_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QMap>
#include <QPainter>
#include <QToolTip>

namespace Ui {
  class GraphsPlace;
}

class GraphsPlace : public QWidget
{
  Q_OBJECT

public:
  explicit GraphsPlace(QWidget *parent = nullptr);
  ~GraphsPlace();

  void addGraph(const QMap<float, float> &map);

private:
  Ui::GraphsPlace *ui;
  QVector<QMap<float, float>> graphs;

  int x_0, y_0;  //center
  int measure;
  float scale;
  bool axesOn = true, gridOn = true;
  QPainter paint;

  void updateCenter();
  void drawAxes();
  void drawGrid();
  void drawGraphs();
  void mouseMoveEvent(QMouseEvent *);
  float convertToScreeenY(float y);
  float convertToScreeenX(float x);
public slots:
  void changeAxes(int);
  void changeGrid(int);
protected:
  void paintEvent(QPaintEvent *);
};

#endif // GRAPHSPLACE_H
