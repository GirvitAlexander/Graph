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

  void addGraph(const QMap<float, float> &map, QString col);
  void addAxesName(const QString &abs, const QString &ord);

private:
  Ui::GraphsPlace *ui;
  QVector<QMap<float, float>> graphs;
  QVector<QColor> colors;

  int x_0, y_0;  //center
  float measure;
  float scale;
  bool axesOn = true, gridOn = true;
  QPainter paint;
  QColor color;

  void updateCenter();
  void drawAxes();
  void drawGrid();
  void drawGraphs();
  void mouseMoveEvent(QMouseEvent *);
  float convertToScreeenY(float);
  float convertToScreeenX(float);
  float convertToGraphX(float);
  float convertToGraphY(float);
public slots:
  void changeAxes(int);
  void changeGrid(int);
protected:
  void paintEvent(QPaintEvent *);
  void resizeEvent(QResizeEvent *event);
};

#endif // GRAPHSPLACE_H
