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
    threads = ui->spinBoxCores->text().toInt();
    N = ui->spinBoxNvalue->text().toInt();

    result = 0;

    omp_set_num_threads(threads);
    qDebug() << omp_get_max_threads();
    #pragma omp parallel for reduction(+: result)
       for (unsigned int i = 0; i < N-1; i++){
            result +=(4/(1+((((double)i+0.5)/(double)N)*(((double)i+0.5)/(double)N))))*(1/(double)N);
       }
    ui->textEditResult->setText(QString::number(result));
}


void MainWindow::on_pushButtonMaxN_clicked()
{
    ui->spinBoxNvalue->setValue(ui->spinBoxNvalue->maximum());
}


void MainWindow::on_pushButtonMaxThreads_clicked()
{
    ui->spinBoxCores->setValue(ui->spinBoxCores->maximum());
}

