#include <stdio.h>

int main(){
    char escolha;
    char sair;
    char estoque;
    printf("Digite E para estoque, V para vendas, F para controle finaceiro e digite S para sair: ");
    scanf("%c" , &escolha);
     
     
    switch( escolha ){
        case 'E':
        printf("--------------------------------------------------------------------------------------------------- \n");
        printf("Controle de estoque \n");
        printf("     *Itens Disponíveis: \n \n");
        printf("   101 - Produto A -- 10 unidades; \n");
        printf("   102 - Produto B -- 23 unidades; \n");
        printf("   103 - Produto C -- 31 unidades: \n \n");
        printf("Voltar ao menu principal? \n");
        scanf(" %c" , &sair);
        switch(sair){
            case 'S':
            printf("Programa encerrado \n");
            break;
        }
        
        case 'F':
        printf("--------------------------------------------------------------------------------------------------- \n");
        printf("Controle financeiro \n");
        printf("     *Opções: \n \n");
        printf("201 - Registrar Despesas \n");
        printf("202 - Registrar Receitas \n");
        printf("203 - Consultar Saldo \n \n");
        printf("Voltar ao menu principal? \n");
        scanf(" %c" , &sair);
        switch(sair){
            case 'S':
            printf("Programa encerrado \n");
            break;
        }
        
        case 'V' :
        printf("--------------------------------------------------------------------------------------------------- \n");
        printf("Vendas \n");
        printf("     *Itens Disponíveis: \n \n");
        printf("301 - Produto A -- R$22,00 \n");
        printf("302 - Produto B -- R$40,00 \n");
        printf("303 - Produto C -- R$53,00 \n \n");
        printf("Voltar ao menu principal? \n");
        scanf(" %c" , &sair);
        switch(sair){
            case 'S':
            printf("Programa encerrado \n");
            break;
        }
       
        default:
        printf("Opção Inválida \n");
        break;
    }

    return 0;
}
