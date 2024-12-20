# Projeto de Ordenação de Vetores com Selection Sort e Insertion Sort

## Descrição
Este projeto implementa dois algoritmos de ordenação clássicos em linguagem C: **Selection Sort** e **Insertion Sort**. O programa compara o desempenho desses algoritmos medindo o tempo de execução e armazena os números ordenados em arquivos de saída.

Os números a serem ordenados são lidos de arquivos de entrada, e os resultados são salvos em arquivos de saída separados para cada algoritmo.

---

## Estrutura dos Arquivos

- **instancias-num/num.10000.1.in**: Arquivo de entrada contendo os números a serem ordenados.
- **sorted_numbers1.out**: Arquivo de saída com os números ordenados pelo algoritmo Selection Sort.
- **sorted_numbers2.out**: Arquivo de saída com os números ordenados pelo algoritmo Insertion Sort.

---

## Como Compilar e Executar

### Compilando o Código

```bash
gcc -o ordenacao main.c
```

### Executando o Programa

1. Certifique-se de que o arquivo de entrada **num.10000.1.in** esteja localizado no diretório **instancias-num/**.
2. Execute o programa com o seguinte comando:

```bash
./ordenacao
```

O programa irá:
- Ler os números do arquivo de entrada.
- Ordenar os números usando Selection Sort e Insertion Sort.
- Medir o tempo de execução de cada algoritmo.
- Salvar os resultados em arquivos de saída.

---

## Saída do Programa
O programa exibirá no terminal o tempo de execução de cada algoritmo em segundos:

```
Tempo de execucao do selection_sort: X.XXXXXXXXX segundos
Tempo de execucao do insertion_sort: Y.YYYYYYYYY segundos
Ordenacao concluida!
```

Os arquivos **sorted_numbers1.out** e **sorted_numbers2.out** conterão os números ordenados.

---

## Detalhes dos Algoritmos

### Selection Sort
- O algoritmo busca o menor elemento do vetor e troca de posição com o elemento da posição atual.
- Complexidade: O(n²).

### Insertion Sort
- O algoritmo insere cada elemento em sua posição correta, considerando as partes já ordenadas do vetor.
- Complexidade: O(n²).
