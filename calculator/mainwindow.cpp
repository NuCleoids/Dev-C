#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->one, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->two, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->three, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->four, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->five, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->six, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->seven, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->eight, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->nine, SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->division, SIGNAL(clicked()),this, SLOT(math_operations()));
    connect(ui->percent, SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->multiply, SIGNAL(clicked()),this, SLOT(math_operations()));
    connect(ui->minus, SIGNAL(clicked()),this, SLOT(math_operations()));
    connect(ui->plus, SIGNAL(clicked()),this, SLOT(math_operations()));

    ui->division->setCheckable(true);
    ui->multiply->setCheckable(true);
    ui->minus->setCheckable(true);
    ui->plus->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
   QPushButton *button = (QPushButton *)sender();
   double all_numbers;
   QString new_label;
   all_numbers = (ui->label->text() + button->text()).toDouble();
   new_label = QString::number(all_numbers, 'g', 15);
   ui->label->setText(new_label);
}


void MainWindow::on_dot_clicked()
{
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text()+ ".");
}

void MainWindow::operations()
{
   QPushButton *button = (QPushButton *)sender();

   double all_numbers;
   QString new_label;

   if(button->text() == "%"){
   all_numbers = (ui->label->text()).toDouble();
   all_numbers = all_numbers * 0.01;
   new_label = QString::number(all_numbers, 'g', 15);
   }
   ui->label->setText(new_label);
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);
}

void MainWindow::on_AC_clicked()
{
    ui->division->setChecked(false);
    ui->multiply->setChecked(false);
    ui->minus->setChecked(false);
    ui->plus->setChecked(false);

    ui->label->setText("0");
}


void MainWindow::on_exactiy_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->label->text().toDouble();

    if(ui->division->isChecked()){
        if(num_second == 0){
            ui->label->setText("0");
        }else{
        labelNumber = num_first  / num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        }
        ui->division->setChecked(false);

    }else if(ui->multiply->isChecked()){
            labelNumber = num_first * num_second;
            new_label = QString::number(labelNumber, 'g', 15);

            ui->label->setText(new_label);
            ui->multiply->setChecked(false);

    }else if(ui->minus->isChecked()){
            labelNumber = num_first - num_second;
            new_label = QString::number(labelNumber, 'g', 15);

            ui->label->setText(new_label);
            ui->minus->setChecked(false);

    }else if(ui->plus->isChecked()){
            labelNumber = num_first + num_second;
            new_label = QString::number(labelNumber, 'g', 15);

            ui->label->setText(new_label);
    }else{
            ui->plus->setChecked(false);
    }
}

