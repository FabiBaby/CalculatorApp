#ifndef CALCULATORMAINWINDOW_H
#define CALCULATORMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculatorMainWindow;
}
QT_END_NAMESPACE

class CalculatorMainWindow : public QMainWindow {
   Q_OBJECT

   public:
   CalculatorMainWindow(QWidget *parent = nullptr);
   ~CalculatorMainWindow();

   private slots:
   void digitPressed();

   void on_pushButton_equal_clicked();

   void on_pushButton_add_clicked();

   void on_pushButton_subtract_clicked();

   void on_pushButton_multiply_clicked();

   void on_pushButton_divide_clicked();

   private:
   Ui::CalculatorMainWindow *ui;
   double currentValue;
   char currentOperator;
};
#endif // CALCULATORMAINWINDOW_H
