#include <stdio.h>
#include <string.h>

int existeNoArray(char *array[], int tamanho, char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1;  
        }
    }
    return 0;  
}

int main() {
    char *nomes[] = {"texto", "J", "EDA", "EDO"};
    int tamanho = sizeof(nomes) / sizeof(nomes[0]);
    
    char busca[50];
    printf("Digite um nome para buscar: ");
    scanf("%s", busca);

    if (existeNoArray(nomes, tamanho, busca)) {
        printf("1 - A string de busca existe no array.\n");
    } else {
        printf("0 - A string de busca não existe no array.\n");
    }

    return 0;
}
