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
			//space();
			printBoard(board);
			printf("This space is occupied or the input is excessive.Please choose again.\n\n");
			continue;
		}
		else if(board[(input-1)/3][(input-1)%3] == '.')
		{	
			board[(input-1)/3][(input-1)%3] = 'X';
			//space();
			printBoard(board);
			break;
		}
	}
}

void computer(char board[3][3])
{
	int inputc;
	//space();
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

void computerr(int row, char board[3][3])
{
	int rd;
	//space();
	srand( time(NULL) );
	for(rd = 0+rand()%3;;rd = 0+rand()%3)
	{
		if(board[row][rd] == '.')
		{
			board[row][rd] = 'O';
			break;
		}
		else
		{
			continue;
		}
	}
	printBoard(board);
}

void computerc(int column, char board[3][3])
{
	int rd;
	//space();
	srand( time(NULL) );
	for(rd = 0+rand()%3;;rd = 0+rand()%3)
	{
		if(board[rd][column] == '.')
		{
			board[rd][column] = 'O';
			break;
		}
		else
		{
			continue;
		}
	}
	printBoard(board);
}

void computercross1(char board[3][3])
{
	int rd;
	//space();
	srand( time(NULL) );
	for(rd = 0+rand()%3;;rd = 0+rand()%3)
	{
		if(board[rd][rd] == '.')
		{
			board[rd][rd] = 'O';
			break;
		}
		else
		{
			continue;
		}
	}
	printBoard(board);
}

void computercross2(char board[3][3])
{
	int rd;
	//space();
	srand( time(NULL) );
	for(rd = 0+rand()%3;;rd = 0+rand()%3)
	{
		if(board[rd][2-rd] == '.')
		{
			board[rd][2-rd] = 'O';
			break;
		}
		else
		{
			continue;
		}
	}
	printBoard(board);
}

void computercorner(char board[3][3])
{
	int rd;
	//space();
	srand( time(NULL) );
	rd = 1 + rand()%4;
	if(rd == 1)
	{
		board[0][0] = 'O';
	}
	else if(rd == 2)
	{
		board[0][2] = 'O';
	}
	else if(rd == 3)
	{
		board[2][0] = 'O';
	}
	else
	{
		board[2][2] = 'O';
	}

	printBoard(board);
}

void intelligentcomputer(int count, char board[3][3])
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

	for(;;)
	{
		if(count == 0 && board[1][1] == 'X')
		{
			computercorner(board);
			break;
		}
		if(a == 204)
		{
			computerc(0, board);
			break;
		}
		else if(b == 204)
		{
			computerc(1, board);
			break;
		}
		else if(c == 204)
		{
			computerc(2, board);
			break;
		}
		else if(d == 204)
		{
			computerr(0, board);
			break;
		}
		else if(e == 204)
		{
			computerr(1, board);
			break;
		}
		else if(f == 204)
		{
			computerr(2, board);
			break;
		}
		else if(g == 204)
		{
			computercross1(board);
			break;
		}
		else if(h == 204)
		{
			computercross2(board);
			break;
		}
		else if(a == 222)
		{
			computerc(0, board);
			break;
		}
		else if(b == 222)
		{
			computerc(1, board);
			break;
		}
		else if(c == 222)
		{
			computerc(2, board);
			break;
		}
		else if(d == 222)
		{
			computerr(0, board);
			break;
		}
		else if(e == 222)
		{
			computerr(1, board);
			break;
		}
		else if(f == 222)
		{
			computerr(2, board);
			break;
		}
		else if(g == 222)
		{
			computercross1(board);
			break;
		}
		else if(h == 222)
		{
			computercross2(board);
			break;
		}
		else if(a == 171)
		{
			computerc(0, board);
			break;
		}
		else if(b == 171)
		{
			computerc(1, board);
			break;
		}
		else if(c == 171)
		{
			computerc(2, board);
			break;
		}
		else if(d == 171)
		{
			computerr(0, board);
			break;
		}
		else if(e == 171)
		{
			computerr(1, board);
			break;
		}
		else if(f == 171)
		{
			computerr(2, board);
			break;
		}
		else if(g == 171)
		{
			computercross1(board);
			break;
		}
		else if(h == 171)
		{
			computercross2(board);
			break;
		}
		else if(board[1][1] == '.' )
		{
			board[1][1] = 'O';
			//space();
			printBoard(board);
			break;
		}
		else
		{
			computer(board);
			break;
		}
		break;
	}
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

	printf("a%d b%d c%d d%d e%d f%d g%d h%d\n",a, b, c, d, e, f, g, h);
	
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
	int count;
	char board[3][3];
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			board[i][j] = '.';
		}
	}
	printBoard(board);
	for(count=0;;count++)
	{
		modifyBoard(board);
		if(check(board) == 1)
		{
			printf("You win!\n");
			break;
		}
		else if(checkend(board) == 756)
		{
			printf("Game terminated.\n");
			break;
		}
		printf("Please press Enter.");
		printf("Count = %d", count);
		getchar();
                getchar();
		intelligentcomputer(count, board);
		if(check(board) == 2)
		{
			printf("You lose!\n");
			break;
		}
	}
	return 0;
}


