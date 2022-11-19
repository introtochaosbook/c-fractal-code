/* compute and display unfilled Mandelbrot set
  12-21-93   Phil Laplante
  02-01-94	 Scott Farbman
*/

#include "cplex.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "graph.h"


float	zoom=2.0;                 	/* create 4 by 4 window */
float escape=4.0;           		/* escape value */


int	i, j;           /* loop variables*/
int	MaxY;           /* Maximum Y screen coordinate*/
float	scale;          /* scale factor */
float	mag;            /* square of magnitude of complex number */
int	iter;           /* escape iteration counter */
float cx,cy;				 /* x and y components of c */
float	x, y;           /* coordinate values in complex plane */
int	MaxColor;       /* maximum number of colors on graphics card */

void main(void)
{

	/* initialize graphics */
	startgraph();


	MaxColor = getmaxcolor(); /* find maximum number of colors */
	MaxY = getmaxy();         /* find maximum Y screen coordinate */
	scale= 2.0*zoom/MaxY;   /* calculate zoom factor*/

	x = 0;			/* set z0 = 0 + 0i */
	y = 0;


	for (i = 0; i <= MaxY; i++)    /* MaxY is usually smaller than MaxX */
	{
		 for (j = 0; j <= MaxY; j++)
			{
				x = 0;							  /*	set z0 = 0 + 0i */
				y = 0;
				cx = scale*i-zoom;            /* set starting value of real(z) */
				cy = zoom-scale*j;            /* set starting value of imag(z) */
				iter =0;
				mag = 0;
				while ((iter < MaxColor*2) && (mag < escape))
				{
					 mult(x,y,x,y,&x,&y);            /* square z */
					 add(x,y,cx,cy,&x,&y);           /* add c */
					 mag = x*x + y*y;						/* calc square of magnitude */
					 iter++;
				}  /* while loop*/
				if (mag > escape)  					/* color escaping points */
					putpixel(i,j,iter/2);

			 }  /*j loop*/
	}/* i loop*/
	getch();
	closegraph();
}



