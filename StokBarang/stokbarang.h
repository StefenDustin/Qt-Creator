#ifndef STOKBARANG_H
#define STOKBARANG_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class StokBarang; }
QT_END_NAMESPACE

class StokBarang : public QMainWindow
{
    Q_OBJECT

public:
    StokBarang(QWidget *parent = nullptr);
    ~StokBarang();

private slots:
    void on_actionAdd_triggered();

    void on_actionDelete_triggered();

private:
    void AddItemToTableWidget(const QString& KodeBarang,
                              const QString& Nama,
                              const QString& HargaSatuan,
                              const QString& Jumlah);

private:
    Ui::StokBarang *ui;
};
#endif // STOKBARANG_H
