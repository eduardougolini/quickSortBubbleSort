#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

#define tam_vetor  8
int counter = 0;

void rapida(int *a, int esquerda, int direita);
void bubbleSort(int *vetor);
void read(int *vetor);
void write(int *vetor);

int main() {
    int vetor[tam_vetor];
    int vetorBs[tam_vetor];
    int aux;

    read(vetor);
    read(vetorBs);

    printf("Valores inseridos: ");
    for (int i = 0; i < tam_vetor; i++) // mostra os valores digitados
    {
        printf("  - %d", vetor[i]);
    }
    printf("\n\n\n\n\n\n\nQuickSort: \n");
    rapida(vetor, 0, tam_vetor - 1); // chamo a funcao recursiva
    printf("\n\n");


    printf("Resultado final QuickSort: ");
    for (int i = 0; i < tam_vetor; i++) {
        printf("  - %d", vetor[i]);
    }

    bubbleSort(vetorBs);
    printf("\n\n");

    printf("Resultado final BubbleSort: ");
    for (int i = 0; i < tam_vetor; i++) {
        printf("  - %d", vetorBs[i]);
    }

    write(vetor);
    printf("\n\n");
    system("pause");

    return (0);
}

void rapida(int *a, int esquerda, int direita) {
    int i, j, x, y;

    i = esquerda;
    j = direita;
    x = a[(esquerda + direita) / 2];

    while (i <= j) {
        while (a[i] < x && i < direita) // trecho que avanca a seta da esquerda
        {
            i++;
        }
        while (a[j] > x && j > esquerda) // trecho que retorna a seta da direita
        {
            j--;
        }
        if (i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    //// impressao de parciais
    printf("\n\n");

    printf("||%d||        ", counter);
    for (int i = 0; i < tam_vetor; i++) {
        printf("  - %d", a[i]);
    }
    counter++;

    ///////////////////////////


    if (j > esquerda) {
        rapida(a, esquerda, j);
    }
    if (i < direita) {
        rapida(a, i, direita);
    }
}

void bubbleSort(int *vetor) {
    printf("\n\n\nBubbleSort: \n");
    counter = 0;
    bool flare = true;

    while (true) {

        if (flare) {
            for (int i = 0; i < tam_vetor - 1; i++) {


                if (vetor[i] > vetor[i + 1]) {
                    int aux = vetor[i];
                    vetor[i] = vetor[i + 1];
                    vetor[i + 1] = aux;
                    flare = true;

                    printf("||%d||    ", counter);
                    for (int j = 0; j < tam_vetor; j++) {
                        printf("%d - ", vetor[j]);
                    }
                    counter++;
                    printf("\n");

                    break;
                } else {
                    flare = false;
                }

            }
        } else {
            break;
        }
    }
}

void read(int *vetor) {
    std::ifstream file("initialNumbers.txt");

    for (int i = 0; i < tam_vetor; i++) {
        file >> vetor[i];
    }
}

void write(int *vetor) {
    ofstream file("numberSort.txt");

    for (int i = 0; i < tam_vetor; i++) {
        file << vetor[i];
        file << " , ";
    }

    file.close();
}

