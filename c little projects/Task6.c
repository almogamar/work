/*********************************
* Class: MAGSHIMIM C1			 *
* Daniel's binary search  		 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

enum define{Row = 4, Cols = 4};

int oneS = 0;
int twoS = 0;
int oneD = 0;
int twoD = 0;
int oneL = 0;
int twoL = 0;// those varibals are to count the sum of each segment

void fill(int matrix[][Cols]);
void pr(int matrix[][Cols]);
void check(int matrix[][Cols]);
int diag(int matrix[][Cols], int i);
int lineUpDown(int matrix[][Cols], int i);
int sideLine(int matrix[][Cols], int i);

int main(void)
{
	int matrix[Row][Cols] = {0};
	
	fill(matrix);
	check(matrix);
	pr(matrix);
	
	return (0);
}
 
 /*this function will fill the matrix with numbers
 input - the matrix array
 output - NULL*/
 
void fill(int matrix[][Cols])
{
	int i = 0;
	int j = 0;
	
	for(i = 0; i < Row; i++)
	{
		for(j = 0; j < Cols; j++)
		{
			printf("Please put the value for cell [%d][%d]\n",i, j);
			scanf("%d",&matrix[i][j]);
			
		}
		printf("\n");
	}
}

/*this function will cheack whether it is a matrix or not
input - the sum of the sides and the daignal lines 
output - none*/

void check(int matrix[][Cols])
{
	int i = 0;
	
	int nal = 0;
	int upDown = 0;
	int sides = 0;
	
	for(i = 0;i < Row; i++)
	{
		nal  = diag(matrix, i);
		sides = sideLine(matrix, i);
		upDown = lineUpDown(matrix, i);
	}
	
	printf("Is it a matrix?\n");
	
	if((nal == upDown) && (upDown == sides) && diag)
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No!\n");
	}
	
}

/*this function will find sum of the diagnal lines 
input - the matrix
output - the sum of the daiganal lines*/

int diag(int matrix[][Cols], int i)
{
	
	oneD += matrix[i][i];
	twoD += matrix[Row - i -1][Cols - i -1];
	
	printf("%d, %d - diag\n",oneD, twoD);
	
	if(oneD == twoD)
	{
		return oneD;
	}
	else
	{
		return 0;
	}
}

/*this function will find the sum of the sides of the matrix
input - the matrix 
output - the sum*/

int sideLine(int matrix[][Cols], int i)
{
	
	oneS += matrix[i][0];
	twoS += matrix[Cols -i - 1][0];
	
	printf("%d, %d - side\n",oneS, twoS);
	
	if(oneS == twoS)
	{
		return oneS;
	}
	else
	{
		return 0;
	}
}

/*this function will find the sum of the up and down sides of the matrix
input - the matrix 
output - the sum*/

int lineUpDown(int matrix[][Cols], int i)
{
	
	oneL += matrix[0][i];
	twoL += matrix[Row - 1][i];
	
	printf("%d, %d - line\n\n",oneL, twoL);
	
	if(oneL == twoL)
	{
		return oneL;
	}
	else
	{
		return 0;
	}
	
}

/*this functoion will print the matrix 
input - the matrix
output- none*/

void pr(int matrix[][Cols])
{
	int i = 0;
	int j = 0;
	
	for(i = 0; i < Row; i++)
	{
		for(j = 0; j < Cols; j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}