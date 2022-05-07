#include <pch.h>
#include "graphsplace.h"
#include "ui_graphsplace.h"

GraphsPlace::GraphsPlace(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::GraphsPlace)
{
  ui->setupUi(this);
  updateCenter();
  scale = 10;
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
  for (int i = 0; ; ++i)
  {
    if (x_0 - i * scale < 0)
      break;

    paint.drawLine(x_0 - i * scale, 0, x_0  - i * scale, height());
  }

  for (int i = 1; ; ++i)
  {
    if (x_0 + i * scale > width())
      break;

    paint.drawLine(x_0 + i * scale, 0, x_0  + i * scale, height());
  }

  for (int i = 0; ; ++i)
  {
    if (y_0 - i * scale < 0)
      break;

    paint.drawLine(0, y_0  - i * scale, width(), y_0  - i * scale);
  }

  for (int i = 1; ; ++i)
  {
    if (y_0 + i * scale > height())
      break;

    paint.drawLine(0, y_0  + i * scale, width(), y_0  + i * scale);
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



