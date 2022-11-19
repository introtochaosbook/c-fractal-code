/* compute and display fern
  using Michael Barnsley's IFS algorithm

  12-5-93  Phil Laplante
  1-16-94  Scott Farbman
*/

#include <time.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

float x, y;           /* pixel coordinates */
int	i;			       /* loop counter*/
int	q;			       /* random number */
int   k;			       /* row selector */
int   MaxY;		       /* Maximum Y screen coordinate*/
float d[4][6];			 /* holds data of IFS attractor */


void main(void)
{
	/* initialize graphics */
	startgraph();


	MaxY = getmaxy();

/* initialize IFS data array */

 d[0][0]=0;    d[0][1]=0;    d[0][2]=0;    d[0][3]=0.16;d[0][4]=0; d[0][5]=0;
 d[1][0]=0.85; d[1][1]=0.04; d[1][2]=-0.04;d[1][3]=0.85;d[1][4]=0; d[1][5]=1.6;
 d[2][0]=0.2;  d[2][1]=-0.26;d[2][2]=0.23; d[2][3]=0.22;d[2][4]=0; d[2][5]=1.6;
 d[3][0]=-0.15;d[3][1]=0.28; d[3][2]=0.26; d[3][3]=0.24;d[3][4]=0; d[3][5]=0.44;


	randomize();           /*initialize random number generator*/

	x = 0;              /*set starting coordinates*/
	y = 0;

	for (i = 1; i <=30000; i++)
	  {
		  q = random(100) + 1;                /* pick random number from 1-100*/
		  if (q <= 85)                       /* assign row according to */
			  k = 1;                           /* probability */
		  if (q == 86)
			  k = 0;
		  if ((q > 86) && (q < 94))
			  k = 2;
		  if (q >= 94)
			  k = 3;

		  x = d[k][0]*x + d[k][1]*y + d[k][4];   /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];
		  if (i > 10)                        /* skip first 10 iterations */
				 putpixel((MaxY/2 + MaxY*x/10),(MaxY*y/10),GREEN);
			  }                              /* scale for screen */
			  getch();
			  closegraph();
}


