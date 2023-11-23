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
    } else {
        pilha->topo++;
        pilha->dados[pilha->topo] = valor;
        printf("Valor %d empilhado.\n", valor);
    }
}

int exibirTopoPilha(Pilha *pilha) {
        return pilha->dados[pilha- >topo];
}

int desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("A pilha está vazia. Não é possível remover um valor.\n");
        return -1;
    } else {
        int valor = pilha->dados[pilha->topo];
        pilha->topo--;
        return valor;
    }
}

int tamanhoPilha(Pilha *pilha) {
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d\n", pilha->dados[i]);
    }
}

void exibirPilha(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Conteúdo da pilha:\n");
        for (int i = pilha->topo; i >= 0; i--) {
            printf("%d\n", pilha->dados[i]);
        }
    }
}

void buscarNaPilha(Pilha *pilha, int valor) {
    int encontrado = 0;
    for (int i = pilha->topo; i >= 0; i--) {
        if (pilha->dados[i] == valor) {
            printf("Valor %d encontrado na posição %d.\n", valor, i);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Valor %d não encontrado na pilha.\n", valor);
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);
    int escolha, valor;
    int exit = 1;
    do{
        printf("\nMenu:\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Tamanho da pilha\n");
        printf("4. Topo da pilha");
        printf("5. Exibir pilha\n");
        printf("6. Buscar item\n");
        printf("7. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &valor);
                empilhar(&pilha, valor);
                break;
            case 2:
                valor = desempilhar(&pilha);
                if (valor != -1) {
                    printf("Valor removido: %d\n", valor);
                }
                break;
            case 3:
                printf("Tamanho da pilha: %d\n", tamanhoPilha(&pilha));
                break;
            case 4:
                printf("O valor no topo da pilha é %d empilhado.\n", exibirTopoPilha(&pilha));
                break;
            case 5:
                printf("Digite um valor para buscar: ");
                scanf("%d", &valor);
                buscarNaPilha(&pilha, valor);
            case 6:
                printf("Digite um valor para buscar: ");
            case 7:
                exit = 0;
            }
        } while (exit = 1);
    }
