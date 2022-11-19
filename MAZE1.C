/* compute and display a "maze"
  using Michael Barnsley's IFS algorithm

  12-5-93  Phil Laplante
  02-1-94  Scott Farbman
*/

#include <time.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"           /* include graphics package*/

float		x, y;      				    /* pixel coordinates */
long  	i;           				 /* loop counters*/
int 		k;      				       /* row selector */
int  		MaxY;      					 /* maximum Y screen coordinate*/
float  	d[6][6];						 /* holds data of IFS attractor */

void main(void)
{
	startgraph();				 /* call routine to initialize graphics */

	MaxY = getmaxy();          /* get screen limits */

/* initialize IFS data array */

	d[0][0]=0.33; d[0][1]=0; d[0][2]=0; d[0][3]=0.33; d[0][4]=1;  d[0][5]=1;
	d[1][0]=0.33; d[1][1]=0; d[1][2]=0; d[1][3]=0.33; d[1][4]=MaxY/2; d[1][5]=1;
	d[2][0]=0.33; d[2][1]=0; d[2][2]=0; d[2][3]=0.33; d[2][4]=1;  d[2][5]=MaxY/2;
	d[3][0]=0.33; d[3][1]=0; d[3][2]=0; d[3][3]=0.33; d[3][4]=MaxY/2; d[3][5]=MaxY;
	d[4][0]=0.33; d[4][1]=0; d[4][2]=0; d[4][3]=0.33; d[4][4]=MaxY; d[4][5]=MaxY;
	d[5][0]=0.33; d[5][1]=0; d[5][2]=0; d[5][3]=0.33; d[5][4]=1; d[5][5]=MaxY;


	randomize();           /*initialize random number generator*/

	x = 0;              /*set starting coordinates*/
	y = 0;

	 for (i = 1; i <= 320000;i++)
	  {
		  k = random(8);                  /* pick random row */
		  x = d[k][0]*x + d[k][1]*y + d[k][4];   /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];
		  if (i > 10)                        /* skip first 10 iterations */
			  putpixel((2*x/3),(2*y/3),DARKGRAY );
	 }
	 getch();
	 closegraph();
}