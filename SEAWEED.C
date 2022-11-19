/* compute and display seaweed
  using Michael Barnsley's IFS algorithm

  12-5-93  Frank D'Erasmo
  2-12-94  Scott Farbman

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "graph.h"                    /*include graphics package*/

float   x, y;     /* pixel coordinates */
long    i;      	/* loop counters*/
int     k;      	/* row selector */
int     MaxY;     /* Maximum Y screen coordinate*/
float   d[4][6];	/* holds data of IFS attractor */

void main (void)
{
	startgraph();
	MaxY = getmaxy();

/* initialize IFS data array */

	d[0][0]=0.5;  d[0][1]=0;  d[0][2]=0;  d[0][3]=0.5;  d[0][4]=0; d[0][5]=0;
	d[1][0]=0.5;  d[1][1]=0;  d[1][2]=0;  d[1][3]=0.5;  d[1][4]=2; d[1][5]=0;
	d[2][0]=0.4;  d[2][1]=0;  d[2][2]=1;  d[2][3]=0.4;  d[2][4]=0; d[2][5]=1;
	d[3][0]=0.5;  d[3][1]=0;  d[3][2]=0;  d[3][3]=0.5;  d[3][4]=2; d[3][5]=1;


	randomize();           /*initialize random number generator*/

	x = 0;              /*set starting coordinates*/
	y = 0;

	for (i = 1; i <= 320000; i++)                   /*320][000 pixels*/
	  {
		  k = random(4);                /*pick random number from 1-4*/
		  x = d[k][0]*x + d[k][1]*y + d[k][4]; /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];
		  if (i > 10)                        /* skip first 10 iterations */
				 putpixel(MaxY*x/2,MaxY-MaxY*y/2,GREEN);
	  };                               /* scale for screen */
	getch();
	closegraph();

}