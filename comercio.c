#include <stdio.h>

int main(){
    char escolha;
    char sair;
    char estoque;
    printf("Digite e para estoque, v para venda, f para finaceiro, digite s para sair: ");
    scanf("%c" , &escolha);
     
    
    
    switch( escolha ){
        case 'e':
            printf("Controle de estoque: \n");
            printf("----------------------------------------------------------------------------------- \n");
            printf(" Itens disponíveis: \n \n");
            printf("   101 - produto A -- 10 un; \n");
            printf("   102 - produto B -- 23 un; \n");
            printf("   103 - produto C -- 31 un: \n \n");
            
            printf("Você deseja sair do programa? \n");
            printf("Para sair digite s, para voltar digite v: ");
            scanf(" %c" , &sair);
            switch(sair){
                case 's':
                    printf("Programa encerrado \n");
                    break;
                    }
            printf("   \n");
            
            break;
            
            
        case 'v' :   
            printf("Controle de venda \n");
            break;
        case 'f':
            printf("Controle financeiro \n");
            break;
        case 's':
            printf("Programa encerrado");
            break;
        default:
            printf("Opção invalida \n");
            break;
    }
/* 
*/

    return 0;
}
