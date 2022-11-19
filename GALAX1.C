  /* compute and display view of space using Michael Barnsley's
  IFS algorithm.

  12-5-93  Phil Laplante                  */

#include <time.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

float x, y;          /* pixel coordinates */
int	i,j;			   /* loop counter*/
int   k;					/* row selector */
int   MaxX;		      /* Maximum X screen coordinate*/
float	d[5][6];	 		/* holds data of IFS attractor */
float	scale;         /* random scale factor*/
int	xpos,ypos;     /* tree position */

void main(void)
{
	/* initialize graphics */
	startgraph();
	
	MaxX = getmaxx();

/* initialize IFS data array */

d[0][0]=0.33;d[0][1]=0;d[0][2]=0; d[0][3]=0.33; d[0][4]=1;      d[0][5]=1;
d[1][0]=0.33;d[1][1]=0;d[1][2]=0; d[1][3]=0.33; d[1][4]=MaxX;   d[1][5]=1;
d[2][0]=0.33;d[2][1]=0;d[2][2]=0; d[2][3]=0.33; d[2][4]=1;      d[2][5]=MaxX;
d[3][0]=0.33;d[3][1]=0;d[3][2]=0; d[3][3]=0.33; d[3][4]=MaxX;   d[3][5]=MaxX;
d[4][0]=0.33;d[4][1]=0;d[4][2]=0; d[4][3]=0.33; d[4][4]=MaxX/2; d[4][5]=MaxX/2;

	MaxX = getmaxx();

	randomize();           /*initialize random number generator*/

	x = 0;              /*set starting coordinates*/
	y = 0;

	for (j = 1; j<=150; j++)                       /* make stars */
	 {
	  xpos = random(MaxX);                    /* pick star position */
	  ypos = random(MaxX);
	  scale = (random(5)+1)*.001;             /* pick star scale */

	  for (i = 1; i <= 800; i++)
	  {
		  k = random(5);                  /* pick random row */
		  x = d[k][0]*x + d[k][1]*y + d[k][4];   /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];
		  if (i > 10)                        /* skip first 10 iterations */
			  putpixel((scale*x+xpos),(scale*y+ypos),WHITE);
	  }
	 }
	getch();
	closegraph();
}




