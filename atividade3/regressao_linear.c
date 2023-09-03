#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    float y;
} Ponto;

double calcular_media(double* valores, int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += valores[i];
    }
    return soma / n;
}

double calcular_coeficiente(Ponto* pontos, int n, double media_x, double media_y) {
    double numerador = 0;
    double denominador = 0;
void calcularRegressao(FILE *file, Ponto *pontos, int num_pontos) {
    int i;
    int somX = 0;
    float somY = 0;
    float somXY = 0;
    float somXX = 0;

    for (int i = 0; i < n; i++) {
        numerador += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        denominador += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    for (i = 0; i < num_pontos; i++) {
        fscanf(file, "%d,%f", &(pontos[i].x), &(pontos[i].y));
        somX += pontos[i].x;
        somY += pontos[i].y;
        somXY += pontos[i].x * pontos[i].y;
        somXX += pontos[i].x * pontos[i].x;
    }

    return numerador / denominador;
    float avgX = (float)somX / num_pontos;
    float avgY = somY / num_pontos;

    float inclin = (somXY - num_pontos * avgX * avgY) / (somXX - num_pontos * avgX * avgX);

    float intercept = avgY - inclin * avgX;

    printf("y = %fx + %f\n", inclin, intercept);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <.csv>\n", argv[0]);
        printf("Modo de uso: ./regressao <arquivo.csv>\n");
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    
    int num_pontos = 0;
    fscanf(arquivo, "%d", &num_pontos);

    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            num_pontos++;
        }
    }
    rewind(file);

    Ponto *pontos = (Ponto *)malloc(num_pontos * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro na alocação de memória.\n");
        printf("Erro ao alocar memória.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < num_pontos; i++) {
        fscanf(arquivo, "%d,%.2f", &pontos[i].x, &pontos[i].y);
    }

    
    calcularRegressao(file, pontos, num_pontos);

    free(pontos);
    fclose(file);

    return 0;
}