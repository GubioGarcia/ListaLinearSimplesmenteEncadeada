#include "llse.h"

namespace ggs{
    int LLSE::getQuantidadeElementos() const{
        return quantidadeElementos;
    }

    LLSE::LLSE():
        quantidadeElementos(0), inicio(0)
    {}

    bool LLSE::estaVazia() const{
        return (quantidadeElementos == 0);
    }

    void LLSE::inserirInicio(int elemento){
        try{
            No *auxiliar = new No(elemento);
            quantidadeElementos++;
            auxiliar->setEnderecoProximo(inicio);
            inicio = auxiliar;
        } catch (std::bad_alloc &erro){
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirInicio");
        }
    }

    int LLSE::retirarInicio(){
        if(estaVazia()) throw QString("Lista está vazia - retirarInicio");
        No* auxiliar = inicio;
        inicio = inicio->getEnderecoProximo();
        quantidadeElementos--;
        int valor = auxiliar->getDado();
        delete auxiliar;
        return valor;
    }

    int LLSE::acessarInicio()const{
        if(estaVazia()) throw QString("Lista está vazia - acessarInicio");
        return inicio->getDado();
    }

    QString LLSE::obterDadosLLSE()const{
        if(estaVazia()) throw QString("Lista esta Vazia - obterDadosLLSE");
        No* auxiliar = inicio;
        QString saida = "";
        for(int i=0; i<quantidadeElementos; i++){
            saida += "|" + QString::number(auxiliar->getDado()) + "|";
            auxiliar = auxiliar->getEnderecoProximo();
            if(i<quantidadeElementos-1) saida += " -> ";
        }
        return saida;
    }

    void LLSE::inserirFinal(int elemento){
        try {
            No *auxiliar = new No(elemento);
            if(estaVazia()){
                quantidadeElementos++;
                inicio = auxiliar;
                return;
            } else{
                No* aux = inicio;
                for(int i=0; i<quantidadeElementos-1; i++){
                    aux = aux->getEnderecoProximo();
                }
                quantidadeElementos++;
                aux->setEnderecoProximo(auxiliar);
            }
        } catch (std::bad_alloc &erro) {
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirFinal");
        }
    }

    int LLSE::acessarFinal()const{
        if(estaVazia()) throw QString("Lista está vazia - acessarFinal");
        No* aux = inicio;
        for(int i=0; i<quantidadeElementos-1; i++){
            aux = aux->getEnderecoProximo();
        }
        return aux->getDado();
    }

    int LLSE::retirarFinal(){
        if(estaVazia()) throw QString("Lista esta Vazia - retirarFinal");
        if(quantidadeElementos == 1){
            int valor = inicio->getDado();
            delete inicio;
            quantidadeElementos = 0;
            inicio = 0;
            return valor;
        } else{
            No *aux = inicio;
            for(int i=0; i<quantidadeElementos-2; i++){
                aux = aux->getEnderecoProximo();
            }
            int valor = aux->getEnderecoProximo()->getDado();
            delete aux->getEnderecoProximo();
            aux->setEnderecoProximo(0);
            quantidadeElementos--;
            return valor;
        }
    }

    void LLSE::inserirPosicao(int elemento, int posicao){
        try {
            if(posicao < 0 || posicao > quantidadeElementos) throw QString("Posição fora do intervalo válido - acessarPosicao");
            if(posicao == 0) return inserirInicio(elemento);
            if(posicao == quantidadeElementos) return inserirFinal(elemento);
            No *aux = inicio;
            for(int i=0; i < posicao-1; i++){
                aux = aux->getEnderecoProximo();
            }
            No *novoNo = new No(elemento);
            quantidadeElementos++;
            novoNo->setEnderecoProximo(aux->getEnderecoProximo());
            aux->setEnderecoProximo(novoNo);
        } catch (std::bad_alloc &erro) {
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirFinal");
        }
    }

    int LLSE::acessarPosicao(int posicao)const{
        if(estaVazia()) throw QString("Lista está vazia - acessarPosicao");
        if(posicao < 0 || posicao >= quantidadeElementos) throw QString("Posição fora do intervalo válido - acessarPosicao");
        if(posicao == 0) return acessarInicio();
        if(posicao == quantidadeElementos - 1) return acessarFinal();
        No *aux = inicio;
        for(int i=0; i < posicao; i++){
            aux = aux->getEnderecoProximo();
        }
        return aux->getDado();
    }

