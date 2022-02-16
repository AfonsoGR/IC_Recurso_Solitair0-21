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
void drawBoard(int);
void playGame(int);
/*int playerMove();*/
int updateSum(int, int);
/*void boardUpdate();*/

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

	int left[DEFAULT_NROWS];
	int right[DEFAULT_NROWS];
	
	/* Verify for command line arguments */
	sscanf(argv[1], "%d", &level);
	sscanf(argv[2], "%ld", &seed);
	sscanf(argv[3], "%d", &nrows);
	sscanf(argv[4], "%d", &nhold);

	/* Initialize the random seed of the board */
	srand(seed);
	
	/* Allocs memory */
	/*board.*left = (int *) malloc(100*sizeof(int));
	board.*right = (int *) malloc(100*sizeof(int));*/
	

	/* Generate numbers for the right column: */
	for (int i = 0 ; i < nrows ; i++)
	{
		left[i] = randn_sat(0, level, -21, 21);
	}

	/* Generate numbers for the right column: */
	for (int i = 0 ; i < nrows ; i++)
	{
		right[i] = randn_sat(0, level, -21, 21);
	}

	/* Draws the board's initial state based on arguments */
	void drawBoard(int nrows);

	/* Core game loop */
	while (currentSum > 0 || currentSum < 21)
	{
		void playGame(int currentSum);
	}
	
	return 0;
}

/* function: uniRand()
 * return: double
 * parameters: none
 * description:
 * 	generate random number between within [0 - 1] 
 */
double uniRand()
{
	return (double) rand() / double RAND_MAX;
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

void playGame(int currentSum)
{
	/*int playerMove();*/
	int updateSum(int currentSum, int playerChoice);
	/*void boardUpdate();*/
}

void drawBoard (int nrows)
{
	printf("+-----+-----+---+-----+-----+\n|HOLD |LEFT |///|RIGHT|HOLD |\n+-----+-----+---+-----+-----+");

	for (int i = 0; i < nrows; i++)
	{
		printf("|     |  *  |///|  *  |     |");
	}

	printf("+-----+-----+---+-----+-----+\n|SUM = %d                   |\n+---------------------------+", DEFAULT_SUM);
}

int updateSum(int currentSum, int playerChoice)
{
	currentSum += playerChoice;

	return currentSum; 
}