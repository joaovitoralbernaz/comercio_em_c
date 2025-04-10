#include <stdio.h>
#include <string.h>

struct produtos {
    char nome[15];
    float preco;
};

// Variáveis globais
int rec = 0;
int des = 0;
int n;
struct produtos estoque[100];
int quantidade_vendida[100] = {0}; // Quantidade vendida por produto

// Declaração de funções
void controle_estoque();
void menu_principal();
void financeiro();
void controle_vendas();
void pagamento(int total);
void relatorio_final();

// Adiciona produtos ao estoque
void controle_estoque() {
    printf("Quantos produtos deseja adicionar ao estoque? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o %dº produto:\n", i + 1);
        scanf(" %s", estoque[i].nome);
        printf("Digite o preço do %dº produto:\n", i + 1);
        scanf("%f", &estoque[i].preco);
    }
}

// Faz as vendas
void controle_vendas() {
    int escolha_3, quant, total = 0;
    float valor;
    char continuar;

    do {
        printf("\n---------------------------------------------\n");
        printf("VENDAS\n");

        for (int i = 0; i < n; i++) {
            printf("%d - %s -- R$ %.2f\n", 301 + i, estoque[i].nome, estoque[i].preco);
        }
        printf("300 - Voltar ao menu principal\n");
        printf("Escolha um código de produto: ");
        scanf("%d", &escolha_3);

        if (escolha_3 >= 301 && escolha_3 < 301 + n) {
            int index = escolha_3 - 301;
            printf("Digite a quantidade: ");
            scanf("%d", &quant);
            valor = estoque[index].preco * quant;
            total = total + valor;
            quantidade_vendida[index] += quant;
            printf("Valor total desta compra: R$ %.2f\n", valor);
        } else if (escolha_3 == 300) {
            return;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

        printf("\nDeseja fazer outra compra? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    pagamento(total);
}

// Faz o pagamento
void pagamento(int total) {
    float recebido, troco;
    int escolha_pagamento;
    float desconto = 0.0, valor_final;

    printf("\nForma de Pagamento:\n");
    printf("1 - Dinheiro (com desconto)\n");
    printf("2 - Cartão\n");
    printf("Escolha a forma de pagamento: ");
    scanf("%d", &escolha_pagamento);

    if (escolha_pagamento == 1) {
        if (total <= 50) {
            desconto = 0.05;
        } else if (total < 100) {
            desconto = 0.10;
        } else {
            desconto = 0.18;
        }
        valor_final = total * (1 - desconto);
        printf("Total com desconto: R$ %.2f\n", valor_final);
        printf("Digite o valor recebido: R$ ");
        scanf("%f", &recebido);
        troco = recebido - valor_final;
        printf("Troco: R$ %.2f\n", troco);
        rec = rec + valor_final;
    } else if (escolha_pagamento == 2) {
        int status_cartao;
        do {
            printf("Pagamento na máquina realizado? (1 - Sim / 0 - Não): ");
            scanf("%d", &status_cartao);
        } while (status_cartao != 1);
        rec = rec + total;
    } else {
        printf("Opção inválida. Tente novamente.\n");
        pagamento(total);
    }
}

// Parte financeira
void financeiro() {
    int escolha_2, valor;

    while (1) {
        printf("\n---------------------------------------------\n");
        printf("CONTROLE FINANCEIRO\n");
        printf("201 - Registrar Despesas\n");
        printf("202 - Registrar Receitas\n");
        printf("203 - Consultar Saldo\n");
        printf("204 - Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha_2);

        switch (escolha_2) {
            case 201:
                printf("Digite o valor da despesa: R$ ");
                scanf("%d", &valor);
                des = des + valor;
                printf("Despesa registrada!\n");
                break;
            case 202:
                printf("Digite o valor da receita: R$ ");
                scanf("%d", &valor);
                rec = rec + valor;
                printf("Receita registrada!\n");
                break;
            case 203:
                printf("Saldo atual: R$ %d\n", rec - des);
                break;
            case 204:
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

// Relatório final
void relatorio_final() {
    printf("\n---------------------------------------------\n");
    printf("RELATÓRIO FINAL DO DIA\n");
    printf("Produtos vendidos:\n");
    for (int i = 0; i < n; i++) {
        if (quantidade_vendida[i] > 0) {
            printf("%s - Quantidade: %d - Total: R$ %.2f\n", estoque[i].nome, quantidade_vendida[i], estoque[i].preco * quantidade_vendida[i]);
        }
    }
    printf("Total de receitas: R$ %d\n", rec);
    printf("Total de despesas: R$ %d\n", des);
    printf("Saldo final: R$ %d\n", rec - des);
}

// Menu principal
void menu_principal() {
    int escolha;

    while (1) {
        printf("\n---------------------------------------------\n");
        printf("MENU PRINCIPAL\n");
        printf("1 - Controle de Estoque\n");
        printf("2 - Controle Financeiro\n");
        printf("3 - Controle de Vendas\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                controle_estoque();
                break;
            case 2:
                financeiro();
                break;
            case 3:
                if (n == 0) {
                    printf("Nenhum produto cadastrado no estoque.\n");
                } else {
                    controle_vendas();
                }
                break;
            case 4:
                relatorio_final();
                printf("\nPrograma encerrado!\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

int main() {
    menu_principal();
    return 0;
}
