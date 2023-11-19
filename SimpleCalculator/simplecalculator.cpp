#include "simplecalculator.h"
#include "ui_simplecalculator.h"

SimpleCalculator::SimpleCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleCalculator)
{
    ui->setupUi(this);
}

SimpleCalculator::~SimpleCalculator()
{
    delete ui;
}

void SimpleCalculator::on_ButtonHitung_clicked()
{
    float Bil_1 = ui->Input_1->text().toFloat();
    float Bil_2 = ui->Input_2->text().toFloat();

    if (ui->radioButton_1->isChecked())
    {
        float Result =  Bil_1 + Bil_2;
        ui->Result->setNum(Result);
    }
    else if (ui->radioButton_2->isChecked())
    {
        float Result =  Bil_1 - Bil_2;
        ui->Result->setNum(Result);
    }
    else if (ui->radioButton_3->isChecked())
    {
        float Result =  Bil_1 * Bil_2;
        ui->Result->setNum(Result);
    }
    else if (ui->radioButton_4->isChecked())
    {
        float Result =  Bil_1 / Bil_2;
        ui->Result->setNum(Result);
    }
}



