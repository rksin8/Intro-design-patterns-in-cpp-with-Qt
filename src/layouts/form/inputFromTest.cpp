#include <QApplication>

#include "inputform.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    InputForm form;

    form.show();

    return app.exec();
}
