#ifndef PHONEBOOKDIALOG_H
#define PHONEBOOKDIALOG_H

#include <QDialog>

namespace Ui {
class PhoneBookDialog;
}

class PhoneBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PhoneBookDialog(QWidget *parent = nullptr);
    ~PhoneBookDialog();

public:
    Ui::PhoneBookDialog *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // PHONEBOOKDIALOG_H
