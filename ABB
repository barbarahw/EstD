#include <stdlib.h>
#include <stdio.h>

typedef struct no {
	int conteudo; //dado aramazenado em cada nó
	struct no *esquerda, *direita; //ponteiro para conteúdo a esquerda e a direita
}No;

typedef struct {
	No *raiz;
}ArvB;

void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);

void inserirEsquerda (No *no, int valor){
    if (no->esquerda == NULL) {
        No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		no->esquerda = novo;
    }
    else {
        if (valor < no->esquerda->conteudo){
            inserirEsquerda(no->esquerda, valor);
        }
        else {
            inserirDireita(no->esquerda, valor);
        }
    }
    
}

void inserirDireita (No *no, int valor){
    if (no->direita == NULL) {
        No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		no->direita = novo;
    }
    else {
        if (valor < no->direita->conteudo){
            inserirEsquerda(no->esquerda, valor);
        }
        else {
            inserirDireita(no->esquerda, valor);
        }
    }
}

void inserir (ArvB *arv, int valor) {
	if (arv->raiz == NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		arv->raiz = novo;
	}
	else {
		if (valor < arv->raiz->conteudo){
		   inserirEsquerda(arv->raiz, valor);
		}
		else 
		    inserirDireita(arv->raiz, valor);
			
	}
}

void imprimir(No *raiz){
    if (raiz != NULL){
      printf("%d \n", raiz->conteudo);
      imprimir (raiz->esquerda);
      imprimir(raiz->direita);
    }
}

int main (){

    int op, valor;
    ArvB arvore;
    arvore.raiz = NULL;

    do{
      printf("\n0-Sair \n1-Inserir \n2-Imprimir\n");
      scanf("%d", &op);

      switch (op){
        case 0: 
          printf("programa encerrado!"); 
            break;
        case 1: 
          printf("\nInforme o valor a ser inserido: \n");
          scanf("%d", &valor);
          inserir(&arvore, valor); 
          printf("Valor inserido!\n");
          break;
        case 2:
          printf("\nImpressão da árvore:\n");
          imprimir(arvore.raiz);
          break;
        default:
        printf("\nOpção inválida!\n");
      }
    }while(op!=0);

    return 0;
}