    int LLSE::retirarPosicao(int posicao){
        if(estaVazia()) throw QString("Lista está vazia - retirarPosicao");
        if(posicao < 0 || posicao >= quantidadeElementos) throw QString("Posição fora do intervalo válido - acessarPosicao");
        if(posicao == 0) return retirarInicio();
        if(posicao == quantidadeElementos - 1) return retirarFinal();
        No *aux = inicio;
        for(int i=0; i < posicao-1; i++){
            aux = aux->getEnderecoProximo();
        }
        int valor = aux->getEnderecoProximo()->getDado();
        No *auxiliarDelete = aux->getEnderecoProximo();
        aux->setEnderecoProximo(aux->getEnderecoProximo()->getEnderecoProximo());
        delete auxiliarDelete;
        quantidadeElementos--;
        return valor;
    }

    void LLSE::insercaoOrdenadaCrescente(int elemento){
        try {
            if(estaVazia()) return inserirInicio(elemento);
            No *novoNo = new No(elemento);
            if(quantidadeElementos == 1){
                if(inicio->getDado() < novoNo->getDado()) return inserirFinal(elemento);
                else return inserirInicio(elemento);
            }
            No* aux = inicio;
            for(int i=0; i<quantidadeElementos-1; i++){
                if(inicio->getDado() > novoNo->getDado()){
                    novoNo->setEnderecoProximo(inicio);
                    inicio = novoNo;
                    quantidadeElementos++;
                    return;
                }
                if(aux->getEnderecoProximo()->getDado() < novoNo->getDado()){
                    aux = aux->getEnderecoProximo();
                } else{
                    novoNo->setEnderecoProximo(aux->getEnderecoProximo());
                    aux->setEnderecoProximo(novoNo);
                    quantidadeElementos++;
                    return;
                }
            }
            quantidadeElementos++;
            aux->setEnderecoProximo(novoNo);
        } catch (std::bad_alloc &erro) {
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirFinal");
        }
    }

    void LLSE::insercaoOrdenadaDecrescente(int elemento){
        try {
            if(estaVazia()) return inserirInicio(elemento);
            No *novoNo = new No(elemento);
            if(quantidadeElementos == 1){
                if(inicio->getDado() > novoNo->getDado()) return inserirFinal(elemento);
                else return inserirInicio(elemento);
            }
            No* aux = inicio;
            for(int i=0; i<quantidadeElementos-1; i++){
                if(inicio->getDado() < novoNo->getDado()){
                    novoNo->setEnderecoProximo(inicio);
                    inicio = novoNo;
                    quantidadeElementos++;
                    return;
                }
                if(aux->getEnderecoProximo()->getDado() > novoNo->getDado()){
                    aux = aux->getEnderecoProximo();
                } else{
                    novoNo->setEnderecoProximo(aux->getEnderecoProximo());
                    aux->setEnderecoProximo(novoNo);
                    quantidadeElementos++;
                    return;
                }
            }
            quantidadeElementos++;
            aux->setEnderecoProximo(novoNo);
        } catch (std::bad_alloc &erro) {
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirFinal");
        }
    }

    void LLSE::ordenarCrescente(){
        if(estaVazia()) throw QString("Lista está vazia - ordenarCrescente");
        if(quantidadeElementos == 1) return;
        No *i, *j;
        int menorValor;
        for (i = inicio; i != nullptr; i = i->getEnderecoProximo()) {
            menorValor = i->getDado();
            No *noMenorValor = i;
            for (j = i->getEnderecoProximo(); j != nullptr; j = j->getEnderecoProximo()) {
                if (j->getDado() < menorValor) {
                    menorValor = j->getDado();
                    noMenorValor = j;
                }
            }
            if (noMenorValor != i) {
                int aux = i->getDado();
                i->setDado(menorValor);
                noMenorValor->setDado(aux);
            }
        }
    }

    void LLSE::ordenarDecrescente(){
        if(estaVazia()) throw QString("Lista está vazia - ordenarDecrescente");
        if(quantidadeElementos == 1) return;
        No *i, *j;
        int maiorValor;
        for (i = inicio; i != nullptr; i = i->getEnderecoProximo()) {
            maiorValor = i->getDado();
            No *noMaiorValor = i;
            for (j = i->getEnderecoProximo(); j != nullptr; j = j->getEnderecoProximo()) {
                if (j->getDado() > maiorValor) {
                    maiorValor = j->getDado();
                    noMaiorValor = j;
                }
            }
            if (noMaiorValor != i) {
                int aux = i->getDado();
                i->setDado(maiorValor);
                noMaiorValor->setDado(aux);
            }
        }
    }
}
