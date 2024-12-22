#include "selection_sort.h"

void selection_sort(int v[], int tam) {
    
    for (int i = 0; i < tam - 1; i++) {

        int min = i; // Salva a posição do menor valor
        for (int j = i + 1; j < tam; j++) {

            if (v[min] > v[j]) { // Verifica se o vetor na posição min é maior que um dos valores subsequentes
                min = j; // Se for maior min guarda a posição do menor valor
            }

        }

        if (v[min] != v[i]) { // Verifica se min e i são diferentes para fazer a troca de valores
            
            int aux = v[min];
            v[min] = v[i];
            v[i] = aux;
        }
    }
}