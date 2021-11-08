#include <stdio.h>
#include <math.h>

int check(char board[3][3])
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

int modifyBoard(int input, char board[3][3])
{
	for(;board[(input-1)/3][(input-1)%3] == 'X'||input > 9||input < 1;)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printBoard(board);
		printf("This space is occupied or the input is excessive.Please choose again.\n\n");
		return 0;
	}
	for(;board[(input-1)/3][(input-1)%3] != 'X';)
	{	
		board[(input-1)/3][(input-1)%3] = 'X';
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printBoard(board);
		return 0;
	}
	return 0;
}

int main()
{
	int input, i, j;
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
		printf("Please drop your chess: ");
		scanf("%d", &input);
		modifyBoard(input, board);
		for(;check(board) == 9*88;)
		{
			printf("Game terminated.\n");
			return 0;
		}
	}
	return 0;
}

