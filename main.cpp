#include "calculatormainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
   // Initializes the QApplication object.
   // QApplication manages application-wide resources and is necessary for any Qt GUI application.
   // 'argc' and 'argv' are used to handle command line arguments.
   QApplication a(argc, argv);

   // Creates an instance of CalculatorMainWindow.
   // This instance 'w' will be the main window of your application.
   CalculatorMainWindow w;

   // Displays the main window.
   // The 'show' method renders the window on the screen.
   w.show();

   // Enters the main event loop and waits until exit() is called.
   // 'a.exec()' starts Qt's event loop, allowing the application to start processing events.
   // This includes things like button clicks and other user interactions.
   return a.exec();
}
