#include "insertion_sort.h"
#include "selection_sort.h"
#include <stdlib.h>
#include <time.h> 

int main(void) {

    // Abre o arquivo que será lido
    FILE *file1 = fopen("instancias-num/num.10000.1.in", "r");

    // Verifica se a abertura do arquivo foi bem sucedida
    if (file1 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Cria um vetor para armazenar os números do arquivo
    int vetor_selection[100001], vetor_insertion[100001];
    int n1 = 0, n2 = 0; // Variáveis auxiliares para contar a quantidade de numeros

    // Executa a leitura até chegar na última linha
    while (fscanf(file1, "%d", &vetor_selection[n1]) != EOF) {
        n1++;
    }

    // Fecha o arquivo
    fclose(file1);

    // Abre o arquivo que será lido
    FILE *file2 = fopen("instancias-num/num.10000.1.in", "r");

    // Verifica se a abertura do arquivo foi bem sucedida
    if (file2 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Executa a leitura até chegar na última linha
    while (fscanf(file2, "%d", &vetor_insertion[n2]) != EOF) {
        n2++;
    }

    // Fecha o arquivo
    fclose(file2);

    // Marca o tempo antes da execução
    clock_t inicio = clock(); 

    selection_sort(vetor_selection, n1);

    // Marca o tempo após a execução
    clock_t fim = clock(); 

    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do selection_sort: %.9lf segundos\n", tempo_execucao);

    // Marca o tempo antes da execução
    inicio = clock(); 

    insertion_sort(vetor_insertion, n2);

    // Marca o tempo após a execução
    fim = clock(); 

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do insertion_sort: %.9lf segundos\n", tempo_execucao);

    // Cria o arquivo que será guardado os números ordenados
    FILE *output1 = fopen("instancias_output/sorted_numbers1.out", "w");

    // Verifica se a criação do arquivo foi bem sucedida
    if (output1 == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        exit(1);
    }

    // Escreve os números no arquivo
    for (int i = 0; i < n1; i++) {
        fprintf(output1, "%d\n", vetor_selection[i]);
    }

    // Fecha o arquivo
    fclose(output1);

    // Cria o arquivo que será guardado os números ordenados
    FILE *output2 = fopen("instancias_output/sorted_numbers2.out", "w");

    // Verifica se a criação do arquivo foi bem sucedida
    if (output2 == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        exit(1);
    }

    // Escreve os números no arquivo
    for (int i = 0; i < n2; i++) {
        fprintf(output2, "%d\n", vetor_insertion[i]);
    }

    // Fecha o arquivo
    fclose(output2);

    printf("Ordenacao concluida!\n");
    
    return 0;
}
