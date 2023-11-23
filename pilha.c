#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dado;
    struct NO* prox;
}NO;

NO* topo;

void empilhar();
void desempilhar();
void imprimirPilha();

int main() {
    topo=NULL;
    empilhar();
    empilhar();
    empilhar();
    imprimirPilha();
    return 0;
}

void empilhar(){
    NO* novo = (NO*)malloc(sizeof(NO));
    printf("informe o novo dado: ");
    scanf("%d", &novo->dado);
    
    novo->prox = topo;
    topo = novo;

    printf("Elemento inserido!\n");
}

void desempilhar(){
    if (topo == NULL)
        printf("Não há elementos na pilha!\n");
    else {
        NO* aux;
        aux = topo;
        topo = topo->prox;
        printf("O elemento %d foi removido!\n", aux->dado);
        free(aux);
    }
}

void imprimirPilha(){
    if (topo == NULL)
        printf("A pilha esstá vazia!");
    else{
        NO* aux;
        aux = topo;
        while(aux!=NULL){
            printf("Pilha:\n");
            printf("%d\t", aux->dado);
            aux = aux->prox;
        }
    }
    printf("\n");
}
