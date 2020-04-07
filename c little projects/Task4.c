/*********************************
* Class: MAGSHIMIM C1			 *
* Daniel's binary search  		 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

enum def{Len = 17, Max = 256};

void countingSort(int arr[]);
void pt(int old[], int new[]);

int main(void)
{
	int arr[Len] = {0};
	
	int i = 0;
	
	printf("Enter 17 numbers: \n");
	
	for(i = 0; i < Len; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	countingSort(arr);
}

/*this function will sort the given array
input - the array i will later on sort
output - none */

void countingSort(int arr[])
{
	int mid[Max] = {0};
	int new[Len] = {0};
	
	int i = 0;
	int j = 0;
	
	int ind = 0;
	int fChange = 0;
	int index = 0;
	
	
	for(i = 0; i < Len; i++)
	{
		mid[arr[i]] += 1;
	}
	
	for(i = 0; i < Max; i++)
	{
		mid[i + 1] += mid[i];
	}
	
	for(i = Len; i >= 0; i--)
	{
		index = arr[i];
		fChange = mid[index] - 1;
		
		new[fChange] = arr[i];
		
		mid[arr[i]]--;
	}
	
	pt(arr,new);
}

/*this function will print the two arrays of number 
input - the unsorted array and the sorted array
output - NULL*/

void pt(int old[], int new[])
{
	int j = 0;
	
	printf("Before:\n");
	
	for(j = 0; j < Len; j++)
	{
		printf("%d ",old[j]);
	}
	
	printf("\nAfter:\n");
	
	for(j = 0; j < Len; j++)
	{
		printf("%d ",new[j]);
	}
}
	