#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void space()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


int checkend(int board[3][3])
{
	int a = 1;
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			a *= (int)board[i][j];
		}
	}
	return a;
}

void printBoard(int board[3][3])
{
	int i, j;
	printf("\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(board[i][j] == 0)
			{
				printf(".   ");
			}	
			else if(board[i][j] == 1)
			{
				printf("X   ");
			}
			else
			{
				printf("O   ");
			}
		}
			printf("\n\n");
	}
}

void modifyBoard(int board[3][3])
{
	int input;
here:	printf("Please drop your chess: ");
	scanf("%d", &input);
	switch(input)
	{
		case 7 :if(board[0][0] != 0)
			{
				space();
				printBoard(board);
				printf("This place is occupied. Please drop your chess at another place.\n\n");
				goto here;
			}
			else
			{
				space();
				board[0][0] = 1;
				printBoard(board);
			}
			break;
		
		case 8 :if(board[0][1] != 0)
			{
				space();
				printBoard(board);
				printf("This place is occupied. Please drop your chess at another place.\n\n");
				goto here;
			}
			else
			{
				space();
				board[0][1] = 1;
				printBoard(board);
			}
			break;

		case 9 :if(board[0][2] != 0)
			{
				space();
				printBoard(board);
				printf("This place is occupied. Please drop your chess at another place.\n\n");
				goto here;
			}
			else
			{
				space();
				board[0][2] = 1;
				printBoard(board);
			}
			break;

		case 4 :if(board[1][0] != 0)
			{
				space();
				printBoard(board);
				printf("This place is occupied. Please drop your chess at another place.\n\n");
				goto here;
			}
			else
			{
				space();
				board[1][0] = 1;
				printBoard(board);
			}
			break;

		case 5 :if(board[1][1] != 0)
			{
				 space();
                                 printBoard(board);
                                 printf("This place is occupied. Please drop your chess at another place.\n\n");
                        	 goto here;
			}
                        else
                        {
				space();
                                board[1][1] = 1;
                                printBoard(board);
                        }
                        break;
 
                case 6 :if(board[1][2] != 0)
                        {
				space();
                                printBoard(board);
                                printf("This place is occupied. Please drop your chess at another place.\n\n");
                        	goto here;
			}
                        else
                        {
				space();
                                board[1][2] = 1;
                                printBoard(board);
                        }
                        break;

		case 1 :if(board[2][0] != 0)
                        {
				space();
                                printBoard(board);
                                printf("This place is occupied. Please drop your chess at another place.\n\n");
                        	goto here;
			}
                        else
                        {
				space();
                                board[2][0] = 1;
                                printBoard(board);
                        }
                        break;

                case 2 :if(board[2][1] != 0)
                        {
				space();
                                printBoard(board);
                                printf("This place is occupied. Please drop your chess at another place.\n\n");
                        	goto here;
			}
                        else
                        {
				space();
                                board[2][1] = 1;
                                printBoard(board);
                        }
                        break;
 
                case 3 :if(board[2][2] != 0)
                        {
				space();
                                printBoard(board);
                                printf("This place is occupied. Please drop your chess at another place.\n\n");
                        	goto here;
			}
                        else
                        {
				space();
                                board[2][2] = 1;
                                printBoard(board);
                        }
                        break;

		default : space();
			  printBoard(board);
			  printf("The input is excessive.Please choose again.\n");
			  goto here;
	}
}

void computer(int board[3][3])
{
	int inputc;
	space();
	srand( time(NULL) );
	for(inputc = 1+rand()%9;;inputc = 1+rand()%9)
	{
		if(board[(inputc-1)/3][(inputc-1)%3] == 0)
		{
			board[(inputc-1)/3][(inputc-1)%3] = 2;
			break;
		}
		else
		{
			continue;
		}
	}
	printBoard(board);
}

int check(int board[3][3])
{
	int i, j;
	int a=1, b=1, c=1, d=1, e=1, f=1, g=1, h=1;
	for(i=0; i<3; i++)
	{
		a *= board[i][0];
	}
	for(i=0; i<3; i++)
	{
		b *= board[i][1];
	}
	for(i=0; i<3; i++)
	{
		c *= board[i][2];
	}
	for(j=0; j<3; j++)
	{
		d *= board[0][j];
	}
	for(j=0; j<3; j++)
	{
		e *= board[1][j];
	}
	for(j=0; j<3; j++)
	{
		f *= board[2][j];
	}
	for(i=0; i<3; i++)
	{
		g *= board[i][i];
	}
	for(j=0; j<3; j++)
	{
		h *= board[2-j][j];
	}

	switch(a)
	{
		case 1 : return 1;
		case 8 : return 2;
	}

	switch(b)
	{
		case 1 : return 1;
		case 8 : return 2;
	}

	switch(c)
	{
		case 1 : return 1;
		case 8 : return 2;
	}

	switch(d)
	{
		case 1 : return 1;
		case 8 : return 2;
	}

	switch(e)
	{
		case 1 : return 1;
		case 8 : return 2;
	}

	switch(f)
	{
		case 1 : return 1;
		case 8 : return 2;
	}

	switch(g)
	{
		case 1 : return 1;
		case 8 : return 2;
	}

	switch(h)
	{
		case 1 : return 1;
		case 8 : return 2;
	}
	return 0;
}

int main()
{
	int i, j;
	int board[3][3];
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			board[i][j] = 0;
		}
	}
	printBoard(board);
	for(;;)
	{
		modifyBoard(board);
		if(check(board) == 1)
		{
			printf("You win!\n");
			break;
		}
		else if(checkend(board) != 0)
		{
			printf("The game is drawn.\n");
			break;
		}
		printf("Please press Enter.");
		getchar();
                getchar();
		computer(board);
		if(check(board) == 2)
		{
			printf("You lose!\n");
			break;
		}
	}
	return 0;
}
