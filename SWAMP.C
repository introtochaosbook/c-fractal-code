/* compute and display a swamp
  using Michael Barnsley's IFS algorithm

  12-5-93  Phil Laplante
  2-12-94  Scott Farbman

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "graph.h"                    /*include graphics package*/

float	x, y;       /* pixel coordinates */
int	i, j;      	/* loop counters*/
int   q;      		/* random number */
int	k;      		/* row selector */
int   MaxX;      	/* Maximum X screen coordinate*/
float d[4][6]; 	/* holds data of IFS attractor */
float scale;      /* random scale factor*/
int	xpos,ypos;  /* plant position */
int   crand;      /* pick random color (green, yellow, lightgreen)*/
int	color;      /* random color value */

void main(void)
{
	startgraph();
	MaxX = getmaxx();

/* initialize IFS data array */

	d[0][0]=0.5; d[0][1]=0; d[0][2]=0; d[0][3]=0.25; d[0][4]=1;  d[0][5]=1;
	d[1][0]=0.25; d[1][1]=0; d[1][2]=0; d[1][3]=0.7; d[1][4]=50; d[1][5]=1;
	d[2][0]=0.25; d[2][1]=0; d[2][2]=0; d[2][3]=0.7; d[2][4]=1;  d[2][5]=50;
	d[3][0]=0.5; d[3][1]=0; d[3][2]=0; d[3][3]=0.25; d[3][4]=50; d[3][5]=50;

   randomize();           /*initialize random number generator*/

   x = 0;              /*set starting coordinates*/
   y = 0;

	for (j = 1; j <= 70; j++)                       /* make 70 plants */
	  {
	  xpos = random(MaxX);                    /* pick plant position */
	  ypos = random(MaxX);
	  scale = random(3)+1;                  /* pick plant scale */
	  crand = random(10) + 1;                 /* pick plant color */
	  switch  (crand)
	  {
		  case 0:
		  case 1:
		  case 2:
		  case 3:
		  case 4:
		  case 5:
		  case 6:
		  case 7:
		  case 8:
				 color = GREEN;break;            /* most plants are green */
		  case 9  : color = YELLOW;break;      /* some plants are yellow */
		  case 10 : color = LIGHTGREEN;break;  /* some plants are lightgreen*/
	  };

	  for (i = 1; i <= 3000; i++)
	  {
		  k =random(4);                     /* pick random row */

		  x = d[k][0]*x + d[k][1]*y + d[k][4];   /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];

		  if (i > 10)                       /* skip first 10 iterations */
				 putpixel(xpos + x*scale,ypos - y*scale,color);
	  }
	}
	getch();
	closegraph();
}
