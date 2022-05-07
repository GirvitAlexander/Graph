#include <pch.h>
#include "graphswidget\graphsplace.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->axesOn, SIGNAL(stateChanged(int)),
            ui->graphPlace, SLOT(changeAxes(int)));
    ui->axesOn->setChecked(true);

    connect(ui->gridOn, SIGNAL(stateChanged(int)),
            ui->graphPlace, SLOT(changeGrid(int)));
    ui->gridOn->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

