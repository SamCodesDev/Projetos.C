#include <stdio.h>

float taxaEntrega(float distancia) {
    return 5 + (distancia * 1.5);
}

void mostrarPedidos(int pizza, int burger, int sushi, int batata, int acai) {

    printf("\n========== PEDIDOS FEITOS ==========\n");

    if (pizza == 0 && burger == 0 && sushi == 0 && batata == 0 && acai == 0) {
        printf("Nenhum pedido feito ainda.\n");
    } else {
        if (pizza > 0)
            printf("Pizza Calabresa: %d\n", pizza);

        if (burger > 0)
            printf("Hamburguer Artesanal: %d\n", burger);

        if (sushi > 0)
            printf("Sushi Combo: %d\n", sushi);

        if (batata > 0)
            printf("Batata Frita Grande: %d\n", batata);

        if (acai > 0)
            printf("Acai 500ml: %d\n", acai);
    }

    printf("====================================\n");
}

int main() {
    int escolha = -1;
    int opcao = -1;
    float distancia;

    int pizza = 0, burger = 0, sushi = 0, batata = 0, acai = 0;

    printf("=====================================\n");
    printf("        SISTEMA DE PEDIDOS\n");
    printf("=====================================\n");

    while (escolha != 0) {

        printf("\nEscolha no menu o item que deseja:\n\n");
        printf("1 - Pizza Calabresa\n");
        printf("2 - Hamburguer Artesanal\n");
        printf("3 - Sushi Combo\n");
        printf("4 - Batata Frita Grande\n");
        printf("5 - Acai 500ml\n");
        printf("0 - Finalizar pedidos\n");

        printf("\nDigite sua escolha: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("\nEncerrando pedidos...\n");
            break;
        }

        if (escolha == 1) {
            pizza++;
            printf("\n====== PIZZA CALABRESA ======\n");
            printf("Pizza tradicional com molho de tomate,\n");
            printf("mussarela e calabresa.\n");
            printf("Preco: R$ 39.90\n");
        } 
        else if (escolha == 2) {
            burger++;
            printf("\n====== HAMBURGUER ARTESANAL ======\n");
            printf("Hamburguer 180g com queijo, alface e tomate.\n");
            printf("Preco: R$ 25.90\n");
        } 
        else if (escolha == 3) {
            sushi++;
            printf("\n====== SUSHI COMBO ======\n");
            printf("Combo com 20 pecas variadas.\n");
            printf("Preco: R$ 49.90\n");
        } 
        else if (escolha == 4) {
            batata++;
            printf("\n====== BATATA FRITA GRANDE ======\n");
            printf("Batata crocante com molho especial.\n");
            printf("Preco: R$ 15.90\n");
        } 
        else if (escolha == 5) {
            acai++;
            printf("\n====== ACAI 500ML ======\n");
            printf("Acai cremoso com granola.\n");
            printf("Preco: R$ 18.90\n");
        } 
        else {
            printf("\nOpcao invalida! Tente novamente.\n");
            continue;
        }

        printf("\nO que deseja fazer agora?\n");
        printf("1 - Calcular valor da entrega\n");
        printf("2 - Ver pedidos feitos\n");
        printf("3 - Fazer outro pedido\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\nInforme a distancia da entrega (km): ");
            scanf("%f", &distancia);
            printf("Valor da entrega: R$ %.2f\n", taxaEntrega(distancia));
        } 
        else if (opcao == 2) {
            mostrarPedidos(pizza, burger, sushi, batata, acai);
        } 
        else if (opcao == 3) {
            printf("\nVoltando ao menu...\n");
        } 
        else {
            printf("\nOpcao invalida!\n");
        }
    }

    printf("\nObrigado por usar o sistema!\n");
    return 0;
}