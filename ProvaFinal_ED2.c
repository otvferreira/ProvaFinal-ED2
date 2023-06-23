#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Otávio Augusto Ferreira
// 23/06/2023

void gerarVetor(int vetor[], int tamanho) {

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }
}


void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}


void insertionSort(int vetor[], int tamanho) {
    int i, j, chave;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
    printf("\n");
}

void merge(int vetor[], int inicio, int meio, int fim) {
    int i, j, k;
    int tamanho_esq = meio - inicio + 1;
    int tamanho_dir = fim - meio;

    int esquerda[tamanho_esq], direita[tamanho_dir];

    for (i = 0; i < tamanho_esq; i++) {
        esquerda[i] = vetor[inicio + i];
    }
    for (j = 0; j < tamanho_dir; j++) {
        direita[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;
    while (i < tamanho_esq && j < tamanho_dir) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanho_esq) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanho_dir) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
    printf("\n");
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
    printf("\n");
}

void buscaSequencial(int vetor[], int tamanho, int valor) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            printf(" %d encontrado na posicao %d.\n", valor, i);
            return;
        }
    }
    printf("Valor %d nao encontrado.\n", valor);
}

void buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valor) {
            printf("Valor %d encontrado na posicao %d.\n", valor, meio);
            return;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("%d não encontrado.\n", valor);
}

int main() {
    int vetor[1000];
    int tamanho = 0;
    char opcao;
    int tamvet = 0;
    char IOUM;

    do {
        printf("\n----- MENU -----\n");
        printf("A. Gerar vetor\n");
        printf("B. Ordenar vetor\n");
        printf("C. Busca sequencial\n");
        printf("D. Busca binaria\n");
        printf("E. Sair\n\n");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'A':
                printf("Tamanho do vetor: ");
                scanf("%d", &tamvet);
                printf("\n");

                gerarVetor(vetor, tamvet);
                tamanho = tamvet;
                exibirVetor(vetor, tamanho);

                break;

            case 'B':
                if (tamanho == 0) {
                    printf("O vetor nao foi gerado. Opcao A para gerar o vetor.\n\n");
                } else {
                    printf("Escolha o metodo de ordenacao \n I - Insertion Sort \n M - Merge Sort \n ");
                    scanf(" %c", &IOUM);

                    if (IOUM == 'I' || IOUM == 'i') {
                        insertionSort(vetor, tamanho);
                        printf("Ordenado por Insertion Sort\n");

                    } else if (IOUM == 'M' || IOUM == 'm') {
                        mergeSort(vetor, 0, tamanho - 1);
                        printf("Ordenado por Merge Sort\n");

                    } else {
                        printf("Opcao invalida\n");
                    }
                    exibirVetor(vetor, tamanho);
                }

                break;

            case 'C':

                if (tamanho == 0) {
                    printf("O vetor nao foi gerado. Por favor, escolha a opcao A para gerar o vetor.\n");

                } else {
                    printf("Digite um numero para buscar no vetor: ");
                    scanf("%d", &tamvet);
                    buscaSequencial(vetor, tamanho, tamvet);


                }
                break;
            case 'D':
                if (tamanho == 0) {
                    printf("O vetor nao foi gerado. Por favor, escolha a opcao A para gerar o vetor.\n");

                } else {
                    printf("Digite um numero para buscar no vetor: ");
                    scanf("%d", &tamvet);
                    buscaBinaria(vetor, tamanho, tamvet);

                }
                break;
            case 'E':
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;

            }

    } while (opcao != 'E');

    return 0;
}
