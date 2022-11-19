/* Produce Cantor set using recursion
  12-20-92   Phil Laplante
  01-15-94   Scott Farbman
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "graph.h"

int MaxX;           /*Maximum X coordinate */

void Cantor(int x1, int y1, int x2, int y2 );

void main(void)
{
   startgraph();

	MaxX =  getmaxy();

	Cantor(0,8,MaxX,8);          /* start Cantor set at row 8 */
	getch();
	closegraph();
}


void Cantor(int x1, int y1, int x2, int y2 )
/* Applies middle third algorithm to segment of real line */
{
	 int  delta ;                 /*one third of line segment */

	 line(x1, y1, x2, y2);
	 y1 = y1 + 16;                  /*increment y coordinate*/
	 if (y1 <=128)                 /*don't do to far */
	 {
		delta = (x2-x1) / 3;       /*calculate quarter of line segment */
		Cantor(x1, y1, x1+delta, y1); /*draw first third*/
		Cantor(x2-delta, y1, x2, y1); /*draw third third*/
	 };
}




