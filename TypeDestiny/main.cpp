#include "mainwindow.h"
#include <QApplication>
#include <QObject>

/*********************************************
SOURCES:
~Documentation of QT
http://doc.qt.io/

~Delay function used in most of the program
http://stackoverflow.com/questions/3752742/how-do-i-create-a-pause-wait-function-using-qt
**********************************************/

/*int main makes use of arguments c and v
 * from looking online, argc and argv can be accessed with QCoreApplication::arguments()
 * argc is the number of strings pointed to by argv
 *
 * Pre   : .exe is started and program builds
 * Param : argc (argument count) and argv(argument vector)
 * Return: list of command line arguments
 * Post  : a is executed, MainWindow is shown
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow b; ///refers to the mainwindow.ui
    b.show(); ///shows the mainwindow.ui and makes it accessible for use

    return a.exec();
}//end function main
