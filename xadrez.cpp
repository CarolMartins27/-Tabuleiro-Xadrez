#include <stdio.h>

#define TAM 8

char tabuleiro[TAM][TAM];
int x = 0, y = 0;

// Inicializa o tabuleiro com '.'
void inicializarTabuleiro() {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '.';
}

// Imprime o tabuleiro
void imprimirTabuleiro() {
    printf("\nTabuleiro Final:\n");
    for (int i = TAM - 1; i >= 0; i--) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Marca uma posição no caminho
void marcarCaminho(int x, int y) {
    if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
        tabuleiro[y][x] = '*';
    }
}

// Função recursiva para a Torre
void moverTorre(int casas) {
    if (casas <= 0) return;
    x++;
    marcarCaminho(x, y);
    printf("Direita (%d, %d)\n", x, y);
    moverTorre(casas - 1);
}

// Função recursiva para a Rainha
void moverRainha(int casas) {
    if (casas <= 0) return;
    x--;
    marcarCaminho(x, y);
    printf("Esquerda (%d, %d)\n", x, y);
    moverRainha(casas - 1);
}

// Função recursiva para o Bispo
void moverBispo(int casas) {
    if (casas <= 0) return;
    x++;
    y++;
    marcarCaminho(x, y);
    printf("Cima Direita (%d, %d)\n", x, y);
    moverBispo(casas - 1);
}

// Movimento do Cavalo
void moverCavalo() {
    printf("\nMovimento do Cavalo:\n");

    int cima = 0;
    for (int i = 0; i < 2; i++) {
        y++;
        marcarCaminho(x, y);
        printf("Cima (%d, %d)\n", x, y);
    }

    x++;
    marcarCaminho(x, y);
    printf("Direita (%d, %d)\n", x, y);
}

int main() {
    // Movimento da Torre
    x = 0; y = 0;
    inicializarTabuleiro();
    marcarCaminho(x, y);  // posição inicial
    printf("Movimento da Torre:\n");
    moverTorre(5);
    if (x >= 0 && x < TAM && y >= 0 && y < TAM) tabuleiro[y][x] = 'T';
    imprimirTabuleiro();

    // Movimento do Bispo
    x = 0; y = 0;
    inicializarTabuleiro();
    marcarCaminho(x, y);
    printf("Movimento do Bispo:\n");
    moverBispo(5);
    if (x >= 0 && x < TAM && y >= 0 && y < TAM) tabuleiro[y][x] = 'B';
    imprimirTabuleiro();

    // Movimento da Rainha
    x = 5; y = 0;
    inicializarTabuleiro();
    marcarCaminho(x, y);
    printf("Movimento da Rainha:\n");
    moverRainha(8);
    if (x >= 0 && x < TAM && y >= 0 && y < TAM) tabuleiro[y][x] = 'R';
    imprimirTabuleiro();

    // Movimento do Cavalo
    x = 0; y = 0;
    inicializarTabuleiro();
    marcarCaminho(x, y);
    moverCavalo();
    if (x >= 0 && x < TAM && y >= 0 && y < TAM) tabuleiro[y][x] = 'C';
    imprimirTabuleiro();

    return 0;
}

