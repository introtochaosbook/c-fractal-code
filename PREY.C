/*
	Simulate Wolf- Caribou populations
	1/29/93	Phil Laplante
	2/1/94	Scott Farbman
*/

#include <stdio.h>
#include <conio.h>

float caribou_O;				/* initial caribou population */
float wolf_O;					/* initial wolf population */

float caribou;					/* current caribou population */
float wolf;						/*	current wolf population */

float caribou_p ;				/*	previous caribou population */
float wolf_p;					/* previous wolf population */

float caribou_b ;				/*	caribou birth rate  */
float wolf_d;					/* wolf death rate */
float K;							/* contact-death ratio */

int iter;						/* number of iterations to track */

int i;

void main(void)
{
	clrscr();
	printf(" Enter initial caribou population ");
	scanf("%f",&caribou_O);
	printf(" Enter initial wolf population ");
	scanf("%f",&wolf_O);
	printf(" Enter caribou birth rate ");
	scanf("%f",&caribou_b);
	printf(" Enter wolf death rate ");
	scanf("%f",&wolf_d);
	printf(" Enter contact-death rate ");
	scanf("%f",&K);
	printf(" Enter number of iterations (months) for simulation ");
	scanf("%d",&iter);

	caribou_p = caribou_O;
	wolf_p = wolf_O;

	printf("Press enter to begin simulation ");
	getch();

	printf("\n				wolves				caribou ");
	for (i=1;i<=iter; i++)
	{
		if (i % 22 == 0)
		{
			printf("\npress enter to continue");
			getch();
			clrscr();
			printf("\n		  	  wolves			caribou ");
		}
	  /* calculate and output current populations, truncate to nearest integer */
		caribou = caribou_p + caribou_b * caribou_p - K * caribou_p * wolf_p;
		wolf    = wolf_p + K * caribou_p * wolf_p - wolf_d * wolf_p;
		printf("\n month %d	 	%9.0f		%9.0f ",i,wolf,caribou);

		caribou_p = caribou; /* reset previous generation counters */
		wolf_p = wolf;
	}
	getch();
}


