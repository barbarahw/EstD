#include <stdio.h>
#include <stdlib.h>

//struct no
typedef struct no{
	int dado;
	struct no *prox;
}no;

//struct pilha
typedef struct PILHA{
	struct no *topo;
}pilha;

no *aux;

pilha* criaPilha(){
	pilha *p= (pilha *) malloc(sizeof(pilha));
	if (p!=NULL){
		p->topo = NULL; //topo da pilha inicia null
	}
	return p;
}

void empilhar(pilha *p){
	no *novo = (no *)malloc(sizeof(no));
	printf("informe o numero a ser inserido:\n");
	scanf("%d", &novo->dado);
	novo->prox = p->topo;
	p->topo = novo;
	printf("numero inserido na pilha!\n");
}

void desempilhar(pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
    } else {
        aux = p->topo;
        printf("%d removido!\n", p->topo->dado);
        p->topo = p->topo->prox;
        free(aux);
    }
}

void consultarPilha(pilha *p){
    if (p->topo==NULL){
        printf("Pilha vazia!\n");
    }
    else {
        aux=p->topo;
        do {
            printf(" %d \n", aux->dado);
            aux=aux->prox;
        }while(aux!=NULL);
    }
}

void esvaziarPilha(pilha *p) {
    if (p->topo==NULL){
        printf("pilha vazia!\n");
    }
    else {
        aux=p->topo;
        do{
            p->topo=p->topo->prox;
            free(aux);
            aux=p->topo;
        }while(aux!=NULL);
        printf("´Pilha esvaziada!\n");
    }
}


int main() {
    int escolha;
    pilha *p = criaPilha();

    do {
        printf("1-Empilhar\n2-Desempilhar\n3-Consultar pilha\n4-Esvaziar pilha\n0-Sair\n");
        scanf("%d", &escolha);
        switch (escolha){
            case 1: empilhar(p); break;
            case 2: desempilhar(p); break;
            case 3: consultarPilha(p); break;
            case 4: esvaziarPilha(p); break;
        }
    } while (escolha>0);


    return 0;
}
