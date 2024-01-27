#ifndef CALCULATORMAINWINDOW_H
#define CALCULATORMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
    namespace Ui {
   class CalculatorMainWindow;
}
QT_END_NAMESPACE

    // CalculatorMainWindow class derived from QMainWindow.
    // This class defines the main window for the calculator application.
class CalculatorMainWindow : public QMainWindow {
   Q_OBJECT // Macro to use Qt's signal and slot mechanism.

   public:
   // Constructor and Destructor.
   // Constructor initializes the main window with optional parent widget.
   CalculatorMainWindow(QWidget *parent = nullptr);
   ~CalculatorMainWindow(); // Destructor for cleaning up resources.

   private slots:
   // Slot functions for handling button clicks in the UI.
   void digitPressed(); // Handles digit button presses.

   // Slots for handling specific button click events:
   void on_pushButton_equal_clicked(); // Handles '=' button click.
   void on_pushButton_add_clicked(); // Handles '+' button click.
   void on_pushButton_subtract_clicked(); // Handles '-' button click.
   void on_pushButton_multiply_clicked(); // Handles '*' button click.
   void on_pushButton_divide_clicked(); // Handles '/' button click.

   void on_clearButton_clicked();

   private:
   // Pointer to the UI class generated from the .ui file.
   Ui::CalculatorMainWindow *ui;

   // Variables to store the current value and the current operator.
   double currentValue; // Stores the current value entered or calculated.
   char currentOperator; // Stores the last operator entered.
};

#endif // CALCULATORMAINWINDOW_H
