#include "mainwindow.h"
#include "maincontroller.h"
#include "mainmodel.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MainWindow* view = new MainWindow();
    MainModel* model = new MainModel();
    MainController* controller = new MainController(view, model);
    controller->showView();

    return a.exec();
}
