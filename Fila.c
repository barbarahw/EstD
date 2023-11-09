#include <stdio.h>
#include <stdlib.h>

//struct no
typedef struct no{
	int dado;
	struct no *prox;
}no;

//struct fila
typedef struct fila{
	struct no *inicio;
	struct no *fim;
}fila;

no *aux;

fila* criaFila(){
	fila *f= (fila *) malloc(sizeof(fila));
	if (f!=NULL){
		f->inicio = NULL;
		f->fim = NULL;
	}
	return f;
}

void enfileirar(fila *f){
	no *novo = (no *)malloc(sizeof(no));
	printf("informe o numero a ser inserido:\n");
	scanf("%d", &novo->dado);
	novo->prox=NULL;
	if (f->inicio==NULL){
        f->fim=novo;
        f->inicio=novo;
	}
	else {
        f->fim->prox=novo;
        f->fim=novo;
	}
	printf("Numero inserido na fila!\n");
}

void desenfileirar(fila *f) {
    if (f->fim==NULL) {
        printf("Fila vazia!\n");
    } else {
        aux=f->inicio;
        printf("%d removido!\n", f->inicio->dado);
        f->inicio=f->inicio->prox;
        free(aux);
    }
}

void consultarFila(fila *f){
    if (f->fim==NULL){
        printf("Fila vazia!\n");
    }
    else {
        aux=f->inicio;
        do {
            printf(" %d ", aux->dado);
            aux=aux->prox;
        }while(aux!=NULL);
        printf("\n");
    }
}

void esvaziarFila(fila *f) {
    if (f->fim==NULL){
        printf("Fila vazia!\n");
    }
    else {
        aux = f->inicio;
        do{
            f->inicio=f->inicio->prox;
            free(aux);
            aux=f->inicio;
        }while(aux!=NULL);
        printf("Pilha esvaziada!\n");
    }
}


int main() {
    int escolha;
    fila *f = criaFila();

    do {
        printf("1-Enfileirar\n2-Desenfileirar\n3-Consultar fila\n4-Esvaziar fila\n0-Sair\n");
        scanf("%d", &escolha);
        switch (escolha){
            case 1: enfileirar(f); break;
            case 2: desenfileirar(f); break;
            case 3: consultarFila(f); break;
            case 4: esvaziarFila(f); break;
        }
    } while (escolha!=0);


    return 0;
}
