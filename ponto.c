#include "ponto.h"

Ponto criarPonto(float x, float y) {
    Ponto ponto;
    ponto.X = x;
    ponto.Y = y;
    return ponto;
}

float calcularArea(Ponto *pontos, int numVertices) {
    float area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        area += (pontos[i].X * pontos[j].Y) - (pontos[j].X * pontos[i].Y);
    }

    return area / 2.0;
}
