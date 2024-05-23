#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define SIZE 11 // Tamanho do tabuleiro
#define ALTURA 31
#define COMPRIMENTO 61

// AQUI FOI MONTADO A ESTRUTURA DE CADA PEÇA
typedef struct {
    int x;
    int y;
    int active; // LOGICA PRA QUE SE A PEÇA TIVER FORA DO TABULEIRO OU DENTRO
    int pathIndex; // INDICE DA POSIÇÃO
    int homeX; // POSIÇÃO INICIAL
    int homeY;
} Peca;

// ESTRUTURA IMPLEMENTADA PRA REPRESENTAR OS JOGADORES
typedef struct {
    Peca pecas[4];
    char cor;
    int startX;
    int startY;
    int startPathIndex;
    const int (*caminhoFinal)[2]; // CAMINHO FINAL (em desenvolvimento to tentando arrumar essa logica)
} Jogador;

// CAMINHO DO TABULEIRO
const int caminho[40][2] = {
    {6, 9}, {6, 8}, {6, 7}, {6, 6}, {7, 6}, {8, 6}, {9, 6}, {10, 6}, {10, 5}, {10, 4},
    {9, 4}, {8, 4}, {7, 4}, {6, 4}, {6, 3}, {6, 2}, {6, 1}, {6, 0}, {5, 0}, {4, 0},
    {4, 1}, {4, 2}, {4, 3}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}, {0, 5}, {0, 6},
    {1, 6}, {2, 6}, {3, 6}, {4, 6}, {4, 7}, {4, 8}, {4, 9}, {5, 9}, {6, 9}
};

// CAMINHO FINAL (EM DESENVOLVIMENTO)
const int caminhos_finais_vermelho[4][2] = {{5, 5}, {4, 5}, {3, 5}, {2, 5}};
const int caminhos_finais_amarelo[4][2] = {{5, 5}, {5, 4}, {5, 3}, {5, 2}};
const int caminhos_finais_azul[4][2] = {{5, 5}, {5, 6}, {5, 7}, {5, 8}};
const int caminhos_finais_verde[4][2] = {{5, 5}, {6, 5}, {7, 5}, {8, 5}};
const int posicao_final[2] = {5, 5}; // Posição final "W"

// AQUI FOI CRIADO UMA FUNÇÃO PRA POSICIONAR O CURSOR NO CONSOLE
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// INICIALIZNADO O TABULEIRO (igual o professor fez no exel) (futuramente pretende tirar o Y pra ficar mais bonito)
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    int i, j;
    char tabuleiroInicial[SIZE][SIZE] = {
        {'Y','Y','Y','Y','D','D','D','Y','Y','Y','Y'},
        {'Y',' ',' ','Y','D','X','D','Y',' ',' ','Y'},
        {'Y',' ',' ','Y','D','X','D','Y',' ',' ','Y'},
        {'Y','Y','Y','Y','D','X','D','Y','Y','Y','Y'},
        {'D','D','D','D','D','X','D','D','D','D','D'},
        {'D','X','X','X','X','W','X','X','X','X','D'},
        {'D','D','D','D','D','X','D','D','D','D','D'},
        {'Y','Y','Y','Y','D','X','D','Y','Y','Y','Y'},
        {'Y',' ',' ','Y','D','X','D','Y',' ',' ','Y'},
        {'Y',' ',' ','Y','D','X','D','Y',' ',' ','Y'},
        {'Y','Y','Y','Y','D','D','D','Y','Y','Y','Y'}
    };
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = tabuleiroInicial[i][j];
        }
    }
}

