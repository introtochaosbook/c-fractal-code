/*  compute and display Mandelbrot set

  12-21-92  Phil Laplante
  01-31-94  Scott Farbman

*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "cplex.h"
#include "graph.h"


float	zoom =   2.0;                 /* create 4 by 4 window */
float escape = 4.0;						/* escape value */

int   i, j;          /* loop variables*/
int   MaxY;          /* Maximum Y screen coordinate*/
float	scale;         /* scale factor */
float	mag;           /* square of magnitiude of complex number */
int	iter;          /* escape iteration counter */
float cx,cy;         /* x and y components of c */
float x,y;				/* coordinate values in complex plane */

void main(void)
{

	/* initialize graphics */
	startgraph();

	MaxY = getmaxy();         /* find maximum Y screen coordinate */
	scale= zoom*2.0/MaxY;   /* calculate zoom factor*/

	for(i = 0;i<=MaxY;i++)    /* MaxY is usually smaller than MaxX */
	{
		 for (j = 0;j<= MaxY;j++)
		 {
				x = 0;								/* set z0 = 0 + 0i */
				y = 0;

				cx = scale*i-zoom;            /* sweep value of c */
				cy = zoom-scale*j;
				mag = 0;								/* initial loop guards */
				iter =0;
				while ((iter < 30) && (mag < escape))
				{
					 mult(x,y,x,y,&x,&y);        /* square z */
					 add(x,y,cx,cy,&x,&y);    /* add c */
					 mag = x*x+y*y;           /* calculate square of magnitude */
					 iter++;
				} 	  /* while loop*/
					 if (mag < escape)
						putpixel(i,j,BLUE);       /* output blue for non-escape */

		 }  /*j loop*/
	}/* i loop*/
	getch();
	closegraph();
}