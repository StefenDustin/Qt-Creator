#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class SortDialog; }
QT_END_NAMESPACE

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    SortDialog(QWidget *parent = nullptr);
    ~SortDialog();

private slots:
    void on_ButtonMore_clicked();

public:
    Ui::SortDialog *ui;
};
#endif // SORTDIALOG_H
