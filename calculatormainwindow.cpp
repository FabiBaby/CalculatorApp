#include "calculatormainwindow.h"
#include "./ui_calculatormainwindow.h"

// Constructor for CalculatorMainWindow.
// Constructor for CalculatorMainWindow.
CalculatorMainWindow::CalculatorMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalculatorMainWindow) {
   ui->setupUi(this); // Setting up the user interface.

   // Initialize the current value and operator for calculations.
   currentValue = 0.0;
   currentOperator = '\0';

   // Connect digit buttons to the digitPressed slot.
   // These connections ensure that digitPressed is called when any digit button is clicked.
   connect(ui->pushButton_0, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   // ... similar connections for pushButton_1 to pushButton_9 ...
   connect(ui->pushButton_1, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_2, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_3, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_4, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_5, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_6, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_7, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_8, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);
   connect(ui->pushButton_9, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);

   // Connect decimal button to the digitPressed slot.
   connect(ui->decimalButton, &QPushButton::clicked, this, &CalculatorMainWindow::digitPressed);

   // Connect the '=' button to its slot, after disconnecting any existing connections.
   // This is done to prevent multiple connections which could cause the slot to be called multiple times.
   disconnect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(on_pushButton_equal_clicked()));
   connect(ui->pushButton_equal, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_equal_clicked);

   // Similar connections for the add, subtract, multiply, and divide buttons.
   disconnect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(on_pushButton_add_clicked()));
   connect(ui->pushButton_add, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_add_clicked);
   // ... similar for subtract, multiply, and divide ...

   disconnect(ui->pushButton_subtract, SIGNAL(clicked()), this, SLOT(on_pushButton_subtract_clicked()));
   connect(ui->pushButton_subtract, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_subtract_clicked);

   disconnect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(on_pushButton_multiply_clicked()));
   connect(ui->pushButton_multiply, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_multiply_clicked);

   disconnect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(on_pushButton_divide_clicked()));
   connect(ui->pushButton_divide, &QPushButton::clicked, this, &CalculatorMainWindow::on_pushButton_divide_clicked);

   ui->lineEdit->setText("0");
}

// Destructor of CalculatorMainWindow.
CalculatorMainWindow::~CalculatorMainWindow() {
   delete ui; // Cleans up the UI to free memory.
}

// Slot for handling digit button presses.
void CalculatorMainWindow::digitPressed()
{
   if(ui->lineEdit->text() == "0"){
      ui->lineEdit->clear();
   }

   ui->clearButton->setText("C");

   QPushButton *button = qobject_cast<QPushButton*>(sender());
   if(button){
      // Append the text of the pressed button (a digit) to the lineEdit display.
      ui->lineEdit->setText(ui->lineEdit->text() + button->text());
   }
}


// Slot for handling '=' button click event.
void CalculatorMainWindow::on_pushButton_equal_clicked()
{
   double result = 0.0;
   double num = ui->lineEdit->text().toDouble(); // Get the current number from the display.

   // Perform the operation based on the current operator and update result.
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
      // Check for division by zero error.
      if(num == 0){
         ui->lineEdit->setText("Error");
         return;
      }
      else{
         result = currentValue / num;
      }
   }

   // Set the result to the display.
   ui->lineEdit->setText(QString::number(result));
}

// Slots for handling operation button clicks (add, subtract, multiply, divide).
// These slots store the current value from the display, set the current operator, and clear the display.
void CalculatorMainWindow::on_pushButton_add_clicked()
{
   currentValue = ui->lineEdit->text().toDouble(); // Store current value.
   currentOperator = '+'; // Set operator.
   ui->lineEdit->clear(); // Clear display.
}


void CalculatorMainWindow::on_pushButton_subtract_clicked()
{
   currentValue = ui->lineEdit->text().toDouble();
   currentOperator = '-';
   ui->lineEdit->clear();
}


void CalculatorMainWindow::on_pushButton_multiply_clicked()
{
   currentValue = ui->lineEdit->text().toDouble();
   currentOperator = '*';
   ui->lineEdit->clear();
}


void CalculatorMainWindow::on_pushButton_divide_clicked()
{
   currentValue = ui->lineEdit->text().toDouble();
   currentOperator = '/';
   ui->lineEdit->clear();
}

void CalculatorMainWindow::on_clearButton_clicked()
{
   // If the clear button is AC then it clears everything from the memory
   if(ui->clearButton->text() == "AC"){
      currentValue = 0.0;
      currentOperator = '\0';
      ui->lineEdit->clear();
      ui->clearButton->setText("C");
   }
   // Otherwise if the clear button is C then it clears only the current entry
   else{
      ui->lineEdit->clear();
      ui->clearButton->setText("AC");
      ui->lineEdit->setText("0");
   }
}

