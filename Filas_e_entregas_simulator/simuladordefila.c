#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int ids[MAX];
float valores[MAX];
int tempos[MAX];
int prioridades[MAX];
int tamanho = 0;

void adicionarPedido() {
    if (tamanho >= MAX) {
        printf("Fila cheia!\n");
        return;
    }

    int id;
    float valor;
    int tempo;
    int prioridade;

    printf("ID do pedido: ");
    scanf("%d", &id);

    printf("Valor do pedido: ");
    scanf("%f", &valor);

    printf("Tempo de preparo (min): ");
    scanf("%d", &tempo);

    printf("Prioridade (1=Urgente, 0=Normal): ");
    scanf("%d", &prioridade);

    int i = tamanho - 1;

    while (i >= 0 && prioridades[i] < prioridade) {
        ids[i + 1] = ids[i];
        valores[i + 1] = valores[i];
        tempos[i + 1] = tempos[i];
        prioridades[i + 1] = prioridades[i];
        i = i - 1;
    }

    ids[i + 1] = id;
    valores[i + 1] = valor;
    tempos[i + 1] = tempo;
    prioridades[i + 1] = prioridade;

    tamanho = tamanho + 1;

    printf("Pedido adicionado!\n");
}

void listarPedidos() {
    if (tamanho == 0) {
        printf("Nenhum pedido.\n");
        return;
    }

    int i = 0;

    while (i < tamanho) {
        printf("ID: %d | Valor: %.2f | Tempo: %d | Prioridade: ", ids[i], valores[i], tempos[i]);

        if (prioridades[i] == 1) {
            printf("Urgente\n");
        } else {
            printf("Normal\n");
        }

        i = i + 1;
    }
}

void removerPedido() {
    int id;
    printf("Digite o ID: ");
    scanf("%d", &id);

    int pos = -1;
    int i = 0;

    while (i < tamanho) {
        if (ids[i] == id) {
            pos = i;
        }
        i = i + 1;
    }

    if (pos == -1) {
        printf("Nao encontrado.\n");
        return;
    }

    i = pos;
    while (i < tamanho - 1){
         {
        ids[i] = ids[i + 1];
        valores[i] = valores[i + 1];
        tempos[i] = tempos[i + 1];
        prioridades[i] = prioridades[i + 1];
        i = i + 1;
    }

    tamanho = tamanho - 1;

    printf("Removido!\n");
}
}

void buscarPedido(){
    int id;
    printf("Digite o ID: ");
    scanf("%d", &id);

    int i = 0;
    int encontrado = 0;

    while (i < tamanho) {
        if (ids[i] == id) {
            printf("Encontrado -> Valor: %.2f | Tempo: %d\n", valores[i], tempos[i]);
            encontrado = 1;
        }
        i = i + 1;
    }

    if (encontrado == 0) {
        printf("Nao encontrado.\n");
    }
}

void estatisticas() {
    if (tamanho == 0) {
        printf("Sem dados.\n");
        return;
    }

    int i = 0;
    int soma = 0;
    int maior = tempos[0];

    while (i < tamanho) {
        soma = soma + tempos[i];

        if (tempos[i] > maior) {
            maior = tempos[i];
        }

        i = i + 1;
    }

    printf("Tempo medio: %.2f\n", (float)soma / tamanho);
    printf("Maior tempo: %d\n", maior);
}

void gerarPedidosAleatorios() {
    int n;
    printf("Quantos pedidos? ");
    scanf("%d", &n);

    srand(time(NULL));

    int i = 0;

    while (i < n && tamanho < MAX) {
        ids[tamanho] = rand() % 1000;
        valores[tamanho] = (rand() % 500) + 10;
        tempos[tamanho] = (rand() % 30) + 5;
        prioridades[tamanho] = rand() % 2;

        tamanho = tamanho + 1;
        i = i + 1;
    }

    printf("Gerados!\n");
}

int main() {
    int opcao = -1;

    while (opcao != 0) {
        printf("\n--- Revaly ---\n");
        printf("1 - Adicionar\n");
        printf("2 - Listar\n");
        printf("3 - Remover\n");
        printf("4 - Buscar\n");
        printf("5 - Estatisticas\n");
        printf("6 - Gerar aleatorios\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            adicionarPedido();
        } else {
            if (opcao == 2) {
                listarPedidos();
            } else {
                if (opcao == 3) {
                    removerPedido();
                } else {
                    if (opcao == 4) {
                        buscarPedido();
                    } else {
                        if (opcao == 5) {
                            estatisticas();
                        } else {
                            if (opcao == 6) {
                                gerarPedidosAleatorios();
                            } else {
                                if (opcao == 0) {
                                    printf("Saindo...\n");
                                } else {
                                    printf("Opcao invalida!\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
