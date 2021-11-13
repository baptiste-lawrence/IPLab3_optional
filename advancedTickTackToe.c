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


int checkend(char board[3][3])
{
	int a = 0;
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			a += (int)board[i][j];
		}
	}
	return a;
}

void printBoard(char board[3][3])
{
	int i, j;
	printf("\n");
	for(i=2; i>=0; i--)
	{
		for(j=0; j<3; j++)
		{
			printf("%c   ", board[i][j]); 
		}
			printf("\n\n");
	}
}

void modifyBoard(char board[3][3])
{
	int input;
	for(;;)
	{
		printf("Please drop your chess: ");
		scanf("%d", &input);
		if(board[(input-1)/3][(input-1)%3] != '.'||input > 9||input < 1)
		{
			space();
			printBoard(board);
			printf("This space is occupied or the input is excessive.Please choose again.\n\n");
			continue;
		}
		else if(board[(input-1)/3][(input-1)%3] == '.')
		{	
			board[(input-1)/3][(input-1)%3] = 'X';
			space();
			printBoard(board);
			break;
		}
	}
}

void computer(char board[3][3])
{
	int inputc;
	space();
	srand( time(NULL) );
	for(inputc = 1+rand()%9;;inputc = 1+rand()%9)
	{
		if(board[(inputc-1)/3][(inputc-1)%3] == '.')
		{
			board[(inputc-1)/3][(inputc-1)%3] = 'O';
			break;
		}
		else
		{
			continue;
		}
	}
	printBoard(board);
}

int check(char board[3][3])
{
	int i, j;
	int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0;
	for(i=0; i<3; i++)
	{
		a += board[i][0];
	}
	for(i=0; i<3; i++)
	{
		b += board[i][1];
	}
	for(i=0; i<3; i++)
	{
		c += board[i][2];
	}
	for(j=0; j<3; j++)
	{
		d += board[0][j];
	}
	for(j=0; j<3; j++)
	{
		e += board[1][j];
	}
	for(j=0; j<3; j++)
	{
		f += board[2][j];
	}
	for(i=0; i<3; i++)
	{
		g += board[i][i];
	}
	for(j=0; j<3; j++)
	{
		h += board[2-j][j];
	}

	switch(a)
	{
		case 264 : return 1;
		case 237 : return 2;
	}

	switch(b)
	{
		case 264 : return 1;
		case 237 : return 2;
	}

	switch(c)
	{
		case 264 : return 1;
		case 237 : return 2;
	}

	switch(d)
	{
		case 264 : return 1;
		case 237 : return 2;
	}

	switch(e)
	{
		case 264 : return 1;
		case 237 : return 2;
	}

	switch(f)
	{
		case 264 : return 1;
		case 237 : return 2;
	}

	switch(g)
	{
		case 264 : return 1;
		case 237 : return 2;
	}

	switch(h)
	{
		case 264 : return 1;
		case 237 : return 2;
	}
	return 0;
}

int main()
{
	int i, j;
	char board[3][3];
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			board[i][j] = '.';
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
		else if(checkend(board) == 756)
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

