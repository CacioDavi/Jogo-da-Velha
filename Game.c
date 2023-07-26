#include <stdio.h>

// Função para exibir o tabuleiro
void exibir_tabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---+---+---\n");
    }
}

// Função para verificar se um jogador ganhou
int verificar_vitoria(char tabuleiro[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return 1;
        }
    }
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1;
    }
    return 0;
}

int main() {
    char tabuleiro[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int linha, coluna;
    int jogadas = 0;
    char jogador = 'X';

    printf("Bem-vindo ao Jogo da Velha!\n");

    do {
        exibir_tabuleiro(tabuleiro);

        // Obter a entrada do jogador
        printf("Jogador %c, digite a posição (1-9): ", jogador);
        scanf("%d", &linha);
        linha--; // Ajustar para o índice do array
        coluna = linha % 3;
        linha = linha / 3;

        // Verificar se a posição está vazia
        if (tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O') {
            tabuleiro[linha][coluna] = jogador;
            jogadas++;
            if (verificar_vitoria(tabuleiro, jogador)) {
                exibir_tabuleiro(tabuleiro);
                printf("Parabéns! Jogador %c venceu!\n", jogador);
                return 0;
            }
            // Alternar o jogador
            jogador = (jogador == 'X') ? 'O' : 'X';
        } else {
            printf("Posição ocupada. Tente novamente.\n");
        }

    } while (jogadas < 9);

    exibir_tabuleiro(tabuleiro);
    printf("Empate! Fim do jogo.\n");

    return 0;
}
