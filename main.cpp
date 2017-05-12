/** Author : Alexandre BONIN
 *  Date : 12/02/2017 DMY format
 *
 *  class generator GUI program realized during OpenClassroom C++
 *  in Qt TP tutorial.
 *
 */

#include <QApplication>
#include "MainWindow.h"


int main(int argc, char* argv[]){

    QApplication application(argc, argv);

    MainWindow* mainWin = new MainWindow();

    mainWin->show();

    // Execution
    int returnedCode = application.exec();

    // Deletes
    delete mainWin; mainWin = nullptr;

    return returnedCode;
}
