#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SortDialog)
{
    ui->setupUi(this);
    ui->groupBoxSecondary->hide();
    ui->groupBoxTertiary->hide();
    adjustSize();
}

SortDialog::~SortDialog()
{
    delete ui;
}


void SortDialog::on_ButtonMore_clicked()
{
    adjustSize();
}

