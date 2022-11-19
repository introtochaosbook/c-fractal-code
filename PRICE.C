/* Price
	Compute and display bifurcation diagram for mini-economic system
	given by:

	P(t + 1) = at - t^2

	12 - 21 - 93 Phil Laplante
	02 - 13 - 94 Scott Farbman

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "graph.h"
#include "cplex.h"

int 	i,j;				/* Loop variables */
int	MaxX;				/* Maximum X screen coordinate */
int 	MaxY;				/* Maximum Y screen coordinate */
double t;		 		/* iterated value */
float a;					/* constant of iteration */
int 	MaxColor; 		/* Maximum number of colors on graphics card */
float	scale;			/* plotting scale factor */

void main (void)
{
	startgraph();					/* Initialize graphics */
	MaxColor  = getmaxcolor();	/* Find maximum number of colors */
	MaxX = getmaxx();       	/* Find maximum X screen coordinates */
	MaxY = getmaxy();				/* Find maximum Y screen cooridantes */

	scale = MaxY / 4;				/* Calculate overall scale factor */
	a		= 2.50;					/* Set starting point */

	for (i=1;i<=MaxX;i++)
	{
		t = 0.9;						/* Calculate orbit about t = 1 */
		a = a + 1.50/MaxX;		/* iterate a */
		for (j=1;j<=100;j++)		/* calculate orbit after 200 iterations */
		{
			t = a*t - a*t*t;		/* calculate new price */
			if (j>50)         	/* skip first 50 iterations */
				putpixel(i,MaxY/2+t*scale,GREEN);
		}
	}
	getch();

	closegraph();
}
