#include "tabla.h"
#include "ui_tabla.h"
#include <QDebug>
Tabla::Tabla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tabla)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);

    QStringList headers;
    headers << "Placas" << "Marca" << "Modelo" << "Km";
    qDebug() << headers;

    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

Tabla::~Tabla()
{
    delete ui;
}

void Tabla::mostrarTabla(Taller &taller)
{
    ui->tableWidget->setRowCount(taller.size());
    ui->tableWidget->clear();
    QStringList headers;
    headers << "Placas" << "Marca" << "Modelo" << "Km";
    qDebug() << headers;

    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (size_t i = 0; i < taller.size(); i++) {
        QString placas = QString::fromStdString(
                    taller[i].getPlacas());
        QString marca = QString::fromStdString(
                    taller[i].getMarca());
        QString modelo = QString::number(
                    taller[i].getModelo());
        QString km = QString::number(
                    taller[i].getKm());

        QTableWidgetItem *iPlacas = new
                QTableWidgetItem(placas);
        QTableWidgetItem *iMarca = new
                QTableWidgetItem(marca);
        QTableWidgetItem *iModelo = new
                QTableWidgetItem(modelo);
        QTableWidgetItem *iKm = new
                QTableWidgetItem(km);

        ui->tableWidget->setItem(i, 0, iPlacas);
        ui->tableWidget->setItem(i, 1, iMarca);
        ui->tableWidget->setItem(i, 2, iModelo);
        ui->tableWidget->setItem(i, 3, iKm);
    }
}
