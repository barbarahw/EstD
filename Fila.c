#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dado;
    struct NO* prox;
    struct NO* ant;
}NO;

NO* inicio;
NO* final;
NO* aux;

void enfileirar();

void desenfileirar();

void imprimirFila();

int main() {
    inicio = NULL;
    final = NULL;
        
    enfileirar();
    enfileirar();
    enfileirar();
    enfileirar();
    imprimirFila();
    
    return 0;
}


void enfileirar(){
    NO* novo = malloc(sizeof(NO));
    printf("Informe o novo dado: ");
    scanf("%d", &novo->dado);
    if (inicio == NULL){
        inicio = novo;
        novo->prox = NULL;
        novo->ant = NULL;
    }
    else{
        novo->ant = final;
        final->prox = novo;
        novo->prox = NULL;
    }
    final = novo;
    
    printf("O elemento foi inserido!\n");
}

void desenfileirar(){
    if (inicio == NULL)
        printf("A fila está vazia!\n");
    else{
        aux = inicio;
        printf("O elemento %d foi removido\n", aux->dado);
        inicio = inicio->prox;
        free(aux);

        if (inicio == NULL) {
            final = NULL;
        }
    }
}

void imprimirFila() {
    if (inicio == NULL)
        printf("Fila vazia!");
    else {
        aux = inicio;
        printf("Fila: ");
        while(aux != NULL){
            printf("%d\t", aux->dado);
            aux=aux->prox;
        }
    }
}
