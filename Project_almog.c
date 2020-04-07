/*********************************
* Class: MAGSHIMIM C1			 *
* Week 2           				 *
*                   			 *
**********************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

//setting the max and min to the levels
#define L_MIN 1
#define L_MAX 4
//setting the max and min to the gussing
#define MAX 6
#define MIN 1
//this is the convertion from the askii chart
#define CONV 48

#define MAX_T 20
#define MAD_T 15
#define MIN_T 10

enum level {eazy = 1, moderate, hard, crazy};
enum numbers{One = 1, Two, Three, Four, Five, Six, Seven, Eghit, Nine, Ten};

int try = 0;
int rNum = 0;// this is the secret number that will be genorated
int miss = 0;
int hit = 0;
int secret = 0;
int win = 0;

void inter();
void randNum();
void choose();
void level();
void veryHard();
void check(int c1, int c2, int c3, int c4);
void winG();
void loseG ();

int main ()
{
	int yes = 0;
	
	do{
		randNum();
		choose();
		
		miss = 0;
		hit = 0;
		
		if(win == 1)
		{
			win = 0;
			winG();
			printf("to play again press (y/n): ");
			yes = getche();

			if(yes == 121)
			{
				yes = 1;
			}
		}
		else
		{
			loseG();
			yes = 0;
		}
	}while(yes == 1);
	
	return(0);
}

/*this fanction will print the intredaction*
input - none
output - none*/

void inter()
{
	
	printf("Welcome to MAGSHIMIM CODE-BREAKER!!!\n\n");
	printf("A secret password was chosen to protect the credit card of Pancratius,\n");
	printf("the descendant of Antiochus.\n");
	printf("Your mission is to stop Pancratius by revealing his secret password.\n\n");
	printf("The rules are as follows:\n");
	printf("1. In each round you try to guess the secret password (4 distinct digits)\n");
	printf("2. After every guess you'll receive two hints about the password\n");
	printf("    HITS:   The number of digits in your guess which were exactly right.\n");
	printf("	MISSES: The number of digits in your guess which belongs to\n");
	printf("		the password but were miss-placed.\n");
	printf("3. If you'll fail to guess the password after a certain number of rounds\n");
	printf("	Pancratius will buy all the gifts for Hanukkah!!!\n\n");
	printf("Please choose the game level:\n");
	printf("1 - Easy (20 rounds)\n");
	printf("2 - Moderate (15 rounds)\n");
	printf("3 - Hard (10 rounds)\n");
	printf("4 - Crazy (random number of rounds 5-25)\n");
	
}

/*this fanction will inrduce to the user and will catgoris him
input - none
outpot - none*/	

void choose()
{
	char choice = 0;	
	
	inter();
	
	do{
		printf("Make a choice: ");
		choice = getche() - CONV;
		printf("\n");
		
	}while((choice > L_MAX) || (choice < L_MIN));
	
	if(choice == eazy)
	{
		try = MAX_T;
	}
	else if(choice == moderate)
	{
		try = MAD_T;
	}
	else if(choice == hard)
	{
		try = MIN_T;
	}
	else if(choice  == crazy)
	{
		srand(time(NULL));
		try = (rand() % 22) + 4;
		secret = 1;
	} 
	
	level();
}

/*this fanction will create the secret number
input - none
output - none*/

void randNum()
{
	srand(time(NULL));
	int r = 0;
	int n = 0;
	int u = 0;
	int m = 0; 
	
	do{
		r = (rand() % MAX) + 1;
		n = (rand() % MAX) + 1;
		u = (rand() % MAX) + 1;
		m = (rand() % MAX) + 1;
		
		if((r == n)||(r == u)||(r == m))
		{
			r = (rand() % MAX) + 1;
		}
		else if((n == r)||(n == u)||(n == m))
		{
			n = (rand() % MAX) + 1;
		}
		else if((u == r)||(u == n)||(u == m))
		{
			u = (rand() % MAX) + 1;
		}
		else if((m == r)||(m == u)||(m == n))
		{
			m = (rand() % MAX) + 1;
		}
	}while((m == r)||(m == u)||(m == n)||(u == r)||(u == n)||(n == r));
	
	rNum = (r * 1000) + (n * 100) + (u * 10) + m;
	
}

/*this fanction will count your trys 
input - none
outpot - none*/

