#include "inputform.h"

#include <QVBoxLayout>
#include <QFormLayout>

#include <QColorDialog>

InputForm::InputForm(QWidget* parent):
    QDialog(parent){
        updateUi();
    }



void InputForm::updateUi(){
    name_ = new QLineEdit;
    birthday_ = new QDateEdit;
    birthday_->setDisplayFormat("dd/MM/yyyy");
    colorButton_ = new QPushButton(tr("Choose"));
    //colorButton_->autoFillBackground(true);
    colorButton_->setAutoFillBackground(true);

    buttons_ = new QDialogButtonBox(QDialogButtonBox::Ok |
              QDialogButtonBox::Cancel );

    QVBoxLayout* vbox = new QVBoxLayout;
    QFormLayout* layout = new QFormLayout;

    layout-> addRow(tr("Name"), name_);
    layout-> addRow(tr("Birthday"), birthday_);
    layout-> addRow(tr("Favorite Color"), colorButton_);


    connect(colorButton_, SIGNAL(clicked()),this, SLOT(chooseColor()));

    connect(buttons_, &QDialogButtonBox::accepted, this,&QDialog::accept);

    connect(buttons_, &QDialogButtonBox::rejected, this, &QDialog::reject);


    vbox->addLayout(layout);

    vbox->addWidget(buttons_);

    setLayout(vbox);

}

void InputForm::accept(){

    QString color = QString("background-color:%1").arg(color_.name());
    colorButton_->setStyleSheet(color);
}

void InputForm::chooseColor(){
    // open color choose dialog
    QColor color = QColorDialog::getColor(Qt::yellow, this);
    // assign the color_ = selected color from color dailog
    if (color.isValid()){
        color_ = color;
    }
}

