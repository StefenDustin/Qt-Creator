#ifndef DESKTOPMAINWINDOW_H
#define DESKTOPMAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class DesktopMainWindow; }
QT_END_NAMESPACE

class DesktopMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DesktopMainWindow(QWidget *parent = nullptr);
    ~DesktopMainWindow();

private:
    void AddItemToTableWidget(const QString& name,
                              const QString& telp,
                              const QString& email);
    bool OpenDatabase();
    int loadPhoneBook();
    bool insertItemToDatabase(const QString& name,
                              const QString& telp,
                              const QString& email);
    bool deleteItemByPhoneNumber(const QString& telp);
private slots:

    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_actionSort_triggered();
    void on_actionFind_triggered();
    void on_actionAdd_Item_triggered();
    void on_actionDelete_Item_triggered();
    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::DesktopMainWindow *ui;
    QSqlDatabase m_db;
};
#endif // DESKTOPMAINWINDOW_H
