# Ordenação de Vetores com Selection Sort e Insertion Sort

## 📄 Descrição
Implementação de dois algoritmos de ordenação em linguagem C: **Selection Sort** e **Insertion Sort**. O programa compara o desempenho desses algoritmos medindo o tempo de execução e armazena os números ordenados em arquivos de saída.

Os números a serem ordenados são lidos de arquivos de entrada, e os resultados são salvos em arquivos de saída separados para cada algoritmo.

---

## 🗂️ Estrutura dos Arquivos

- **src**: Contém os arquivos de implementação.
- **include**: Contém os arquivos de cabeçalho.
- **instancias-num**: Contém os arquivos de entrada com os números a serem ordenados.
- **instancias_output**: Contém os arquivos de saida com os números já ordenados
- **instancias_output/sorted_numbers1.out**: Arquivo de saída com os números ordenados pelo algoritmo Selection Sort.
- **instancias_output/sorted_numbers2.out**: Arquivo de saída com os números ordenados pelo algoritmo Insertion Sort.
-  **Makefile:** Arquivo de configuração para a compilação.

---

## ⚙️ Como Compilar e Executar

### Compilando o Código

```bash
make
```

### Executando o Programa

```bash
./bin/programa
```

O programa irá:
- Ler os números do arquivo de entrada.
- Ordenar os números usando Selection Sort e Insertion Sort.
- Medir o tempo de execução de cada algoritmo.
- Salvar os resultados em arquivos de saída.

---

## 🖥️ Saída do Programa
O programa exibirá no terminal o tempo de execução de cada algoritmo em segundos:

```
Tempo de execucao do selection_sort: 0.042000000 segundos
Tempo de execucao do insertion_sort: 0.033000000 segundos
Ordenacao concluida!
```

Esses valores variam, mas a média é por volta desse intervalo com o insertion sort sendo mais rápido.

---

## 📚 Detalhes dos Algoritmos

### Selection Sort
- O algoritmo busca o menor elemento do vetor e troca de posição com o elemento da posição atual.
- Complexidade: O(n²).

### Insertion Sort
- O algoritmo insere cada elemento em sua posição correta, considerando as partes já ordenadas do vetor.
- Complexidade: O(n²).
