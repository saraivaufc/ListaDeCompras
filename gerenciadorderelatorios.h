#ifndef GERENCIADORDERELATORIOS_H
#define GERENCIADORDERELATORIOS_H

#include <QStandardItemModel>
#include <QTableView>

#include "gerenciadordecompras.h"

class GerenciadorDeRelatorios {
private:
    static QStandardItemModel* model;
    static void gerarRelatorioGastoMes(GerenciadorDeCompras*);
    static void gerarRelatorioGastoClasse(GerenciadorDeCompras*);
    static void gerarRelatorioGastoClasseMes(GerenciadorDeCompras*);
    static void gerarRelatorioGastoMax(GerenciadorDeCompras*);

public:
    enum TipoRelatorio{GASTO_MES        = 0,
                       GASTO_CLASSE     = 1,
                       GASTO_CLASSE_MES = 2,
                       GASTO_MAX        = 3};

    static void gerarRelatorio(TipoRelatorio tipoRelatorio, GerenciadorDeCompras *g, QWidget* parent);
};

#endif // GERENCIADORDERELATORIOS_H
