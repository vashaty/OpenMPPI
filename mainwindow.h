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

private slots:
    void on_pushButton_clicked();

    void on_pushButtonMaxN_clicked();

    void on_pushButtonMaxThreads_clicked();

private:
    Ui::MainWindow *ui;
    double result = 0;
    unsigned short int N = 1000;
    unsigned short int threads = 1;
};
#endif // MAINWINDOW_H
