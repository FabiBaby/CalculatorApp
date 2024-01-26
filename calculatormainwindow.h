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

   public slots:
   void digitPressed();

   private:
   Ui::CalculatorMainWindow *ui;
};
#endif // CALCULATORMAINWINDOW_H
