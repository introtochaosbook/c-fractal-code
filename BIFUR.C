/* compute and display bifurcation diagram for

	f(x) = x^2 +c

	12-21-93		Phil Laplante
	01-15-94		Scott Farbman

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "graph.h"

int i,j;			/*	loop variables */
int MaxX; 		/* Maximum X screen coordinate */
int MaxY; 		/* Maximum Y screen coordinate */
float x;  		/* iterated value */
float c;		/* constant of iteration */
int MaxColor;	/* maximum number of colors on graphics card */
float scale;	/*	plotting scal factor */
float sf;		/* user input scale factor */

void main(void)
{
	/* initialize graphics */
	startgraph();

	/* get user scale factor */
	cleardevice();
	printf("input scale factor (1-10) ");
	scanf("%f",&sf);
	cleardevice();

	MaxColor = getmaxcolor();	/* find maximum number of colors */
	MaxX = getmaxx();				/* find maximum X screen coordinate */
	MaxY = getmaxy();				/* find maximum Y screen coordinate  */

	scale = sf*MaxX/8;			/* calculate overall scale factor */

	c = -2.0;						/* set starting point */

	for (i=1;i<=MaxX;i++)
	{
		x = 0.0;						/* calculate orbit about x = 0 */
		c = c + 2.25/MaxX;			/* iterate c */
		for (j=1;j<=200;j++)		/* calculate orbit after 200 iterations */
		{
			x = x*x + c;
			if (j>50)            /* skip first 50 iterations */
			{
				putpixel(i,(MaxY/2 + x*scale), j/MaxColor);
			}
		}
	}
	getch();
	closegraph();
}