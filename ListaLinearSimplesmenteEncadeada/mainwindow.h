#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <llse.h>
#include <QInputDialog>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonIncluirInicio_clicked();

    void on_pushButtonAcessarInicio_clicked();

    void on_pushButtonRetiraInicio_clicked();

    void on_pushButtonIncluirFinal_clicked();

    void on_pushButtonAcessarFinal_clicked();

    void on_pushButtonRetiraFinal_clicked();

    void on_pushButtonIncluirMeio_clicked();

    void on_pushButtonAcessarMeio_clicked();

    void on_pushButtonRetiraMeio_clicked();
    void on_pushButtonInsercaoOrdenada_clicked();

    void on_pushButtonOrdenar_clicked();

private:
    Ui::MainWindow *ui;
    ggs::LLSE lista1;
    bool eInteiro(QString entradaValor);
};
#endif // MAINWINDOW_H
