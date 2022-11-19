/* compute and display a "dragon" from the Julia set of

    f(z) = z^2 +  0.360284 + 0.100376i

  12-21-92  Phil Laplante
  01-15-94	Scott Farbman

*/

#include "cplex.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "graph.h"

#define TRUE 1;
#define FALSE 0;


float zoom =2.0;                 /* create 4 by 4 window */
float	attract=0.0001;           /* attractor sensitivity */


int	i, j;           /* loop variables*/
int	MaxY;           /* Maximum Y screen coordinate*/
float	scale;          /* scale factor */
float	mag;            /* square of magnitude of complex number */
int	iter;           /* escape iteration counter */
int	cont;           /* continue iteration counter */
float	x, y;           /* real and complex parts of z */
int	MaxColor;       /* maximum number of colors on graphics card */

void main(void)
{

	/* initialize graphics */
	startgraph();
	
	MaxColor = getmaxcolor(); /* find maximum number of colors */
	MaxY = getmaxy();         /* find maximum Y screen coordinate */
	scale= 2.0*zoom/MaxY;   /* calculate zoom factor*/

	for (i = 0; i <= MaxY; i++)    /* MaxY is usually smaller than MaxX */
	{
		 for (j = 0; j <= MaxY; j++)
		 {
				x = scale*i-zoom;            /* set starting value of real(z) */
				y = zoom-scale*j;            /* set starting value of imag(z) */
				cont = TRUE;             /* assume point does not escape  */
				iter =0;
				while (cont == 1)
				{
					 mult(x,y,x,y,&x,&y);        /* square z */
					 add(x,y,0.360284,0.100376,&x,&y);    /* add constant */
					 mag = x*x+y*y;       /* calculate square of magnitude */
					 if (mag < attract)
						cont = FALSE       /* point is an attractor */
					 else
						if ((mag < 100) && (iter < MaxColor*2))  /* keep iterating function */
							iter = iter+1;
						else                     /* point escapes, plot it */
							{
							  putpixel(i,j, iter / 2);
							  cont = FALSE        /* get out of loop */
							}
				}  /* while loop*/
		 }  /*j loop*/
	}/* i loop*/
	getch();
	closegraph();
}




