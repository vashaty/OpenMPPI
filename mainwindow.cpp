#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <omp.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    cores = ui->spinBoxCores->text().toInt();
    N = ui->spinBoxNvalue->text().toInt();

    result = 0;

    omp_set_num_threads(cores);

    qDebug() << cores;

}

