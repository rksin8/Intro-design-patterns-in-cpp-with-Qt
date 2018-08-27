#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QColor>

class InputForm : public QDialog{

    Q_OBJECT
public:
        explicit InputForm(QWidget* parent = 0);
        void updateUi();
protected slots:
    void accept();
    void chooseColor();

private:
    QColor color_;
    QLineEdit* name_;
    QDateEdit* birthday_;
    QPushButton* colorButton_;
    QDialogButtonBox* buttons_;

};


#endif /* end of include guard: INPUTFORM_H_GOALDURQ */
