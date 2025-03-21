#include <stdio.h>

// Variáveis globais para receitas e despesas
int rec = 0;
int des = 0;

// Declaração de funções
void menu_principal();
void financeiro();
void controle_vendas();
void pagamento(int total);

void controle_vendas() {
    int escolha_3, quant, valor, total = 0;
    int a = 22, b = 40, c = 53;
    char continuar;

    do {
        printf("\n---------------------------------------------\n");
        printf("VENDAS\n");
        printf("301 - Produto A -- R$22,00\n");
        printf("302 - Produto B -- R$40,00\n");
        printf("303 - Produto C -- R$53,00\n");
        printf("304 - Voltar ao menu principal\n");
        printf("Escolha um código de produto: ");
        scanf("%d", &escolha_3);

        switch (escolha_3) {
            case 301:
                printf("Digite a quantidade: ");
                scanf("%d", &quant);
                valor = a * quant;
                total += valor;
                printf("Valor total da compra: R$ %d\n", valor);
                break;
            case 302:
                printf("Digite a quantidade: ");
                scanf("%d", &quant);
                valor = b * quant;
                total += valor;
                printf("Valor total da compra: R$ %d\n", valor);
                break;
            case 303:
                printf("Digite a quantidade: ");
                scanf("%d", &quant);
                valor = c * quant;
                total += valor;
                printf("Valor total da compra: R$ %d\n", valor);
                break;
            case 304:
                return;  // Retorna ao menu principal
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }
        
        printf("\nDeseja fazer outra compra? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    
    pagamento(total);
}

void pagamento(int total) {
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
        float recebido, troco;
        printf("Total com desconto: R$ %.2f\n", valor_final);
        printf("Digite o valor recebido: R$ ");
        scanf("%f", &recebido);
        troco = recebido - valor_final;
        printf("Troco: R$ %.2f\n", troco);
        rec += valor_final;
    } else if (escolha_pagamento == 2) {
        int status_cartao;
        do {
            printf("Pagamento na máquina realizado? (1 - Sim / 0 - Não): ");
            scanf("%d", &status_cartao);
        } while (status_cartao != 1);
        rec += total;
    } else {
        printf("Opção inválida. Tente novamente.\n");
        pagamento(total);
    }
}

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
                des += valor;
                printf("Despesa registrada!\n");
                break;
            case 202:
                printf("Digite o valor da receita: R$ ");
                scanf("%d", &valor);
                rec += valor;
                printf("Receita registrada!\n");
                break;
            case 203:
                printf("Saldo atual: R$ %d\n", rec - des);
                break;
            case 204:
                return;  // Retorna ao menu principal
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

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
                printf("\nCONTROLE DE ESTOQUE\n");
                printf("101 - Produto A -- 10 unidades\n");
                printf("102 - Produto B -- 23 unidades\n");
                printf("103 - Produto C -- 31 unidades\n");
                break;
            case 2:
                financeiro();
                break;
            case 3:
                controle_vendas();
                break;
            case 4:
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
