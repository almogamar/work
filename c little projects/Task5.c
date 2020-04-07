/*********************************
* Class: MAGSHIMIM C1			 *
* Daniel's binary search  		 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <time.h>
#include <math.h>

#define END 0

enum define{Max = 26};

int sLen(char arr[]);
void sNcat(char dst[], char src[], int len);


int main(void)
{
	char arr1[Max] = " ";
	char arr2[Max] = " ";
	
	int len1 = 0;
	int len2 = 0;
	
	printf("Enter your first word: ");
	fgets(arr1, Max, stdin);
	
	printf("Enter second string: ");
	fgets(arr2, Max, stdin);
	
	len1 = sLen(arr1);
	len2 = sLen(arr2);
	
	printf("first string lenght: %d\n",len1);
	printf("second string lenght: %d\n",len2);
	
	sNcat(arr1, arr2, len2);
	return (0);
}

/*this function will give me the lenght of the string
input - the string i want to check for is lenght
output - the len of the string*/

int sLen(char arr[])
{
	int len = -1;
	int flag = 1;
	
	while(len <= Max - 1 && flag)
	{
		len++;
		
		if(arr[len] == END)
		{
			flag = 0;
		}
	}
	
	len -= 1;//this subtraction is becuse the loop will end and add a false value
	
	return len;
}

/*this function will copy the first second string to the first one
input - the first and the second string and the number of chars thet i will need to append
output - nune*/

void sNcat(char dst[], char src[], int len)
{
	int lenOfDst = sLen(dst) ;//we subtract the one to replace the null in the first string
	
	int i = 0;
	int j = 0;
	
	
	
	for(i = lenOfDst; i < len + lenOfDst; i++, j++)
	{
		dst[i] = src[j];
	}
	printf("%s\n",dst);
}
