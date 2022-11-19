/* compute and display Sierpinski triangle
  using Michael Barnsley's IFS algorithm

  12-5-93  Phil Laplante
  2-12-94  Scott Farbman

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "graph.h"                    /*include graphics package*/

float		x, y      ;     /* pixel coordinates */
int   	i         ;     /* loop counter */
int   	MaxY      ;     /* maximum X and Y coordinates*/
int   	k         ;     /* select random row */
float   	d[3][6];			 /* holds data of IFS attractor */

void main (void)
{
	startgraph();

/* initialize IFS data array */

	d[0][0]=0.5; d[0][1]=0; d[0][2]=0; d[0][3]=0.5; d[0][4]=25;  d[0][5]=1;
	d[1][0]=0.5; d[1][1]=0; d[1][2]=0; d[1][3]=0.5; d[1][4]=1; d[1][5]=50;
	d[2][0]=0.5; d[2][1]=0; d[2][2]=0; d[2][3]=0.5; d[2][4]=50;  d[2][5]=50;

	MaxY = getmaxy();

	randomize();           /*initialize random number generator*/

	x = 0.0;  /*set starting coordinates*/
	y = 0.0;

	for (i = 1; i <= 30000; i++)
	  {
		  k = random(3);                  /* pick random row */
		  x = d[k][0]*x + d[k][1]*y + d[k][4];   /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];
		  if (i > 10)                       /* skip first 10 iterations */
			  putpixel(x*MaxY/100,y*MaxY/100,WHITE); /* convert to screen*/
	  }
	getch();
	closegraph();
}




