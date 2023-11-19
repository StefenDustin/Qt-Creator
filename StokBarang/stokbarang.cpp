#include "stokbarang.h"
#include "ui_stokbarang.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"

StokBarang::StokBarang(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StokBarang)
{
    ui->setupUi(this);

    QStringList tableHeader;
    tableHeader << "KodeBarang" << "Nama" << "Harga Satuan" << "Jumlah";
    ui->tableWidget->setColumnCount(tableHeader.count());
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setStyleSheet("selection-background-color: rgb(133,199,0)");
}

StokBarang::~StokBarang()
{
    delete ui;
}

void StokBarang::AddItemToTableWidget(const QString& KodeBarang, const QString& Nama, const QString& HargaSatuan, const QString& Jumlah)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(KodeBarang));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(Nama));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(HargaSatuan));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(Jumlah));
}

void StokBarang::on_actionAdd_triggered()
{
    Dialog d;
    if (d.exec()==QDialog::Accepted)
    {
        AddItemToTableWidget(d.ui->lineEditKode->text(), d.ui->lineEditNama->text(), d.ui->lineEditHarga->text(), d.ui->lineEditJumlah->text());
    }
}


void StokBarang::on_actionDelete_triggered()
{
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(row);
}

