#include <stdio.h>
int controle_vendas();
int menu_principal();
void financeiro(int rec,int des);
int controle_vendas(){
    int a = 22;
    int b = 40;
    int c = 53;
    int valor;
    int quant;
    int menu_principal();
    int escolha_3;
    printf("--------------------------------------------------------------------------\n");
    printf("Vendas \n");
    printf("     *Itens Disponíveis: \n \n");
    printf("301 - Produto A -- R$22,00 \n");
    printf("302 - Produto B -- R$40,00 \n");
    printf("303 - Produto C -- R$53,00 \n");
    printf("304 - voltar ao menu principal? \n\n");
    printf("Selecione o código do o produto a ser vendido:  \n");
    scanf("%d" , &escolha_3);
    

    switch(escolha_3){
        case 301:
            printf("Digite a quantidade que o cliente esta comprando: ");
            scanf("%d" , &quant );
            valor = a * quant;
            printf("%d" , valor);
            return 1;
        case 302:
            printf("Digite a quantidade que o cliente esta comprando: ");
            scanf("%d" , &quant );
            valor = b * quant;
            printf("%d" , valor);
            return 1;
        case 303:
            printf("Digite a quantidade que o cliente esta comprando: ");
            scanf("%d" , &quant );
            valor = c * quant;
            printf("%d" , valor);
            return 1;
        case 304:
            menu_principal();
            break;
        default: 
            controle_vendas();
            return 1;
    }
}

void financeiro(int rec,int des){
    
    int s;
    int escolha_2;
    printf("\n------------------------------------------------------------------------------ \n");
    printf("Controle financeiro \n");
    printf("     *Opções: \n \n");
    printf("201 - Registrar Despesas \n");
    printf("202 - Registrar Receitas \n");
    printf("203 - Consultar Saldo \n");
    printf("204 - Voltar ao menu principal?\n\n");
        
    printf("Selecione as opcoẽs:\n ");
    scanf("%d" , &escolha_2);
    switch(escolha_2){
        case 201:
        printf("Digite o valor da despesa R$: ");
        scanf("%d" , &des);
        financeiro(rec,des);
        break;
        case 202:
        printf("Digite o valor da receita R$: ");
        scanf("%d" , &rec);
        financeiro(rec,des);
        break;
        case 203:
        s = rec - des;
        printf("Saldo é igual a R$: %d " , s);
        financeiro(rec,des);
        break;
        case 204:
        menu_principal();
        break;
        default:
        financeiro(rec,des);
        break;
    }
            
}

int rec;
int des;
int menu_principal(){
int escolha;
int sair;
int estoque;
printf("Menu: \n\n 1. Controle estoque \n 2. Controle finaceiro \n 3. Controle vendas \n 4. Sair \n\n Selecione: ");
scanf("%d" , &escolha);

switch( escolha ){
    case 1 :
    printf("-------------------------------------------------------------------------- \n");
    printf("Controle de estoque \n");
    printf("     *Itens Disponíveis: \n \n");
    printf("   101 - Produto A -- 10 unidades; \n");
    printf("   102 - Produto B -- 23 unidades; \n");
    printf("   103 - Produto C -- 31 unidades: \n \n");
    printf("Voltar ao menu principal? \n");
    printf("Digite s para voltar e n para ficar. ");
    scanf(" %c" , &sair);
    
    if( sair == 's'){
        menu_principal();
    }else{
        printf("Programa encerrado!");
    }
    
    break;
    case 2:
    financeiro(rec,des);
    break;
    
    case 3 :
    controle_vendas();
    break;
    
    case 4 :
    printf("\n--------------------------------------------------------------------------\n");
    printf("Programa encerrado!");
    return 4;
    default:
    printf("\n--------------------------------------------------------------------------\n");
    printf("Opção Inválida \n");
    break;
    }
    
}


int main(){
    menu_principal();
    return 0;
}
