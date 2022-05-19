#include <pch.h>
#include <QLabel>
#include <QFontMetrics>
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
      offset_x = fm.horizontalAdvance(QString("%1").arg(i * scale)) / 2;
      paint.drawText(x_0 - i * measure - offset_x - offset_minus, y_0, QString("%1").arg(-i * scale));
    }

    paint.drawLine(x_0 - i * measure, 0, x_0  - i * measure, height());
  }

  for (int i = 1; ; ++i)
  {
    if (x_0 + i * measure > width())
      break;

    if (i % 5 == 0)
    {
      offset_x = fm.horizontalAdvance(QString("%1").arg(i * scale)) / 2;
      paint.drawText(x_0 + i * measure - offset_x, y_0, QString("%1").arg(i * scale));
    }

    paint.drawLine(x_0 + i * measure, 0, x_0  + i * measure, height());
  }

  for (int i = 0; ; ++i)
  {
    if (y_0 - i * measure < 0)
      break;

    if (i % 5 == 0 && i != 0)
    {
      offset_x = fm.horizontalAdvance(QString("%1").arg(i * scale)) + 2;
      paint.drawText(x_0 - offset_x, y_0 - i * measure + offset_y, QString("%1").arg(i * scale));
    }

    paint.drawLine(0, y_0  - i * measure, width(), y_0  - i * measure);
  }

  for (int i = 1; ; ++i)
  {
    if (y_0 + i * measure > height())
      break;

    if (i % 5 == 0)
    {
      offset_x = fm.horizontalAdvance(QString("%1").arg(i * scale)) + 2;
      paint.drawText(x_0 - offset_x - offset_minus, y_0 + i * measure  + offset_y, QString("%1").arg(-i * scale));
    }

    paint.drawLine(0, y_0  + i * measure, width(), y_0  + i * measure);
  }

  paint.end();
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

float GraphsPlace::convertToScreeen(float y) {
  return y_0 - y * measure;
}