// AQUI FOI CRIADA UMA FUNÇÃO PRA IMPRIMIR O TABULEIRO EM CODIGO ASCII
void imprimirTabuleiro(char tabuleiro[SIZE][SIZE]) {
    int i, j;
    system("cls");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            gotoxy(j * 2, i); // MULTIPLICA POR 2 PRA FICAR CERTINHO
            if (tabuleiro[i][j] == 'R') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                printf("%c", tabuleiro[i][j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else if (tabuleiro[i][j] == 'A') { 
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
                printf("%c", tabuleiro[i][j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else if (tabuleiro[i][j] == 'B') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                printf("%c", tabuleiro[i][j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else if (tabuleiro[i][j] == 'G') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                printf("%c", tabuleiro[i][j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                printf("%c", tabuleiro[i][j]);
            }
        }
    }
    gotoxy(0, SIZE); // ESSE COMANDO POSICIONA O CURSOR EM BAIXO DO TABUELIRO
}

// AQUI INICIALIZA OS JOGADORES
void inicializarJogadores(Jogador jogadores[4]) {
    // TIME Vermelho
    jogadores[0] = (Jogador){{{1, 1, 0, -1, 1, 1}, {2, 1, 0, -1, 2, 1}, {1, 2, 0, -1, 1, 2}, {2, 2, 0, -1, 2, 2}}, 'R', 4, 1, 20, caminhos_finais_vermelho};

    // TIME Amarelo
    jogadores[1] = (Jogador){{{1, 8, 0, -1, 1, 8}, {2, 8, 0, -1, 2, 8}, {1, 9, 0, -1, 1, 9}, {2, 9, 0, -1, 2, 9}}, 'A', 1, 6, 30, caminhos_finais_amarelo};

    // TIME Azul
    jogadores[2] = (Jogador){{{8, 8, 0, -1, 8, 8}, {9, 8, 0, -1, 9, 8}, {8, 9, 0, -1, 8, 9}, {9, 9, 0, -1, 9, 9}}, 'B', 6, 9, 0, caminhos_finais_azul};

    // TIME Verde
    jogadores[3] = (Jogador){{{8, 1, 0, -1, 8, 1}, {9, 1, 0, -1, 9, 1}, {8, 2, 0, -1, 8, 2}, {9, 2, 0, -1, 9, 2}}, 'G', 9, 4, 10, caminhos_finais_verde};
}

// FUNÇÃO PRA ROLAR O DADO (1-6)
int rolarDado() {
    return rand() % 6 + 1;
}

// AQUI FOI CRIADA A FUNÇÃO PRA MOVER A PEÇA (deu um tabalinho fazer essa logica)
void moverPeca(Jogador *jogador, int indicePeca, int passos) {
    Peca *peca = &jogador->pecas[indicePeca];

    if (!peca->active) {
        if (passos == 6) {
            peca->active = 1;
            peca->x = caminho[jogador->startPathIndex][0];
            peca->y = caminho[jogador->startPathIndex][1];
            peca->pathIndex = jogador->startPathIndex;
        }
    } else {
        peca->pathIndex += passos;
        if (peca->pathIndex >= 40) {
            int finalIndex = peca->pathIndex - 40;
            if (finalIndex < 4) {
                peca->x = jogador->caminhoFinal[finalIndex][0];
                peca->y = jogador->caminhoFinal[finalIndex][1];
            } else {
                peca->x = posicao_final[0];
                peca->y = posicao_final[1];
            }
        } else {
            peca->x = caminho[peca->pathIndex][0];
            peca->y = caminho[peca->pathIndex][1];
        }
    }
}

// FUNÇÃO PRA ATUALIZAR O TABULEIRO
void atualizarTabuleiro(char tabuleiro[SIZE][SIZE], Jogador jogadores[4]) {
    inicializarTabuleiro(tabuleiro);
    for (int i = 0; i < 4; i++) {
        Jogador *jogador = &jogadores[i];
        for (int j = 0; j < 4; j++) {
            Peca *peca = &jogador->pecas[j];
            if (peca->active) {
                tabuleiro[peca->x][peca->y] = jogador->cor;
            } else {
                tabuleiro[peca->homeX][peca->homeY] = jogador->cor;
            }
        }
    }
}

// FUNÇÃO MAIN DO JOGO
void jogarLudo() {
    srand(time(NULL));
    char tabuleiro[SIZE][SIZE];
    Jogador jogadores[4];
    int jogadorAtual = 0;

    inicializarTabuleiro(tabuleiro);
    inicializarJogadores(jogadores);

    while (1) {
        int dado = rolarDado();
        imprimirTabuleiro(tabuleiro);
        printf("Jogador %c, voce tirou %d no dado.\n", jogadores[jogadorAtual].cor, dado);
        printf("Escolha uma peca para mover (1-4): ");
        int pecaEscolhida;
        scanf("%d", &pecaEscolhida);
        pecaEscolhida--;

        moverPeca(&jogadores[jogadorAtual], pecaEscolhida, dado);
        atualizarTabuleiro(tabuleiro, jogadores);
        imprimirTabuleiro(tabuleiro);

        jogadorAtual = (jogadorAtual + 1) % 4;
    }
}

// TELA DE BOAS VINDAS
void mostrarBoasVindas() {
    printf("[][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("[]                                              []\n");
	printf("[]                                              []\n");
	printf("[]          Bem-vindo ao Jogo de Ludo!          []\n");
	printf("[]                                              []\n");
	printf("[]                                              []\n");
	printf("[]  Prepare-se para muita diversao e desafios!  []\n");
	printf("[]                                              []\n");
	printf("[]            Pressione uma tecla!              []\n");
	printf("[]                                              []\n");
	printf("[]                                              []\n");
	printf("[]                                              []\n");
	printf("[]             ####################             []\n");
	printf("[]             ####################             []\n");
	printf("[]             ###              ###             []\n");
	printf("[]             ###  ####  ####  ###             []\n");
	printf("[]             ###  ####  ####  ###             []\n");
	printf("[]             ###              ###             []\n");
	printf("[]             ###  ####  ####  ###             []\n");
	printf("[]             ###  ####  ####  ###             []\n");
	printf("[]             ###              ###             []\n");
	printf("[]             ####################             []\n");
	printf("[]             ####################             []\n");
	printf("[]                                              []\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\nAperte qualquer tecla!\n");
    _getch();
}

// REGRAS (vou montar uma tela bonita pra ele)
void mostrarRegras() {
    printf("Regras do Jogo Ludo:\n");
    printf("1. Cada jogador tem 4 pecas.\n");
    printf("2. O objetivo eh mover todas as pecas para a area final.\n");
    printf("3. As pecas se movem com base no numero obtido no dado.\n");
    printf("4. Voce so pode mover uma peca para fora da base se tirar um 6 no dado.\n");
    printf("Pressione qualquer tecla para voltar ao menu...\n");
    _getch();
}

// RANK (vou montar uma tela bonita pra ele)
void mostrarRanking() {
    printf("Ranking dos Jogadores:\n");
    printf("1. Jogador A: 100 pontos\n");
    printf("2. Jogador B: 80 pontos\n");
    printf("3. Jogador C: 60 pontos\n");
    printf("4. Jogador D: 40 pontos\n");
    printf("Pressione qualquer tecla para voltar ao menu...\n");
    _getch();
}

// FUNÇÃO menu principal
void mostrarMenu() {
    int escolha;
    do {
        system("cls");
        printf(" _________        .---\"\"\"      \"\"\"---.              \n");
	printf(":______.-':      :  .--------------.  :             \n");
	printf("| ______  |      | :                : |             \n");
	printf("|:______B:|      | |  LUDO GAME !   | |             \n");
	printf("|:______B:|      | |                | |             \n");
	printf("|:______B:|      | |  1.NovoJogo    | |             \n");
	printf("|         |      | |  2.Regras      | |             \n");
	printf("|:_____:  |      | |  3.Rank        | |             \n");
	printf("|    ==   |      | :  4.Sair        : |             \n");
	printf("|       O |      :  '--------------'  :             \n");
	printf("|       o |      :'---...______...---'              \n");
	printf("|       o |-._.-i___/'             \\._              \n");
	printf("|'-.____o_|   '-.   '-...______...-'  `-._          \n");
	printf(":_________:      `.____________________   `-.___.-. \n");
	printf("                 .'.eeeeeeeeeeeeeeeeee.'.      :___:\n");
	printf("               .'.eeeeeeeeeeeeeeeeeeeeee.'.         \n");
	printf("              :____________________________:\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                jogarLudo();
                break;
            case 2:
                mostrarRegras();
                break;
            case 3:
                mostrarRanking();
                break;
            case 4:
                printf("Saindo do jogo...\n");
                printf("------------------------------------------------------\n");
                printf("|                                                    |\n");
                printf("|		####################                 |\n");
                printf("|		####################                 |\n");
                printf("|		###              ###                 |\n");
                printf("|		###  ####  ####  ###                 |\n");
                printf("|		###  ####  ####  ###                 |\n");
                printf("|		###              ###                 |\n");
                printf("|		###  ####  ####  ###                 |\n");
                printf("|		###  ####  ####  ###                 |\n");
                printf("|		###              ###                 |\n");
                printf("|		####################                 |\n");
                printf("|		####################                 |\n");
                printf("|                                                    |\n");
                printf("|             ~OBRIGADO! VOLTE SEMPRE!~              |\n");
                printf("|                                                    |\n");
                printf("|                                                    |\n");
                printf("------------------------------------------------------\n");
                printf("\nAperte qualquer tecla!");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (escolha != 4);
}

// Função principal
int main() {
    mostrarBoasVindas();
    mostrarMenu();
    return 0;
}
