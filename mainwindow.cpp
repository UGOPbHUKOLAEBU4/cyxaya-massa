#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_resultButton_clicked()
{
    double weight, fatprocent, smt;
    weight = ui->weight_sb->value();
    fatprocent = ui->fat_sb->value();
    fatprocent = fatprocent/100;
    smt = weight - ( weight * fatprocent);
    QString string_smt = QString::number(smt);

    if(ui->weight_sb->value()==0 || ui->fat_sb->value()==0){
        QMessageBox::critical(this,"Ошибка", "Введите все данные!");
    } else {

    if(fatprocent>=0.25){
        QMessageBox::critical(this,"Результат", "Сухая масса тела: " + string_smt + " \nИзбыточное количество жира!");
    } else if(fatprocent>=0.20 && fatprocent<0.25){
        QMessageBox::information(this,"Результат","Сухая масса тела: " + string_smt + " \nПроцент жира близок к норме");
    } else if(fatprocent>0.10 && fatprocent<0.20){
        QMessageBox::information(this,"Результат","Сухая масса тела: " + string_smt + " \nПроцент жира в норме");
    } else if(fatprocent<0.10){
         QMessageBox::critical(this,"Результат", "Сухая масса тела: " + string_smt + " \nНедостаточное количество жира!");
    }
            }

}
