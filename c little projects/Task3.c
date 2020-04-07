/*********************************
* Class: MAGSHIMIM C1			 *
* Daniel's binary search  		 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define FALSE 0
#define TRUE !FALSE
#define NOT_FOUND -1

#define ARR_LEN 10

int binarySearch(int arr[], int len, int val);
/*
Bugs Report:
1.arr2[] did not set to zero
2.the varible found was set to a true value so the loop didn't begon
3.the fonction wasn't sighend by 
4.he forgot the case were there is no number in the given array
5.the if statment was not correct becouse -1 is true 
6. the statment in the function return was oppisit
*/


int main(void)
{
	int arr[ARR_LEN] = {0,1,4,6,8,9,10,11,40,42};	
	int val = 0;
	int	res = 0;
	int arr2[] = {0};
	
	printf("Enter a number to search for in my array!\n");
	
	scanf("%d", &val);
	res = binarySearch(arr, ARR_LEN, val);
	if(res == NOT_FOUND)
	{
		printf("Number not found\n");
	}
	else
	{
		printf("Number found, index: %d\n", res);	
	}
	
	
	// Testing empty array
	//printf("Result for empty array: %d", binarySearch(arr2, 0, 1));
	return 0;
}


/*
This function will search an array for a value. 
input: 
arr - a sorted array of numbers
len - length of the array
val - value to search in the array
output: the index of the value in the array.
		-1 if value not found in the array 
*/
int binarySearch(int arr[], int len, int val)
{
	int found = 0;
	
	int start = 0;
	int end = len;
	int counter = 0;
	int log = log2(10) + 1;
	
	int mid = 0;
	
	while(!found && (start < end) && (counter < log))
	{
		mid = (start + end) / 2;
		if(val == arr[mid])
		{
			found = TRUE;
		}
		else if(val > arr[mid])
		{
			start = mid;
			
		}
		else
		{
			end = mid;
		}
		counter++;
		
	}
	
	return !found && (counter == log) ? NOT_FOUND : mid;
}





