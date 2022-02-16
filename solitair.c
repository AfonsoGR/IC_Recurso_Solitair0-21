#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constant variables */
#define MSG_WIN "You Win! Congratulations!"
#define MSG_LOSE "You Lost! Better luck next time!"
#define DEFAULT_SUM 10
#define DEFAULT_SEED 7
#define DEFAULT_NROWS 12
#define DEFAULT_NHOLDS 2
#define DEFAULT_LEVEL 3	
#define PI 3.14159265358979

/* Function declaration */
double uniRand(void);
double randn(double, double);
int randn_sat(double, double, int, int);
void drawBoard(int, int, int [], int [], int [], int []);
int playerMove(int, int [], int [], int [], int []);

/*typedef struct _board
{
	int * left;
	int * right;
	
} board;*/

int main(int argc, char ** argv)
{	
	long seed;
	int level = DEFAULT_LEVEL; 
	int nrows = DEFAULT_NROWS;
	int nhold = DEFAULT_NHOLDS;
	int currentSum = DEFAULT_SUM;
	/*board game;*/

	/* Allocs memory */
		/*board.*left = (int *) malloc(100*sizeof(int));
		board.*right = (int *) malloc(100*sizeof(int));*/
	
	int left[nrows];
	int right[nrows];
	int holdLeft[nhold];
	int holdRight[nhold];
	
	/* Set initial values for left hold column */
	for (int i = 0 ; i < nhold ; i++)
	{
		holdLeft[i] = 0;
		printf("Initial hold value set to %d", holdLeft[i]);
	}
	/* Set initial values for right hold column */
	for (int i = 0 ; i < nhold ; i++)
	{
		holdRight[i] = 0;
		printf("Initial hold value set to %d", holdRight[i]);
	}

	/* Generate numbers for the right column: */
	for (int i = 0 ; i < nrows ; i++)
	{
		left[i] = randn_sat(0, level, -21, 21);
		printf("Value %d added", left[i]);
	}
	/* Generate numbers for the right column: */
	for (int i = 0 ; i < nrows ; i++)
	{
		right[i] = randn_sat(0, level, -21, 21);
		printf("Value %d added", right[i]);
	}

	if (argc == 5)
	{
		/* Verify for command line arguments */
		sscanf(argv[1], "%d", &level);
		sscanf(argv[2], "%ld", &seed);
		sscanf(argv[3], "%d", &nrows);
		sscanf(argv[4], "%d", &nhold);
		

		/* Initialize the random seed of the board */
		srand(seed);

		/* Draws the board's initial state based on arguments */
		void drawBoard(int nrows, int currentSum, int left[], int right[], int holdLeft[], int holdRight[]);

		/* Core game loop */
		while (currentSum > 0 || currentSum < 21)
		{
			int playerMove(int currentSum, int left[], int right[], int holdLeft[], int holdRight[]);
			void drawBoard( int nrows, int currentSum, int left[], int right[], int holdLeft[], int holdRight[]);
		}
		
		return 0;
	}
	else
	{
		printf("Lacking needed arguments");
	}
}

/* function: uniRand()
 * return: double
 * parameters: none
 * description:
 * 	generate random number between within [0 - 1] 
 */
double uniRand()
{
	return (double) rand() / RAND_MAX;
}

/* function: randn()
 * return: double
 * parameters:
 * 	double mean - the mean of the normal distribution
 * 	double std - the standard deviation of the normal distribution
 * description:
 * 	generate random number following a normal distribution using
 *	Box–Muller transform.
 */
double randn(double mean, double std)
{
	double u1, u2, z;

	u1 = uniRand();
	u2 = uniRand();

	z =  sqrt(-2*log(u1))*cos(2*PI*u2);

	/* Multiply by the standard deviation and add the mean.*/
	return std * z + mean;
}

/* function: randn_sat()
 * return: int
 * parameters:
 * 	double mean - the mean of the normal distribution
 * 	double std - the standard deviation of the normal distribution
  * 	int min - the minimum value
 * 	int max - the maximum value
 * description:
 * 	generate random number following a normal distribution and saturated
 * 	to the interval [min, max]
 */
int randn_sat(double mean, double std, int min, int max)
{
	double r = randn(mean, std);
	return (int) (r > max ? max : r < min ? min : r);
}

void drawBoard (int nrows, int currentSum, int left[], int right[], int holdLeft[], int holdRight[])
{
	printf("\n+-----+-----+---+-----+-----+\n|HOLD |LEFT |///|RIGHT|HOLD |\n+-----+-----+---+-----+-----+\n");

	for (int i = 0; i < nrows; i++)
	{
		printf("|  %d  |  %d  |///|  %d  |  %d  |\n", holdLeft[i], left[i], right[i], holdRight[i]);
	}

	printf("+-----+-----+---+-----+-----+\n|SUM = %d                   |\n+---------------------------+\n", currentSum);
}

int playerMove(int currentSum, int left[], int right[], int holdLeft[], int holdRight[])
{
	int playerChoice = 0;
	char option;
	
	scanf("%c", &option);

	switch (option)
	{
		case 'a':
			/* Assign value from left column array to player choice */
			left[-1] = playerChoice;
			break;
		case 's':
			/* Assign value from left column array to player choice */
			right[-1] = playerChoice;
			break;
		case 'q':
			/*Add to left hold array from left column array*/
			holdLeft[-1] = left[-1];
			break;
		case 'w':
			/*Add to right hold array from right column array*/
			holdRight[-1] = right[-1];
			break;
		case 'z':
			/* Assign value from left hold column array to player choice */
			holdLeft[-1] = playerChoice;
			break;
		case 'x':
			/* Assign value from left hold column array to player choice */
			holdRight[-1] = playerChoice;
			break;
		case 'e':
			exit(0);
			break;
		default:
			printf("\nPlease press a valid option.\n");
			break;
	}

	currentSum += playerChoice;

	return currentSum;
}