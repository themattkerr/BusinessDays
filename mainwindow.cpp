#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mattcalculations.h"
#include <QDate>

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

void MainWindow::on_pushButton_clicked()
{
   QString text;
    if(isBusinessDay( ui->dateEdit->date(), text ))
       ui->textEdit->setText("Is a Business Day");
   else
       ui->textEdit->setText("NOT A WORKDAY");
   ui->dateEdit_2->setDate(dateBusinessDaysAway(ui->dateEdit->date(),ui->spinBox->value(), text  ));
    ui->textBrowser->setText(text);
}
