#include <stdio.h>
#include <stdlib.h>

void imprimirTabuleiro(int optionplayer);
void telaBoasvindas();
void menuPrincipal();
void novoJogo();
void mostrarRanking();
void regrasJogo();

int main() {
    telaBoasvindas();
    menuPrincipal();
    return 0;
}

void telaBoasvindas() {
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
    getchar();
    system("cls");
}

void menuPrincipal() {
    int option;
    char newline;

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

	if (scanf("%d%c", &option, &newline) != 2 || newline != '\n' || option < 1 || option > 4) {
            printf("Opção inválida! Insira um número válido.\n");
            while (getchar() != '\n'); 
            continue; 
        }

        switch (option) {
            case 1:
                novoJogo();
                break;
            case 2:
                regrasJogo();
                break;
            case 3:
                mostrarRanking();
                break;
            case 4:
                system("cls");
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
                getchar(); 
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 4);
}

void novoJogo() {
    int optionplayer;
    char newline;

    do {
        system("cls");
        printf("------------------------------------------------------\n");
        printf("|                                                    |\n");
        printf("|               ####################                 |\n");
        printf("|               ####################                 |\n");
        printf("|               ###              ###                 |\n");
        printf("|               ###  ####  ####  ###                 |\n");
        printf("|               ###  ####  ####  ###                 |\n");
        printf("|               ###              ###                 |\n");
        printf("|               ###  ####  ####  ###                 |\n");
        printf("|               ###  ####  ####  ###                 |\n");
        printf("|               ###              ###                 |\n");
        printf("|               ####################                 |\n");
        printf("|               ####################                 |\n");
        printf("|                                                    |\n");
        printf("|               1. 1 JOGADOR                         |\n");
        printf("|               2. 2 JOGADORES                       |\n");
        printf("|               3. 3 JOGADORES                       |\n");
        printf("|               4. 4 JOGADORES                       |\n");
        printf("|               5. Voltar                            |\n");
        printf("------------------------------------------------------\n");
        if (scanf("%d%c", &optionplayer, &newline) != 2 || newline != '\n' || optionplayer < 1 || optionplayer > 5) {
            printf("Opção inválida! Insira um número válido.\n");
            while (getchar() != '\n'); 
            continue; 
        }
        system("cls");
        switch (optionplayer) {
            case 1:
                printf("Iniciando jogo para 1 jogador...\n");
                printf("Em desenvolvimento (aperte qualquer tecla para retornar)\n");
                imprimirTabuleiro(optionplayer);
                getchar(); 
                break;
            case 2:
                printf("Iniciando jogo para 2 jogadores...\n");
                printf("Em desenvolvimento (aperte qualquer tecla para retornar)\n");
                imprimirTabuleiro(optionplayer);
                getchar(); 
                break;
            case 3:
                printf("Iniciando jogo para 3 jogadores...\n");
                printf("Em desenvolvimento (aperte qualquer tecla para retornar)\n");
                imprimirTabuleiro(optionplayer);
                getchar(); 
                break;
            case 4:
                printf("Iniciando jogo para 4 jogadores...\n");
                printf("Em desenvolvimento (aperte qualquer tecla para retornar)\n");
                imprimirTabuleiro(optionplayer);
                getchar(); 
                break;
            case 5:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (optionplayer != 5);
}

void regrasJogo() {
    system("cls");
    printf("Regras sendo criadas.. (em desenvolvimento)\n");
    printf("DIGITE 1 PARA VOLTAR AO MENU PRINCIPAL\n");
    int option;
    scanf("%d", &option);
    if (option == 1)
        return;
    else
        printf("Opção inválida!\n");
}

void mostrarRanking() {
     system("cls");
    printf("Mostrando ranking...\n");
    // RANKING EM DESENVOLVIMENTO (NÃO CRIADO AINDA 100%)
    printf("--------------------------------------------------------------\n");
    printf("|Mostrando ranking...                                        |\n");
    printf("|POSICAO         NOME DO JOGADOR         QTD DE PONTOS       |\n");
    printf("|                                                            |\n");
    printf("|1               MURILO                  18                  |\n");
    printf("|2               GUILHERME               15                  |\n");
    printf("|3               LEONARDO                13                  |\n");
    printf("|4               EDUARDO                 9                   |\n");
    printf("|5               RAFAEL                  3                   |\n");
    printf("|                                                            |\n");
    printf("|                                                            |\n");
    printf("|TABELA DE PONTOS:                                           |\n");
    printf("|1 = 5 PONTOS                                                |\n");
    printf("|2 = 3 PONTOS                                                |\n");
    printf("|3 = 2 PONTOS                                                |\n");
    printf("|4 = 1 PONTO                                                 |\n");
    printf("|DIGITE 1 PARA VOLTAR AO MENU PRINCIPAL                      |\n");
    printf("|____________________________________________________________|\n");
    printf("DIGITE 1 PARA VOLTAR AO MENU PRINCIPAL\n");
    int option;
    scanf("%d", &option);
    if (option == 1)
        return;
    else
        printf("Opção inválida!\n");
}

void imprimirTabuleiro(int optionplayer) {
    printf(".-----------------------.---.---.---.-----------------------.\n");
printf("|                       |   |   |   |                       |\n");
printf("|                       |---+---+---|                       |\n");
printf("|                       |   | \x1b[32mV\x1b[0m |   | \x1b[32m<\x1b[0m                     |\n");
printf("|       --- ---         |---+---+---|       --- ---         |\n");
printf("|      | \x1b[31mO\x1b[0m | \x1b[31mO\x1b[0m |        |   | \x1b[32mV\x1b[0m |   |      | \x1b[32mO\x1b[0m | \x1b[32mO\x1b[0m |        |\n");
printf("|       ---+---         |---+---+---|       ---+---         |\n");
printf("|      | \x1b[31mO\x1b[0m | \x1b[31mO\x1b[0m |        |   | \x1b[32mV\x1b[0m |   |      | \x1b[32mO\x1b[0m | \x1b[32mO\x1b[0m |        |\n");
printf("|       --- ---         |---+---+---|       --- ---         |\n");
printf("|                       |   | \x1b[32mV\x1b[0m |   |                       |\n");
printf("|                       |---+---+---|                       |\n");
printf("|     \x1b[31mv\x1b[0m                 |   | \x1b[32mV\x1b[0m |   |                       |\n");
printf("|---.---.---.---.---.---+---+---+---+---.---.---.---.---.---|\n");
printf("|   |   |   |   |   |   |   | \x1b[32mV\x1b[0m |   |   |   |   |   |   |   |\n");
printf("|---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|\n");
printf("|   | \x1b[34m>\x1b[0m | \x1b[34m>\x1b[0m | \x1b[34m>\x1b[0m | \x1b[34m>\x1b[0m | \x1b[34m>\x1b[0m | \x1b[34m>\x1b[0m | W | \x1b[33m<\x1b[0m | \x1b[33m<\x1b[0m | \x1b[33m<\x1b[0m | \x1b[33m<\x1b[0m | \x1b[33m<\x1b[0m | \x1b[33m<\x1b[0m |   |\n");
printf("|---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|\n");
printf("|   |   |   |   |   |   |   | \x1b[34m^\x1b[0m |   |   |   |   |   |   |   |\n");
printf("|---^---^---^---^---^---+---+---+---+---^---^---^---^---^---|\n");
printf("|                       |   | \x1b[34m^\x1b[0m |   |                 \x1b[33m^\x1b[0m     |\n");
printf("|                       |---+---+---|                       |\n");
printf("|                       |   | \x1b[34m^\x1b[0m |   |                       |\n");
printf("|       --- ---         |---+---+---|       --- ---         |\n");
printf("|      | \x1b[34mO\x1b[0m | \x1b[34mO\x1b[0m |        |   | \x1b[34m^\x1b[0m |   |      | \x1b[33mO\x1b[0m | \x1b[33mO\x1b[0m |        |\n");
printf("|       ---+---         |---+---+---|       ---+---         |\n");
printf("|      | \x1b[34mO\x1b[0m | \x1b[34mO\x1b[0m |        |   | \x1b[34m^\x1b[0m |   |      | \x1b[33mO\x1b[0m | \x1b[33mO\x1b[0m |        |\n");
printf("|       --- ---         |---+---+---|       --- ---         |\n");
printf("|                     \x1b[34m>\x1b[0m |   | \x1b[34m^\x1b[0m |   |                       |\n");
printf("|                       |---+---+---|                       |\n");
printf("|                       |   |   |   |                       |\n");
printf("^-----------------------^---^---^---^-----------------------^\n");
		}
