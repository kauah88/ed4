#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    FILE *arquivo;
    int numVertices;

    arquivo = fopen("vertices.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fscanf(arquivo, "%d", &numVertices);
    Ponto *pontos = (Ponto *)malloc(numVertices * sizeof(Ponto));

    for (int i = 0; i < numVertices; i++) {
        float x, y;
        fscanf(arquivo, "%f %f", &x, &y);
        pontos[i] = criarPonto(x, y);
    }

    fclose(arquivo);

    float area = calcularArea(pontos, numVertices);
    free(pontos);

    printf("A área do polígono é %.2f\n", area);

    return 0;
}
