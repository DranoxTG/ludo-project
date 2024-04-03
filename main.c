#include <stdio.h>
#include <stdlib.h> 

int main() {
    int option, optionplayer;

    menu_principal:

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

    scanf("%d", &option);
	system("cls");
    switch(option) {
        case 1:
            printf("------------------------------------------------------\n");
            printf("|                                                    |\n");
            printf("|               ####################                 |\n");
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
            printf("|               1. 2  JOGADOR                        |\n");
            printf("|               2. 4. JOGADORES                      |\n");
            printf("|               3. Voltar                            |\n");
			printf("------------------------------------------------------\n");

            scanf("%d", &optionplayer);
			system("cls");
            if (optionplayer == 1) {
                printf(".-----------------------.---.---.---.-----------------------.\n");
	printf("|                       |   |   |   |                       |\n");
	printf("|                       |---+---+---|                       |\n");
	printf("|                       |   | V |   | <                     |\n");
	printf("|       --- ---         |---+---+---|       --- ---         |\n");
	printf("|      | O | O |        |   | V |   |      | O | O |        |\n");
	printf("|       ---+---         |---+---+---|       ---+---         |\n");
	printf("|      | O | O |        |   | V |   |      | O | O |        |\n");
	printf("|       --- ---         |---+---+---|       --- ---         |\n");
	printf("|                       |   | V |   |                       |\n");
	printf("|                       |---+---+---|                       |\n");
	printf("|     v                 |   | V |   |                       |\n");
	printf("|---.---.---.---.---.---+---+---+---+---.---.---.---.---.---|\n");
	printf("|   |   |   |   |   |   |   | V |   |   |   |   |   |   |   |\n");
	printf("|---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|\n");
	printf("|   | > | > | > | > | > | > | W | < | < | < | < | < | < |   |\n");
	printf("|---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|\n");
	printf("|   |   |   |   |   |   |   | ^ |   |   |   |   |   |   |   |\n");
	printf("|---^---^---^---^---^---+---+---+---+---^---^---^---^---^---|\n");
	printf("|                       |   | ^ |   |                 ^     |\n");
	printf("|                       |---+---+---|                       |\n");
	printf("|                       |   | ^ |   |                       |\n");
	printf("|       --- ---         |---+---+---|       --- ---         |\n");
	printf("|      | O | O |        |   | ^ |   |      | O | O |        |\n");
	printf("|       ---+---         |---+---+---|       ---+---         |\n");
	printf("|      | O | O |        |   | ^ |   |      | O | O |        |\n");
	printf("|       --- ---         |---+---+---|       --- ---         |\n");
	printf("|                     > |   | ^ |   |                       |\n");
	printf("|                       |---+---+---|                       |\n");
	printf("|                       |   |   |   |                       |\n");
	printf("^-----------------------^---^---^---^-----------------------^\n"); 
            } else if (optionplayer == 2) {
                printf(".-----------------------.---.---.---.-----------------------.\n");
	printf("|                       |   |   |   |                       |\n");
	printf("|                       |---+---+---|                       |\n");
	printf("|                       |   | V |   | <                     |\n");
	printf("|       --- ---         |---+---+---|       --- ---         |\n");
	printf("|      | O | O |        |   | V |   |      | O | O |        |\n");
	printf("|       ---+---         |---+---+---|       ---+---         |\n");
	printf("|      | O | O |        |   | V |   |      | O | O |        |\n");
	printf("|       --- ---         |---+---+---|       --- ---         |\n");
	printf("|                       |   | V |   |                       |\n");
	printf("|                       |---+---+---|                       |\n");
	printf("|     v                 |   | V |   |                       |\n");
	printf("|---.---.---.---.---.---+---+---+---+---.---.---.---.---.---|\n");
	printf("|   |   |   |   |   |   |   | V |   |   |   |   |   |   |   |\n");
	printf("|---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|\n");
	printf("|   | > | > | > | > | > | > | W | < | < | < | < | < | < |   |\n");
	printf("|---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|\n");
	printf("|   |   |   |   |   |   |   | ^ |   |   |   |   |   |   |   |\n");
	printf("|---^---^---^---^---^---+---+---+---+---^---^---^---^---^---|\n");
	printf("|                       |   | ^ |   |                 ^     |\n");
	printf("|                       |---+---+---|                       |\n");
	printf("|                       |   | ^ |   |                       |\n");
	printf("|       --- ---         |---+---+---|       --- ---         |\n");
	printf("|      | O | O |        |   | ^ |   |      | O | O |        |\n");
	printf("|       ---+---         |---+---+---|       ---+---         |\n");
	printf("|      | O | O |        |   | ^ |   |      | O | O |        |\n");
	printf("|       --- ---         |---+---+---|       --- ---         |\n");
	printf("|                     > |   | ^ |   |                       |\n");
	printf("|                       |---+---+---|                       |\n");
	printf("|                       |   |   |   |                       |\n");
	printf("^-----------------------^---^---^---^-----------------------^\n"); 
            } else if (optionplayer == 3) {
                goto menu_principal;
            } else {
                printf("Opção inválida!\n");
            }
            break;
        case 2:
            printf("Mostrando regras...\n");
            // (REGRAS NÃO CRIADAS AINDA)
            break;
        case 3:
            printf("Mostrando ranking...\n");
            //RANKING EM DESENVOLVIMENTO (NÃO CRIADO AINDA 100%)
			printf("POSICAO		NOME DO JOGADOR		QTD DE PONTOS			\n\n");
 				  	
            printf("1   		MURILO                  18\n");			
            printf("2		GUILHERME		15\n");		
            printf("3		LEONARDO		13\n");		
            printf("4		EDUARDO			9\n");
            printf("5		RAFAEL			3\n\n\n");

            printf("TABELA DE PONTOS:\n");
            printf("1 = 5 PONTOS\n");	
            printf("2 = 3 PONTOS\n");
            printf("3 = 2 PONTOS\n");
            printf("4 = 1 PONTO\n");

            printf("DIGITE 1 PARA VOLTAR AO MENU PRINCIPAL\n");

           
            scanf("%d", &option);
            if (option == 1) {
                goto menu_principal;
            } else {
                printf("Opção inválida!\n");
            }
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
	
	
	        getch();
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
