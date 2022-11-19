/* compute and display Sierpinski triangle via random orbits
  12-5-93  Phil Laplante
  2-12-94  Scott Farbman
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "graph.h"                    /*include graphics package*/

int	x, y      ;      /* pixel coordinates */
int	triangle  ;      /* select random traiangle*/
int   i, j, k   ;      /* loop counters*/
int	MaxY      ;      /* maximum X and Y coordinates*/

void main (void)
{
	startgraph();
	MaxY = getmaxy();

	randomize();        /*initialize random number generator*/

	x = random(MaxY);  /*select random starting point*/
	y = random(MaxY);  /*use MaxX=MaxY */

	for (i = 1; i <= 20000; i++)
		 if (i > 1000)            /* skip first few points */
		 {
		  triangle = random(3)+1;  /* select random number between 1 and 3*/
			switch (triangle)          /* select which triangle to measure from */
			{
				case 1:  {
						 x = x / 2;            /* find 1/2 way point to  A*/
						 y = (MaxY + y) / 2;
				 };break;
				case 2:  {
						x = (MaxY / 2 + x) / 2; /* find 1/2 way point to B */
						y = y / 2;
				 };break;
				case 3:  {
						x = (MaxY + x) / 2;       /* find 1/2 way point to C*/
						y = (MaxY + y) / 2;
				 };break;
			}
				putpixel(x,y,WHITE);                 /* output pixel */
	 }  /* i loop*/
	getch();
	closegraph();
}



