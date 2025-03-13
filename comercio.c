#include <stdio.h>

void registrardespesas(){

}

void registrarreceita(){
    int valor;
    printf("Registrar valor: ");
    scanf("%d" , &valor);
    consultarsaldo(valor);
}

void consultarsaldo(int saldo){
    printf("%d" , saldo)
}

void menu_principal(){
    int escolha_2;
    int escolha;
    char sair;
    int estoque;
    printf("Menu principal: \n 1. Controle estoque \n 2. Controle finaceiro \n 3. Controle vendas \n 4. Sair \n ");
    scanf("%d" , &escolha);
    
    
    switch( escolha ){
        case 1 :
        printf("--------------------------------------------------------------------------------------------------- \n");
        printf("Controle de estoque \n");
        printf("     *Itens Disponíveis: \n \n");
        printf("   101 - Produto A -- 10 unidades; \n");
        printf("   102 - Produto B -- 23 unidades; \n");
        printf("   103 - Produto C -- 31 unidades: \n \n");
        printf("Voltar ao menu principal? \n");
        scanf(" %c" , &sair);
        if( sair == 's'){
            menu_principal();
        }else{
            printf("Programa encerrado!");
            break;
        }
        
        case 2:
        printf("--------------------------------------------------------------------------------------------------- \n");
        printf("Controle financeiro \n");
        printf("     *Opções: \n \n");
        printf("201 - Registrar Despesas \n");
        printf("202 - Registrar Receitas \n");
        printf("203 - Consultar Saldo \n \n");
        printf("Selecione as opcoẽs:\n ");
        scanf("%d" , &escolha_2);
        
        if( escolha_2 == 201){
            registrardespesas();
        }else if( escolha_2 == 202){
            registrarreceita();
        }else if ( escolha_2 == 203){
            consultarsaldo();
        }
        printf("Voltar ao menu principal? \n");
        scanf(" %c" , &sair);
        if( sair == 's'){
            menu_principal();
        }else{
            printf("Programa encerrado!");
            break;
        }
        
        case 3 :
        printf("--------------------------------------------------------------------------------------------------- \n");
        printf("Vendas \n");
        printf("     *Itens Disponíveis: \n \n");
        printf("301 - Produto A -- R$22,00 \n");
        printf("302 - Produto B -- R$40,00 \n");
        printf("303 - Produto C -- R$53,00 \n \n");
        printf("Voltar ao menu principal? \n");
        scanf(" %c" , &sair);
       if( sair == 's'){
            menu_principal();
        }else{
            printf("Programa encerrado!");
            break;
        }
        
      
       case 4 :
        printf("--------------------------------------------------------------------------------------------------- \n");
        printf("Programa encerrado!");
        break;
        
         
       
        default:
        printf("--------------------------------------------------------------------------------------------------- \n");
        printf("Opção Inválida \n");
        break;
    }
    
}


int main(){
    menu_principal();
    return 0;
}
