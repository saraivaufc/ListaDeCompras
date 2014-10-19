#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTreeView>
#include "compra.h"
#include "Macros.h"
#include <QDebug>
#include <QDate>

#include "gerenciadorderelatorios.h"
#include "dialogeditarcompra.h"
#include "dialogeditarproduto.h"
#include "dialogconfirmacao.h"
#include "viewproduto.h"
#include "viewcompra.h"
#include "gerenciadordearquivos.h"
#include "Macros.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    enum TypeView{COMPRAS, PRODUTO};

    TypeView typeView;
    Ui::MainWindow *ui;
    QStandardItemModel listaDeCompras;
    QStandardItemModel listaDeProdutos;
    QSize preferedSize;
    double aW, aH;
    double speedW, speedH;

    //esse model refere-se a lista de Compras
    QStandardItemModel* model;

    //esse model refere-se a lista de Produtos
    QStandardItemModel* model2;

    //Esse é um intex temporario que armazena a ultima Compra Clicado
    QModelIndex selected;

    //Esse é um intex temporario que armazena o ultimo Produto Clicado
    QModelIndex selected2;

    QList<QStandardItem *> compraToItemList(QString titulo,
                                            QDate data);

    QList<QStandardItem *> produtoToItemList(QString nome,
                                             float valor,
                                             int qtd,
                                             ClasseDeProduto classe);

private:
    Compra *getCompraAtual();
    Produto *getProdutoAtual();

signals:
    void addCompra(Compra* c);
    void addProduto(Compra * c, Produto *p);
    void atualizandoProdutosNaGui();
    void inicializada();
    void existeCompra(Compra *c, bool *existe);
    void removeCompra(Compra * c);
    void removeComprasPorData(QString data);
    void removeProduto(Compra *c, Produto *p);
    void removeProdutoPorClasse(Compra *c, ClasseDeProduto classe);

    void buscaCompra(Compra **c, QString nome, QDate data);
    void buscaCompraCorrente(Compra **c);
    void buscaProduto(Compra *c, Produto **p, QString nome, ClasseDeProduto classe);
    void clearCompraCorrente();

    /*
        para o gerenciador de relatorios
    */
    void gerarRelatorio(GerenciadorDeRelatorios::TipoRelatorio);

public slots:
    void atualizarCompras();
    void on_actionSair_triggered();
    void on_actionAdd_triggered();

    //muda a view selecionada
    void treeViewCompras_clicked();
    void treeViewProdutos_clicked();
    void on_treeViewCompras_clicked(const QModelIndex &index);

    void on_actionRemove_triggered();

    void updateSize();

public:
    void carregarCompras();
    void adicionarCompra(Compra *c);
    void adicionarCompraCorrente(Compra *c);
    void adicionarProduto(Compra *c, Produto *p, bool somenteNaInterface=false);
    void listaProdutosVisivel(bool estado);
    void listaComprasVisivel(bool estado);
    void limparProdutosInterface();
    void carregaCompraSelecionada(Compra **c);
    void carregaProdutoSelecionado(Produto **p);

private slots:
    void on_treeViewProdutos_clicked(const QModelIndex &index);
    bool compraIsSelected();
    bool produtoIsSelected();
    void on_actionEdit_triggered();
    void on_treeViewProdutos_doubleClicked(const QModelIndex &index);
    void on_treeViewCompras_doubleClicked(const QModelIndex &index);
    void on_actionSalvar_triggered();
    void on_actionGerar_Relatorio_Mensal_triggered();
    void on_actionGerar_Relat_rio_por_Classe_de_Produto_triggered();
    void on_actionGerar_Relat_rio_Mensal_Classe_triggered();
    void on_actionMaiores_Gastos_triggered();
};

#endif // MAINWINDOW_H
