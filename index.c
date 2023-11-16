#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct {
    int dados[TAMANHO_MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int estaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int estaCheia(Pilha *pilha) {
    return pilha->topo == TAMANHO_MAX - 1;
}

void empilhar(Pilha *pilha, int valor) {
    if (estaCheia(pilha)) {
        printf("A pilha está cheia. Não é possível inserir o valor.\n");
        return;
    }

    pilha->topo++;
    pilha->dados[pilha->topo] = valor;
}

int desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("A pilha está vazia. Não é possível remover um valor.\n");
        return -1;
    }

    int valor = pilha->dados[pilha->topo];
    pilha->topo--;
    return valor;
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);

    printf("Elemento removido: %d\n", desempilhar(&pilha));
    printf("Elemento removido: %d\n", desempilhar(&pilha));
    printf("Elemento removido: %d\n", desempilhar(&pilha));

    return 0;
}
