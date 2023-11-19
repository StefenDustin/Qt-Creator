#include "phonebookdialog.h"
#include "ui_phonebookdialog.h"

PhoneBookDialog::PhoneBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhoneBookDialog)
{
    ui->setupUi(this);
}

PhoneBookDialog::~PhoneBookDialog()
{
    delete ui;
}

void PhoneBookDialog::on_pushButton_clicked()
{
    if (ui->lineEditEmail->text().length()>0 &&
        ui->lineEditNama->text().length()>0 &&
        ui->lineEditTelp->text().length()>0)
        accept();
}

