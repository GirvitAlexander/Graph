#include <pch.h>
#include <QLabel>
#include <QFontMetrics>
#include <QPoint>
#include <QToolTip>
#include <QMouseEvent>
#include <QtMath>
#include <cmath>
#include "graphsplace.h"
#include "ui_graphsplace.h"

GraphsPlace::GraphsPlace(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::GraphsPlace)
{
  ui->setupUi(this);
  updateCenter();
  measure = 20;
  scale = 1.0;
}

GraphsPlace::~GraphsPlace()
{
  delete ui;
}

void GraphsPlace::drawAxes()
{
  updateCenter();
  paint.begin(this);
  paint.setRenderHint(QPainter::Antialiasing);
  paint.setPen(QPen(Qt::red, 1, Qt::SolidLine));
  paint.drawLine(x_0, 0, x_0, height()); // x
  paint.drawLine(0, y_0, width(), y_0); // y
  paint.end();
}

void GraphsPlace::mouseMoveEvent(QMouseEvent* event)
{
  float mouseX = event->pos().x();
  float mouseY = event->pos().y();
  ui->debug->move(QPoint(mouseX+10, mouseY+10));
  float x = convertToGraphX(mouseX);
  float y = convertToGraphY(mouseY);
  QString label = "(" + QString::number(x,'f', 2) + " ; " + QString::number(y, 'f', 2) + ")";
  ui->debug->setText(label);
}

void GraphsPlace::drawGrid()
{
  updateCenter();
  paint.begin(this);
  paint.setRenderHint(QPainter::Antialiasing);
  paint.setPen(QPen(Qt::gray, 0.5, Qt::SolidLine));
  QFontMetrics fm = paint.fontMetrics();
  int offset_x = 0, offset_y = fm.height() / 4, offset_minus = fm.horizontalAdvance(QStringLiteral("-"));

  for (int i = 0; ; ++i)
  {
    if (x_0 - i * measure < 0)
      break;

    if (i % 5 == 0)
    {
      offset_x = fm.horizontalAdvance(QString("%1").arg(i / scale)) / 2;
      paint.drawText(x_0 - i * measure - offset_x - offset_minus, y_0, QString("%1").arg(-i / scale));
    }

    paint.drawLine(x_0 - i * measure, 0, x_0  - i * measure, height());
  }

  for (int i = 1; ; ++i)
  {
    if (x_0 + i * measure > width())
      break;

    if (i % 5 == 0)
    {
      offset_x = fm.horizontalAdvance(QString("%1").arg(i / scale)) / 2;
      paint.drawText(x_0 + i * measure - offset_x, y_0, QString("%1").arg(i / scale));
    }

    paint.drawLine(x_0 + i * measure, 0, x_0  + i * measure, height());
  }

  for (int i = 0; ; ++i)
  {
    if (y_0 - i * measure < 0)
      break;

    if (i % 5 == 0 && i != 0)
    {
      offset_x = fm.horizontalAdvance(QString("%1").arg(i / scale)) + 2;
      paint.drawText(x_0 - offset_x, y_0 - i * measure + offset_y, QString("%1").arg(i / scale));
    }

    paint.drawLine(0, y_0  - i * measure, width(), y_0  - i * measure);
  }

  for (int i = 1; ; ++i)
  {
    if (y_0 + i * measure > height())
      break;

    if (i % 5 == 0)
    {
      offset_x = fm.horizontalAdvance(QString("%1").arg(i / scale)) + 2;
      paint.drawText(x_0 - offset_x - offset_minus, y_0 + i * measure  + offset_y, QString("%1").arg(-i / scale));
    }

    paint.drawLine(0, y_0  + i * measure, width(), y_0  + i * measure);
  }

  paint.end();
}

void GraphsPlace::addGraph(const QMap<float, float> &map, QString col)
{
  colors.push_back(col);
  graphs.push_back(map);
  repaint();
}

void GraphsPlace::drawGraphs()
{
  //QColor color;
  //color.setNamedColor("#0000ff");
  updateCenter();

  //auto c = colors.begin();

  for (int i = 0; i < graphs.size(); ++i)
  {
    paint.begin(this);
    paint.setRenderHint(QPainter::Antialiasing);
    paint.setPen(QPen(colors[i], 1.5, Qt::SolidLine));
    auto point_1 = graphs[i].begin();
    auto point_2 = std::next(point_1);

    while (point_2 != graphs[i].end())
    {
       paint.drawLine(convertToScreeenX(point_1.key()), convertToScreeenY(point_1.value()),
                      convertToScreeenX(point_2.key()), convertToScreeenY(point_2.value()));
       ++point_1;
       ++point_2;
    }
       paint.end();
  }

}

void GraphsPlace::updateCenter()
{
  x_0 = width() / 2;
  y_0 = height() / 2;
}

void GraphsPlace::paintEvent(QPaintEvent *)
{
  updateCenter();
  if (gridOn)
    drawGrid();
  if (axesOn)
    drawAxes();
  drawGraphs();
}

void GraphsPlace::resizeEvent(QResizeEvent *event)
{
  if (event->oldSize().width() == -1)
    {
      setSizeIncrement(event->size());
      return;
    }

  if (event->oldSize() != event->size())
    {
      float count = event->oldSize().width() / measure;
      setSizeIncrement(event->size());
      measure = (event->size() - event->oldSize()).width() / count + measure;
      qDebug() << count << " " << measure;

      if (measure >= 40)
        {
          scale = scale * qPow(2, static_cast<int>(measure) / 20 - 1);
          measure = 20 + static_cast<int>(measure) % 20;
          qDebug() << "1";
        }
      if (measure < 20)
        {
          int power;
          if (measure < 0)
            {
              power = 2 + static_cast<int>(-measure) / 20;
              measure = 40 - static_cast<int>(-measure) % 20;
            }
          else
            {
              power = 1;
              measure = 20 + roundf(measure);
            }
          scale = scale / qPow(2, power);
          qDebug() << "2";
        }

      qDebug() << event->size().width() << " " << event->oldSize().width() << " " << measure << " " << scale;
    }
}

float GraphsPlace::convertToGraphX(float x)
{
  return - (x_0 - x) / (measure * scale);
}

float GraphsPlace::convertToGraphY(float y)
{
  return (y_0 - y) / (measure * scale);
}

void GraphsPlace::changeAxes(int check)
{
  axesOn = (check == Qt::Checked);
  repaint();
}

void GraphsPlace::changeGrid(int check)
{
  gridOn = (check == Qt::Checked);
  repaint();
}

float GraphsPlace::convertToScreeenY(float y)
{
  return y_0 - y * measure * scale;
}

float GraphsPlace::convertToScreeenX(float x)
{
  return x_0 + x * measure * scale;
}



