#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MSG_WIN "You Win! Congratulations!"
#define MSG_LOSE "You Lost! Better luck next time!"
#define DEFAULT_SUM 10
#define DEFAULT_SEED 7
#define DEFAULT_NROWS 12
#define DEFAULT_NHOLDS 2
#define DEFAULT_LEVEL 3	
#define PI 3.14159265358979

/* needed functions */
double uniRand(void);
double randn(double, double);
int randn_sat(double, double, int, int);

typedef struct _board
{
	int * left;
	int * right;
	
} board;

int main(int argc, char ** argv)
{	
	long seed = DEFAULT_SEED;
	int level = DEFAULT_LEVEL, nrows = DEFAULT_NROWS, nhold = DEFAULT_NHOLDS;
	board game;
	
	/* Verify for command line arguments */
	sscanf(argv[1], "%d", &level);
	sscanf(argv[2], "%ld", &seed);
	sscanf(argv[3], "%d", &nrows);
	sscanf(argv[4], "%d", &nhold);


	/* Initialize the random seed of the board */
	srand(seed);
	
	/* Alloc memory */
	board.left = (int *) malloc(100*sizeof(int));
	board.right = (int *) malloc(100*sizeof(int));
	
	/* generate numbers left: */
	for (int i = 0 ; i < nrows ; i++)
		left[i] = randn_sat(0, level, -21, 21);

	/* generate numbers right: */
	for (int i = 0 ; i < nrows ; i++)
		right[i] = randn_sat(0, level, -21, 21);

	while (true)
	{
		playGame();
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

void play()
{
	drawBoard(int, int);
	winState(int);
}

drawBoard (int left, int right)
{
	printf("+-----+-----+---+-----+-----+\n|HOLD |LEFT |///|RIGHT|HOLD |\n+-----+-----+---+-----+-----+");

	for (size_t i = 0; i < count; i++)
	{
		printf("|     |  *  |///|  *  |     |");
	}

	printf("+-----+-----+---+-----+-----+\n|SUM = %d                   |\n+---------------------------+", &DEFAULT_SUM);
	
}