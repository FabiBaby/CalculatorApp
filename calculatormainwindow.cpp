#include "calculatormainwindow.h"
#include "./ui_calculatormainwindow.h"

//
CalculatorMainWindow::CalculatorMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalculatorMainWindow) {
   ui->setupUi(this);

   currentValue = 0.0;
   currentOperator = '\0';

   connect(ui->pushButton_0, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_1, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_2, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_3, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_4, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_5, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_6, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_7, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_8, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_9, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);

   disconnect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(on_pushButton_equal_clicked()));
   connect(ui->pushButton_equal, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_equal_clicked);

   // Disconnect potentially connected signals before reconnecting
   disconnect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(on_pushButton_add_clicked()));
   connect(ui->pushButton_add, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_add_clicked);

   disconnect(ui->pushButton_subtract, SIGNAL(clicked()), this, SLOT(on_pushButton_subtract_clicked()));
   connect(ui->pushButton_subtract, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_subtract_clicked);

   disconnect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(on_pushButton_multiply_clicked()));
   connect(ui->pushButton_multiply, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_multiply_clicked);

   disconnect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(on_pushButton_divide_clicked()));
   connect(ui->pushButton_divide, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_divide_clicked);
}

//Destructor
CalculatorMainWindow::~CalculatorMainWindow() { delete ui; }

//Slot that updates the display to show the number pressed
void CalculatorMainWindow::digitPressed()
{
   QPushButton *button = qobject_cast<QPushButton*>(sender());
   if(button){
      //Append the button text to display
      ui->lineEdit->setText(ui->lineEdit->text() + button->text());
   }
}


void CalculatorMainWindow::on_pushButton_equal_clicked()
{
   double result = 0.0;
   double num = ui->lineEdit->text().toDouble();

   if(currentOperator == '+'){
      result = currentValue + num;
   }
   else if(currentOperator == '-'){
      result = currentValue - num;
   }
   else if(currentOperator == '*'){
      result = currentValue * num;
   }
   else if(currentOperator == '/'){
      if(num == 0){
         ui->lineEdit->setText("Error");
         return;
      }
      else{
         result = currentValue / num;
      }
   }

   ui->lineEdit->setText(QString::number(result));
}


void CalculatorMainWindow::on_pushButton_add_clicked()
{
   //Takes the current number on the display and stores to currentValue and converts it to double from a string
   currentValue = ui->lineEdit->text().toDouble();

   currentOperator = '+';

   ui->lineEdit->clear();
}


void CalculatorMainWindow::on_pushButton_subtract_clicked()
{
   //Takes the current number on the display and stores to currentValue and converts it to double from a string
   currentValue = ui->lineEdit->text().toDouble();

   currentOperator = '-';

   ui->lineEdit->clear();
}


void CalculatorMainWindow::on_pushButton_multiply_clicked()
{
   //Takes the current number on the display and stores to currentValue and converts it to double from a string
   currentValue = ui->lineEdit->text().toDouble();

   currentOperator = '*';

   ui->lineEdit->clear();
}


void CalculatorMainWindow::on_pushButton_divide_clicked()
{
   //Takes the current number on the display and stores to currentValue and converts it to double from a string
   currentValue = ui->lineEdit->text().toDouble();

   currentOperator = '/';

   ui->lineEdit->clear();
}

