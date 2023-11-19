#include "desktopmainwindow.h"
#include "ui_desktopmainwindow.h"
#include "sortdialog.h"
#include "ui_sortdialog.h"
#include "QMessageBox"
#include "finddialog.h"
#include "ui_finddialog.h"
#include "phonebookdialog.h"
#include "ui_phonebookdialog.h"
#include "QSqlQuery"
#include "QSqlError"

DesktopMainWindow::DesktopMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DesktopMainWindow)
{
    ui->setupUi(this);

    QStringList tableHeader;
    tableHeader << "Nama" << "Phone Number" << "Email";
    ui->tableWidget->setColumnCount(tableHeader.count());
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setStyleSheet("selection-background-color: rgb(133,199,0)");


    if (OpenDatabase())
    {
        qDebug() << "Open Database Succesfull";
        loadPhoneBook();
    }
    else
        qDebug() << "Open Database Failed";
}

DesktopMainWindow::~DesktopMainWindow()
{
    delete ui;
}

void DesktopMainWindow::AddItemToTableWidget(const QString& name, const QString& telp, const QString& email)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(telp));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(email));
}

bool DesktopMainWindow::OpenDatabase()
{
    m_db = QSqlDatabase::addDatabase("QODBC");
    m_db.setDatabaseName("phoneBook");


    return m_db.open();

}

int DesktopMainWindow::loadPhoneBook()
{
    int nCount = 0;
    QSqlQuery qry("SELECT * FROM phonebook.tablephonebook order by name", m_db);
    while (qry.next())
    {
        QString telp = qry.value("PhoneNumber").toString();
        QString name = qry.value("name").toString();
        QString email = qry.value("email").toString();
        AddItemToTableWidget(name,telp,email);
        nCount++;
    }
    return nCount;
}

bool DesktopMainWindow::insertItemToDatabase(const QString& name, const QString& telp, const QString& email)
{
    QSqlQuery qry(m_db);

    qry.prepare("INSERT INTO tablephonebook (PhoneNumber, name, email)"
                "VALUES (:phoneNumber,:name,:email)");
    qry.bindValue(":phoneNumber", telp);
    qry.bindValue(":name", name);
    qry.bindValue(":email", email);

    bool fResult = qry.exec();
    if (!fResult)
    {
        qDebug() << "Insert Data Error:" << qry.lastError().text();
    }
    return fResult;
}

bool DesktopMainWindow::deleteItemByPhoneNumber(const QString &telp)
{
    QSqlQuery qry(m_db);

    qry.prepare("DELETE FROM tablephonebook WHERE phoneNumber=:phoneNumber");
    qry.bindValue(":phoneNumber", telp);

    bool fResult = qry.exec();
    if (!fResult)
    {
        qDebug() << "Delete Data Error:" << qry.lastError().text();
    }
    return fResult;
}

void DesktopMainWindow::on_actionExit_triggered()
{
    m_db.close();
    close();
}


void DesktopMainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About",
                             "Desktop sample Application\n"
                             "(c) Copyright by Stefen Dustin 2023");
}


void DesktopMainWindow::on_actionSort_triggered()
{
    SortDialog d;
    if (d.exec()==QDialog::Accepted)
    {
        qDebug()  << "Sort Accepted: " <<
            d.ui->PrimaryColomn->currentText()<<
            "Order: " << d.ui->PrimaryOrder->currentText();
        int nSortOrder = d.ui->PrimaryOrder->currentIndex();
        ui->tableWidget->sortByColumn(d.ui->PrimaryColomn->currentIndex(),
                                      Qt::SortOrder(nSortOrder));
    }
}


void DesktopMainWindow::on_actionFind_triggered()
{
    FindDialog d;
    d.ui->checkBoxCase->setChecked(true);
    if (d.exec()==QDialog::Accepted)
    {
        qDebug()  << "Find: " << d.ui->lineEditSearch->text();
    }
}


void DesktopMainWindow::on_actionAdd_Item_triggered()
{
    PhoneBookDialog d;
    if (d.exec()==QDialog::Accepted)
    {
        AddItemToTableWidget(d.ui->lineEditNama->text(), d.ui->lineEditTelp->text(), d.ui->lineEditEmail->text());
        insertItemToDatabase(d.ui->lineEditNama->text(), d.ui->lineEditTelp->text(), d.ui->lineEditEmail->text());
        //        qDebug()  <<
        //            "Data Added"
        //            "\nNama: " << d.ui->lineEditNama->text()<<
        //            "\nTelp: " << d.ui->lineEditTelp->text()<<
        //            "\nEmail: " << d.ui->lineEditEmail->text();
    }
}


void DesktopMainWindow::on_actionDelete_Item_triggered()
{
    int row = ui->tableWidget->currentRow();
    QString phoneNumber = ui->tableWidget->item(row, 1)->text();
    if (deleteItemByPhoneNumber(phoneNumber))
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}


void DesktopMainWindow::on_tableWidget_cellChanged(int row, int column)
{
    qDebug() << "Cell Changes: " << row << "," << column <<
        ":" << ui->tableWidget->item(row, column)->text();
}

