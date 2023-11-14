#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura de dados com vetor de inteiros
typedef struct {
    int* array;
    int size;
} DataStructure;

// Fun��o para preencher um vetor com n�meros aleat�rios
void fillRandom(DataStructure* data) {
    srand(time(NULL));
    for (int i = 0; i < data->size; ++i) {
        data->array[i] = rand() % 1000;  // Ajuste o intervalo conforme necess�rio
    }
}

// Fun��o para preencher um vetor ordenado ascendentemente
void fillSortedAsc(DataStructure* data) {
    for (int i = 0; i < data->size; ++i) {
        data->array[i] = i + 1;
    }
}

// Fun��o para preencher um vetor ordenado descendentemente
void fillSortedDesc(DataStructure* data) {
    for (int i = 0; i < data->size; ++i) {
        data->array[i] = data->size - i;
    }
}

// Fun��o para exibir o vetor
void printArray(DataStructure* data) {
    printf("Vetor: ");
    for (int i = 0; i < data->size; ++i) {
        printf("%d ", data->array[i]);
    }
    printf("\n");
}

// Fun��o para realizar a troca de dois elementos em um vetor
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// M�todo de ordena��o: Sele��o
void selectionSort(DataStructure* data, int* comparisons, int* swaps) {
    for (int i = 0; i < data->size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < data->size; ++j) {
            (*comparisons)++;
            if (data->array[j] < data->array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&data->array[i], &data->array[minIndex]);
            (*swaps)++;
        }
    }
}

// M�todo de ordena��o: Bolha
void bubbleSort(DataStructure* data, int* comparisons, int* swaps) {
    for (int i = 0; i < data->size - 1; ++i) {
        for (int j = 0; j < data->size - i - 1; ++j) {
            (*comparisons)++;
            if (data->array[j] > data->array[j + 1]) {
                swap(&data->array[j], &data->array[j + 1]);
                (*swaps)++;
            }
        }
    }
}

// M�todo de ordena��o: Inser��o
void insertionSort(DataStructure* data, int* comparisons, int* swaps) {
    for (int i = 1; i < data->size; ++i) {
        int key = data->array[i];
        int j = i - 1;

        (*comparisons)++;
        while (j >= 0 && data->array[j] > key) {
            data->array[j + 1] = data->array[j];
            (*swaps)++;
            j--;
        }
        data->array[j + 1] = key;
    }
}

int main() {
    int sizes[] = {5, 50, 5000, 30000};

    for (int k = 0; k < 4; ++k) {
        int size = sizes[k];
        DataStructure data;
        data.size = size;
        data.array = (int*)malloc(size * sizeof(int));

        // Vetor ordenado ascendente
        fillSortedAsc(&data);
        printf("\nVetor Ordenado Ascendente (Tamanho %d):\n", size);

        int comparisons = 0, swaps = 0;

        // Sele��o
        selectionSort(&data, &comparisons, &swaps);
        printf("\nSele��o - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Reinicializa para os pr�ximos testes
        fillSortedAsc(&data);
        comparisons = 0;
        swaps = 0;

        // Bolha
        bubbleSort(&data, &comparisons, &swaps);
        printf("Bolha - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Reinicializa para os pr�ximos testes
        fillSortedAsc(&data);
        comparisons = 0;
        swaps = 0;

        // Inser��o
        insertionSort(&data, &comparisons, &swaps);
        printf("Inser��o - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Vetor ordenado descendente
        fillSortedDesc(&data);
        printf("\nVetor Ordenado Descendente (Tamanho %d):\n", size);

        // Sele��o
        selectionSort(&data, &comparisons, &swaps);
        printf("\nSele��o - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Reinicializa para os pr�ximos testes
        fillSortedDesc(&data);
        comparisons = 0;
        swaps = 0;

        // Bolha
        bubbleSort(&data, &comparisons, &swaps);
        printf("Bolha - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Reinicializa para os pr�ximos testes
        fillSortedDesc(&data);
        comparisons = 0;
        swaps = 0;

        // Inser��o
        insertionSort(&data, &comparisons, &swaps);
        printf("Inser��o - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Vetor aleat�rio 1
        fillRandom(&data);
        printf("\nVetor Aleat�rio 1 (Tamanho %d):\n", size);

        // Sele��o
        selectionSort(&data, &comparisons, &swaps);
        printf("\nSele��o - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Reinicializa para os pr�ximos testes
        fillRandom(&data);
        comparisons = 0;
        swaps = 0;

        // Bolha
        bubbleSort(&data, &comparisons, &swaps);
        printf("Bolha - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Reinicializa para os pr�ximos testes
        fillRandom(&data);
        comparisons = 0;
        swaps = 0;

        // Inser��o
        insertionSort(&data, &comparisons, &swaps);
        printf("Inser��o - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Vetor aleat�rio 2
        fillRandom(&data);
        printf("\nVetor Aleat�rio 2 (Tamanho %d):\n", size);

        // Sele��o
        selectionSort(&data, &comparisons, &swaps);
        printf("\nSele��o - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Reinicializa para os pr�ximos testes
        fillRandom(&data);
        comparisons = 0;
        swaps = 0;

        // Bolha
        bubbleSort(&data, &comparisons, &swaps);
        printf("Bolha - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        // Reinicializa para os pr�ximos testes
        fillRandom(&data);
        comparisons = 0;
        swaps = 0;

        // Inser��o
        insertionSort(&data, &comparisons, &swaps);
        printf("Inser��o - Comparacoes: %d, Trocas: %d\n", comparisons, swaps);

        free(data.array);
    }

    return 0;
}
