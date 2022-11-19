/* compute and display a Siegel disk -- the Julia set of
 f(z) = z^2 -0.39054 -0.58679i

  1-02-92  Phil Laplante
  2-12-94  Scott Farbman

*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "graph.h"
#include "cplex.h"


float zoom=2.0;                 /* create 4 by 4 window */
float attract=0.0001;           /* attractor sensitivity */
int	i, j;    					  /* loop variables*/
int   MaxY;    					  /* Maximum Y screen coordinate*/
float scale;                    /* scale factor */
float mag;                      /* square of magnitiude of complex number */
int   iter;                     /* escape iteration counter */
int	cont;       		        /* continue iteration conter */
float x, y;                     /* real and imaginary parts of z */
int	MaxColor;                 /* maximum number of colors on graphics card */

void main (void)
{

	startgraph();				/* initialize graphics */
	MaxColor = getmaxcolor(); /* find maximum number of colors */
	MaxY = getmaxy();         /* find maximum Y screen coordinate */
	scale= 2.0*zoom/MaxY;   /* calculate zoom factor*/

	for (i = 0; i <= MaxY; i++)    /* MaxY is usually smaller than MaxY */
	{
		 for (j = 0; j <= MaxY; j++)
		 {
				x = scale*i-zoom;            /* set starting value of real(z) */
				y = zoom-scale*j;            /* set starting value of imag(z) */
				cont = 1;             /* assume point does not escape  */
				iter =0;
				while (cont == 1)
				{
					 mult(x,y,x,y,&x,&y);        /* square z */
					 add(x,y,-0.390540,-0.58679,&x,&y); /* add constant */
					 mag = x*x+y*y;       /* calculate square of magnitude */
					 if (mag < attract)
						cont = 0;       /* point is an attractor */
					 else
						if ((mag < 100) && (iter < MaxColor*2)) /* keep iterating function */
							iter ++;
						else                     /* point escapes, plot it */
							{
							  putpixel(i,j, iter / 2);
							  cont = 0;        /* get out of loop */
							}
				}  /* while loop*/
		 }  /*j loop*/
	}/* i loop*/
	getch();
	closegraph();
}



