/*********************************
* Class: MAGSHIMIM C1			 *
* Daniel's binary search  		 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(void)
{
	char arr[26] = " ";
	char arr2[26] = " ";
	int i = 0;
	
	fgets(arr, 26, stdin);
	fgets(arr2, 26, stdin);
	printf("first - %d\n",strlen(arr));
	printf("second - %d\n",strlen(arr2));
	while(i < 9)
	{
		printf("c - %c\n",arr[i]);
		
		i++;
	}
	i = 0;
	
		printf("c - %s\n",arr2);
	
	return (0);
}
