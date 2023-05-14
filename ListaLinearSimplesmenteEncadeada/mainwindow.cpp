#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEditSaidaQtdElementos->setEnabled(false);
    ui->textEditSaida->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eInteiro(QString entradaValor){
    bool number {false};
        std::string s = entradaValor.toStdString();
        if(!s.empty() && std::all_of(s.begin(), s.end(), [](char c){
        return ::isdigit(c);
        })){
        number = true;
        }
    return number;
}

void MainWindow::on_pushButtonIncluirInicio_clicked()
{
    try{
        QString strValor = ui->lineEditValor->text();
        if(!eInteiro(strValor)) throw QString("INFORME VALOR VÁLIDO - deve ser um inteiro");
        int valor = strValor.toInt();
        lista1.inserirInicio(valor);

        ui->textEditSaida->setText(lista1.obterDadosLLSE());
        ui->pushButtonAcessarInicio->setEnabled(true);
        ui->pushButtonRetiraInicio->setEnabled(true);
        ui->lineEditValor->clear();

        QString saida = QString::number(lista1.getQuantidadeElementos());
        ui->textEditSaidaQtdElementos->setText(saida);

        ui->pushButtonIncluirFinal->setEnabled(true);
        ui->pushButtonAcessarFinal->setEnabled(true);
        ui->pushButtonRetiraFinal->setEnabled(true);

        ui->pushButtonIncluirMeio->setEnabled(true);
        ui->pushButtonAcessarMeio->setEnabled(true);
        ui->pushButtonRetiraMeio->setEnabled(true);
    } catch(QString &erro){
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonAcessarInicio_clicked()
{
    try{
        int valor = lista1.acessarInicio();
        ui->lineEditValor->setText(QString::number(valor));
    } catch (QString &erro){
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonRetiraInicio_clicked()
{
    try{
        int valor = lista1.retirarInicio();
        ui->lineEditValor->setText(QString::number(valor));

        QString saida = QString::number(lista1.getQuantidadeElementos());
        ui->textEditSaidaQtdElementos->setText(saida);

        ui->textEditSaida->clear();
        ui->textEditSaida->setText(lista1.obterDadosLLSE());
    } catch (QString &erro){
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonIncluirFinal_clicked()
{
    try {
        //int valor = ui->lineEditValor->text().toInt();
        //if(!valor) throw QString("INFORME VALOR VÁLIDO - deve ser um inteiro");

        //std::string auxValor = ui->lineEditValor->text().toStdString();
        //int valor = std::stoi(auxValor);

        QString strValor = ui->lineEditValor->text();
        if(!eInteiro(strValor)) throw QString("INFORME VALOR VÁLIDO - deve ser um inteiro");
        int valor = strValor.toInt();

        lista1.inserirFinal(valor);

        ui->textEditSaida->setText(lista1.obterDadosLLSE());
        ui->lineEditValor->clear();

        QString saida = QString::number(lista1.getQuantidadeElementos());
        ui->textEditSaidaQtdElementos->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonAcessarFinal_clicked()
{
    try {
        int valor = lista1.acessarFinal();
        ui->lineEditValor->setText(QString::number(valor));
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonRetiraFinal_clicked()
{
    try {
        int valor = lista1.retirarFinal();
        ui->lineEditValor->setText(QString::number(valor));

        QString saida = QString::number(lista1.getQuantidadeElementos());
        ui->textEditSaidaQtdElementos->setText(saida);

        ui->textEditSaida->clear();
        ui->textEditSaida->setText(lista1.obterDadosLLSE());
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonIncluirMeio_clicked()
{
    try {
        //int valor = ui->lineEditValor->text().toInt();
        //if(!valor) throw QString("INFORME VALOR VÁLIDO - deve ser um inteiro");

        QString strValor = ui->lineEditValor->text();
        if(!eInteiro(strValor)) throw QString("INFORME VALOR VÁLIDO - deve ser um inteiro");
        int valor = strValor.toInt();

        int posicao = 0;
        if(lista1.estaVazia()) posicao = 0;
        else posicao =  QInputDialog::getInt(this, "LEITURA", "POSIÇÃO NA LISTA:");
        if(posicao < 0 || posicao > lista1.getQuantidadeElementos()) throw QString("INFORME POSIÇÃO VÁLIDA");
        lista1.inserirPosicao(valor, posicao);

        ui->textEditSaida->setText(lista1.obterDadosLLSE());
        ui->lineEditValor->clear();

        QString saida = QString::number(lista1.getQuantidadeElementos());
        ui->textEditSaidaQtdElementos->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonAcessarMeio_clicked()
{
    try {
        int posicao =  QInputDialog::getInt(this, "LEITURA", "POSIÇÃO NA LISTA:");
        if(posicao <0 || posicao > lista1.getQuantidadeElementos()) throw QString("INFORME POSIÇÃO VÁLIDA");
        int valor = lista1.acessarPosicao(posicao);
        ui->lineEditValor->setText(QString::number(valor));
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonRetiraMeio_clicked()
{
    try {
        int posicao =  QInputDialog::getInt(this, "LEITURA", "POSIÇÃO NA LISTA:");
        if(posicao <0 || posicao > lista1.getQuantidadeElementos()) throw QString("INFORME POSIÇÃO VÁLIDA");
        int valor = lista1.retirarPosicao(posicao);
        ui->lineEditValor->setText(QString::number(valor));

        QString saida = QString::number(lista1.getQuantidadeElementos());
        ui->textEditSaidaQtdElementos->setText(saida);

        ui->textEditSaida->clear();
        ui->textEditSaida->setText(lista1.obterDadosLLSE());
    } catch (QString &erro) {
        QMessageBox::information(this, "ALERTA DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonInsercaoOrdenada_clicked()
{
    try {
        QString strValor = ui->lineEditValor->text();
        if(!eInteiro(strValor)) throw QString("INFORME VALOR VÁLIDO - deve ser um inteiro");
        int valor = strValor.toInt();

        QStringList options;
        options << "CRESCENTE" << "DECRESCENTE";
        QString tipoOrdenacao = QInputDialog::getItem(this, "LEITURA", "ORDENAÇÃO:", options, 0, false);

        if(tipoOrdenacao == "CRESCENTE") lista1.insercaoOrdenadaCrescente(valor);
        if(tipoOrdenacao == "DECRESCENTE") lista1.insercaoOrdenadaDecrescente(valor);

        ui->textEditSaida->setText(lista1.obterDadosLLSE());
        ui->lineEditValor->clear();

        QString saida = QString::number(lista1.getQuantidadeElementos());
        ui->textEditSaidaQtdElementos->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonOrdenar_clicked()
{
    try {
        QStringList options;
        options << "CRESCENTE" << "DECRESCENTE";
        QString tipoOrdenacao = QInputDialog::getItem(this, "LEITURA", "ORDENAÇÃO:", options, 0, false);

        if(tipoOrdenacao == "CRESCENTE") lista1.ordenarCrescente();
        if(tipoOrdenacao == "DECRESCENTE") lista1.ordenarDecrescente();

        ui->textEditSaida->clear();
        ui->textEditSaida->setText(lista1.obterDadosLLSE());
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}
