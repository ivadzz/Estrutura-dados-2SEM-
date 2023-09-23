#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

void swapStrings(char xp, char yp) {
    char temp = xp;
    xp = yp;
    yp = temp;
}



int main(int argc, char argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    FILE *entrada = fopen(argv[1], "r");
    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }


    int numPalavras = 0;
    char palavra[100]; 

    while (fscanf(entrada, "%s", palavra) != EOF) {
        numPalavras++;
    }

  
    fseek(entrada, 0, SEEK_SET);

   
    char *palavras[numPalavras];

    for (int i = 0; i < numPalavras; i++) {
        fscanf(entrada, "%s", palavra);
        palavras[i] = strdup(palavra);
    }

   
    bubbleSortStrings(palavras, numPalavras);

   
    char *arq_palavras_ordenado= "arq_palavras_ordenado";

  
    FILE *saida = fopen(arq_palavras_ordenado, "w");
    if (saida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

   
    for (int i = 0; i < numPalavras; i++) {
        fprintf(saida, "%s\n", palavras[i]);
    }

   
    fclose(entrada);
    fclose(saida);

   
    for (int i = 0; i < numPalavras; i++) {
        free(palavras[i]);
    }

    printf("As palavras foram ordenadas com sucesso e salvas em %s.\n", arq_palavras_ordenado);

    return 0;
}