void level()
{
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;	
	
	do{
		printf("Write your guess (only 1-6, no ENTER is needed): ");
		c1 = getche() - CONV;
		c2 = getche() - CONV;
		c3 = getche() - CONV;
		c4 = getche() - CONV;
		printf("\n");
		
	}while((c1 > MAX)||(c2 > MAX)||(c3 > MAX)||(c4 > MAX)||(c1 < MIN)||(c2 < MIN)||(c3 < MIN)||(c4 < MIN));
	
	check(c1, c2, c3, c4);
}

/*this fanction will check if the numbers are alined
input - the gussed numbers
output - none*/

void check(int c1, int c2, int c3, int c4)
{
	int flag = rNum;
	int count = 1;
	int div = Ten;
	int true = Four;
	
	
	do{
		while(true != 0)
		{
			count = flag % div;
			if((c1 == count)&&(true == One))
			{
				hit += 1;
			}
			else if(c1 == count)
			{
				miss += 1;
			}
			
			if((c2 == count)&&(true == Two))
			{
				hit += 1;
			}
			else if(c2 == count)
			{
				miss += 1;
			}
			
			if((c3 == count)&&(true == Three))
			{
				hit += 1;
			}
			else if(c3 == count)
			{
				miss += 1;
			}
			
			if((c4 == count)&&(true == Four))
			{
				hit += 1;
			}
			else if(c4 == count)
			{
				miss += 1;
			}
			
			flag /= Ten;
			true --;
		}
		
		flag = rNum;
		true = Four ;
		try -= 1;
		
		if((secret != 1)&&(hit != Four))
		{
			printf("\nyou got %d more trys\n",try);
		}
		if(hit != 4)
		{
			printf("%d MISS   %d HITS\n",miss, hit);
			miss = 0;
			hit = 0;
			
			do{
				printf("Write your guess (only 1-6, no ENTER is needed): ");
				c1 = getche() - CONV;
				c2 = getche() - CONV;
				c3 = getche() - CONV;
				c4 = getche() - CONV;
				printf("\n");
			
			}while((c1 > MAX)||(c2 > MAX)||(c3 > MAX)||(c4 > MAX)||(c1 < MIN)||(c2 < MIN)||(c3 < MIN)||(c4 < MIN)||(c1 == c2)||(c1 == c3)||(c1 == c4)||(c2 == c3)||(c2 == c4)||(c3 == c4));
			
			count = 1;
		}
		else{
			try = 0;
			win = 1;
		}
	}while(try != 0);
}

/*this fanction will print the ascii art
output - none
input - none*/

void winG()
{
	printf("	  ____  _____       __      ______   __     ______  _    _  __          ______  _   _   _ _ _ _ \n");
	printf(" 	 |  _ \\|  __ \\     /\\ \\    / / __ \\  \\ \\   / / __ \\| |  | | \\ \\        / / __ \\| \\ | | | | | | |\n");
	printf("	 | |_) | |__) |   /  \\ \\  / / |  | |  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / / |  | |  \\| | | | | | |\n");
	printf("	 |  _ <|  _  /   / /\\ \\ \\/ /| |  | |   \\   /| |  | | |  | |   \\ \\/  \\/ /| |  | | . ` | | | | | |\n");
	printf("	 | |_) | | \\ \\  / ____ \\  / | |__| |    | | | |__| | |__| |    \\  /\\  / | |__| | |\\  | |_|_|_|_|\n");
	printf("	 |____/|_|  \\_\\/_/    \\_\\/   \\____/     |_|  \\____/ \\____/      \\/  \\/   \\____/|_| \\_| (_|_|_|_)\n");
}

/*this fanction will print the ascii art
output - none
input - none*/

void loseG()
{
	printf("	                                          _                \n");
	printf("                                                 | |               \n");
	printf("  ___  ___  _ __ _ __ _   _   _   _  ___  _   _  | | ___  ___  ___ \n");
	printf(" / __|/ _ \\| '__| '__| | | | | | | |/ _ \\| | | | | |/ _ \\/ __|/ _ \\\n");
	printf(" \\__ \\ (_) | |  | |  | |_| | | |_| | (_) | |_| | | | (_) \\__ \\  __/\n");
	printf(" |___/\\___/|_|  |_|   \\__, |  \\__, |\\___/ \\__,_| |_|\\___/|___/\\___|\n");
	printf("                       __/ |   __/ |                               \n");
	printf("                      |___/   |___/                                \n");
}