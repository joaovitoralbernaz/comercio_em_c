#include <stdio.h>

// Variáveis globais
int rec = 0;
int des = 0;

struct produtos{
    char nome[15];
    float preco;
};
// Declaração de funções

void controle_estoque();
void menu_principal();
void financeiro();
void controle_vendas();
void pagamento(int total);



void controle_estoque(){
    int n;
    printf("Quantos produtos deseja adicionar ao estoque ? ");
    scanf("%d" , &n);
    struct produtos estoque[n];
    
    for( int i = 0; i < n ; i++ ){
        printf("Digite o %dº produto:\n " , (i + 1));
        scanf(" %s" , &estoque[i].nome);
        printf("Digite o preço do %d° produto:\n " , (i + 1));
        scanf("%f" , &estoque[i].preco);
    }
    
    printf(" %s" , &estoque[1].nome);
    printf("%f" , &estoque[1].preco);
}

//Faz as vendas
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
                total = total + valor;
                printf("Valor total da compra: R$ %d\n", valor);
                break;
            case 302:
                printf("Digite a quantidade: ");
                scanf("%d", &quant);
                valor = b * quant;
                total = total + valor;
                printf("Valor total da compra: R$ %d\n", valor);
                break;
            case 303:
                printf("Digite a quantidade: ");
                scanf("%d", &quant);
                valor = c * quant;
                total = total + valor;
                printf("Valor total da compra: R$ %d\n", valor);
                break;
            case 304:
                return;  // Retorna ao menu principal
            default:
                printf("Opção inválida. Tente novamente.\n");
                controle_vendas();
        }
        
        //Pergunta ao usuário se ele quer fazer outra compra ou não
        printf("\nDeseja fazer outra compra? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    
    pagamento(total);
}

//Faz o pagamento
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

//Mostra e registra os valores na parte financeira
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
                return;  // Retorna ao menu principal
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

//Mostra o menu, onde tem as funções principais 
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
            //Mostra todos os produtos disponíveis e a quantidade de cada um
            case 1:
                controle_estoque();
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
