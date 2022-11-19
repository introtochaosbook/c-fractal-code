/* compute and display forest of trees
  using Michael Barnsley's IFS algorithm

  12-5-93  Phil Laplante                  */

#include <time.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

float x, y;          /* pixel coordinates */
int	i,j;			   /* loop counter*/
int	q;			      /* random number */
int   k;			      /* row selector */
int   MaxX;		      /* Maximum X screen coordinate*/
float	d[4][6];	 		/* holds data of IFS attractor */
float	scale;         /* random scale factor*/
int	xpos,ypos;     /* tree position */
int	crand;   	   /* pick random color (green, blue, yellow) */
int	color;	      /* random color value */

void main(void)
{
	/* initialize graphics */
	startgraph();
	
	MaxX = getmaxx();

/* initialize IFS data array */

	d[0][0]=0;   d[0][1]=0;    d[0][2]=0;    d[0][3]=0.5; d[0][4]=0; d[0][5]=0;
	d[1][0]=0.42;d[1][1]=-0.42;d[1][2]=0.42; d[1][3]=0.42;d[1][4]=0; d[1][5]=0.2;
	d[2][0]=0.42;d[2][1]=0.42; d[2][2]=-0.42;d[2][3]=0.42;d[2][4]=0; d[2][5]=0.2;
	d[3][0]=0.1; d[3][1]=0;    d[3][2]=0;    d[3][3]=0.1; d[3][4]=0; d[3][5]=0.2;

	randomize();           /*initialize random number generator*/

	x = 0;              /*set starting coordinates*/
	y = 0;

	for (j = 1; j <=150; j++)                       /* make 150 trees */
	  {
	  xpos = random(MaxX);                    /* pick tree position */
	  ypos = random(MaxX);
	  scale = random(3) + 1;                  /* pick tree scale */
	  crand = random(10) + 1;                 /* pick tree color */
	  switch (crand)
	  {
		case  0:
		case  1:
		case  2:
		case  3:
		case  4:
		case  5:
		case  6:
		case  7:
		case  8	 : color = GREEN;break;                  /* most trees are green */
		case  9  : color = YELLOW;break;                 /* some trees are yellow */
		case  10 : color = BROWN;break;                  /* some trees die */
	  };

	  for (i = 1; i <= 800; i++)                    /* 800 pixels per tree */
		{
		  q = random(100) + 1;                /* pick random number from 1-100*/
		  if (q <= 40)                      /* assign row according to */
			  k = 1;                           /* probability */
		  if ((q> 40) && (q < 81))
			  k = 2;
		  if ((q >= 81) && (q < 95))
			  k = 3;
		  if (q >= 95 )
			  k = 0;

		  x = d[k][0]*x + d[k][1]*y + d[k][4];   /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];

		  if (i > 10)                        /* skip first 10 iterations */
				 putpixel(xpos + (x*MaxX/scale),(ypos - y*MaxX/scale),color);
		}
	}
	getch();
	closegraph();
}



