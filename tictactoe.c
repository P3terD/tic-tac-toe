/*Importar bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/*setar variaveis*/
char square[10] = {' ','1', '2', '3', '4', '5', '6', '7', '8', '9'};
char opt, mark;
int player = 1, choice, i = 1, close = 0, bot;

/*setar funcoes*/
void board();
int win();
void game();

int main() 
{
    do {
    	/*setar os valores iniciais dos quadrados*/
        square[1] = '1', square[2] = '2', square[3] = '3', square[4] = '4', square[5] = '5', square[6] = '6', square[7] = '7',
        square[8] = '8', square[9] = '9';

        /***********************************************************************************
                                                MENU
        ************************************************************************************/

        system("cls||clear");

        printf("\t T | I | C\n");
        printf("\t---|---|---\n");
        printf("\t T | A | C\n");
        printf("\t---|---|---\n");
        printf("\t T | O | E\n");


        printf("\n\nEscolha uma opcao:");
        printf("\n[1] Jogador contra Jogador \n[2] Jogador contra Maquina \n[3] Tutorial \n[4] Sair");
        printf("\n\nOpcao: ");
        opt = getchar();

        switch(opt) 
        {

            /***********************************************************************************
                                            JOGADOR VS JOGADOR
            ************************************************************************************/

            case '1':
                do 
                {
                    board();

                    player = (player % 2) ? 1 : 2;
    
                    printf("Jogador %d, digite um numero: ", player);
                    fflush(stdin);
                    scanf("%d", &choice);

                    game();
                } while (i == 1);
                

                board();

                if (i == 2)
                {
                    printf("O Jogador %d ganhou!\n", --player);
                }
                else
                {
                    printf("Empate!\n");
                }

                system("pause");

                break;

            /***********************************************************************************
                                            JOGADOR VS MAQUINA
            ************************************************************************************/

            case '2':

				/*inicia srand que randomiza o numero gerado por rand*/
                srand(time(NULL));

                do
                {
                    board();

                    player = (player % 2) ? 1 : 2;

                    if (player == 1)
                    {
                        printf("Jogador 1, digite um numero: ");
                        fflush(stdin);
                        scanf("%d", &choice);
                    }

                    else
                    {
                        bot = 1;
                        choice = rand() % 10;

                        if (square[choice] != choice || choice == 0)
                        {
                            choice = rand() % 10;
                        }
                    }

                    game();

                    bot = 0;
                } while (i == 1);

                board();

                if (i == 2)
                {
                    if (--player == 1)
                    {
                        printf("Voce ganhou, parabens!\n\n");
                    }

                    else 
                    {
                        printf("Eu ganhei :D\n\n");
                    }
                }
                else
                {
                    printf("Empate!\n");
                }

                system("pause");

                break;

            /***********************************************************************************
                                                TUTORIAL
            ************************************************************************************/

            case '3':
                system("cls||clear");
                printf("\tINTRODUCAO\n\n");
                printf("Ola visitante, bem vindo ao TIC TAC TOE :D\n");
                printf("Tic Tac Toe ou jogo da velha, eh um jogo simples, \njogado por 2 jogadores, vamos ao tutorial\n\n");
                system("pause");

                system("cls||clear");
                printf("\tCOMO JOGAR\n\n");
                printf("Na sua tela ira aparecer algo assim:\n\n");
                system("pause");
                board();
                printf("Voce tem que escolher um quadrado para marcar, use \no numero no quadrado para fazer isso.\n");
                printf("Se voce for o Jogador 1, sera marcado um 'X', se voce \no jogador 2 sera marcado um 'O'\n");
                printf("O mesmo quadrado nao pode ser marcado mais de uma vez!\n\n");
                system("pause");

                system("cls||clear");
                printf("\tCOMO GANHAR\n\n");
                printf("Para ganhar voce precisa ter 3 quadrados preenchidos pelo seu simbolo na vertical;\n\n");
                system("pause");
                square[1] = 'X', square[4] = 'X', square[7] = 'X';
                board();
                square[1] = '1', square[4] = '4', square[7] = '7';
                system("pause");

                system("cls||clear");
                printf("\tCOMO GANHAR\n\n");
                printf("Ou 3 quadrados preenchidos na horizontal;\n\n");
                system("pause");
                square[1] = 'X', square[2] = 'X', square[3] = 'X';
                board();
                square[1] = '1', square[2] = '2', square[3] = '3';
                system("pause");

                system("cls||clear");
                printf("\tCOMO GANHAR\n\n");
                printf("Ou 3 quadrados preenchidos na diagonal;\n\n");
                system("pause");
                square[1] = 'X', square[5] = 'X', square[9] = 'X';
                board();
                system("pause");

                system("cls||clear");
                printf("\tO QUE ACONTECE SE TODOS OS QUADRADOS FOREM PREENCHIDOS?\n\n");
                printf("Se todos os quadrados forem preenchidos e ninguem tiver ganhado, voces terao um empate!\n");
                printf("Mas voces sempre podem jogar novamente :D\n\n");
                system("pause");

                break;

            case '4':
                close = 1;
                break;

            default:
                printf("Opcao invalida! Tente novamente");
                system("pause");
                break;

        }
    } while (close == 0);
}

/***********************************************************************************
                            FUNCAO PARA JOGAR
************************************************************************************/

void game()
{
    mark = (player == 1) ? 'X' : 'O';

    if (choice == 1 && square[1] == '1') 
    {
        square[1] = mark;
    }

    else if (choice == 2 && square[2] == '2') 
    {
        square[2] = mark;
    }

    else if (choice == 3 && square[3] == '3') 
    {
        square[3] = mark;
    }

    else if (choice == 4 && square[4] == '4') 
    {
        square[4] = mark;
    }

    else if (choice == 5 && square[5] == '5') 
    {
        square[5] = mark;
    }

    else if (choice == 6 && square[6] == '6') 
    {
        square[6] = mark;
    }

    else if (choice == 7 && square[7] == '7') 
    {
        square[7] = mark;
    }

    else if (choice == 8 && square[8] == '8') 
    {
        square[8] = mark;
    }

    else if (choice == 9 && square[9] == '9') 
    {
        square[9] = mark;
    }

    else if (bot == 1)
    {
        player--;
    }

    else
    {
        printf("\n\nMovimento invalido\n");

        player--;

        system("pause");
    }

    i = win();

    player++;
}

/***********************************************************************************
                            FUNCAO PARA CHECAR VITORIA
************************************************************************************/

int win()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 2;

    else if (square[4] == square[5] && square[5] == square[6])
        return 2;

    else if (square[7] == square[8] && square[8] == square[9])
        return 2;

    else if (square[1] == square[4] && square[4] == square[7])
        return 2;

    else if (square[2] == square[5] && square[5] == square[8])
        return 2;

    else if (square[3] == square[6] && square[6] == square[9])
        return 2;

    else if (square[1] == square[5] && square[5] == square[9])
        return 2;

    else if (square[3] == square[5] && square[5] == square[7])
        return 2;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && 
    square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;

    else
        return 1;
}

/***********************************************************************************
                    FUNCAO PARA DESENHAR TABELA COM AS JOGADAS
************************************************************************************/

void board()
{
    system("cls");
    
    printf("\n\nTic Tac Toe\n\n");
    printf("Player 1 (x) - Player 2 (O)\n\n\n");

    printf("\t %c | %c | %c\n", square[1], square[2], square[3]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c\n", square[4], square[5], square[6]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c\n\n\n", square[7], square[8], square[9]);
    
}
