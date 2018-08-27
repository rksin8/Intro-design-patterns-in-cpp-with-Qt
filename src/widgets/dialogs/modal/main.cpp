#include <QtGui>
#include <QProgressDialog>

#include <QApplication>

#include <QMessageBox>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QProgressDialog nonModel;
    nonModel.setWindowTitle("Non Model Parent Dialog");
    nonModel.show();

    nonModel.connect(&nonModel, SIGNAL(finished(int)),
            &app, SLOT(quit()));

    QFileDialog fileDialog(&nonModel, "Model File Child Dialog");

    fileDialog.exec();

    QMessageBox::question(0, QObject::tr("Model parentless fileDialog"),
            QObject::tr("can you interact with the other dialogs now?"),
            QMessageBox::Yes | QMessageBox::No);

    return app.exec();
}
