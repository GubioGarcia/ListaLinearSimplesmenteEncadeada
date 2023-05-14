#ifndef LLSE_H
#define LLSE_H

#include <no.h>

namespace ggs{
    class LLSE// Lista Linear Simplesmente Encadeada
    {
    private:
        int quantidadeElementos;
        ggs::No *inicio;
    public:
        LLSE();
        int getQuantidadeElementos() const;
        bool estaVazia()const;

        void inserirInicio(int elemento);
        int retirarInicio();
        int acessarInicio()const;

        void inserirFinal(int elemento);
        int retirarFinal();
        int acessarFinal()const;

        void inserirPosicao(int elemento, int posicao);
        int retirarPosicao(int posicao);
        int acessarPosicao(int posicao)const;

        void insercaoOrdenadaCrescente(int elemento);
        void insercaoOrdenadaDecrescente(int elemento);

        void ordenarCrescente();
        void ordenarDecrescente();

        QString obterDadosLLSE()const;
    };
}

#endif // LLSE_H
