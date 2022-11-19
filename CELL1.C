/* Simulate One-dimensional cellular automata
  1/29/93   Phil Laplante
  1/15/94	Scott Farbman
*/

#include <conio.h>                    /* header for Console I/O  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int columns = 80;          /* number of columns on screen */
#define rows 	  24;          /* number of rows on screen */
#define FALSE 	  0;
#define TRUE	  1;

int  cells[80];       /* playing field for experiment */
char initcell[80];     /* input cell configuration */
/* ------------------------------------------------------------- */

void init(void)
/* initializes the cell configuration space (the "playing field") */
{
	int  j ;
	  for (j = 0; j < columns; j++)
	  {
		  cells[j] = 0;   /* initialize cell space */
	  }
};

/* ------------------------------------------------------------- */
void display(void)
/* displays line of cells to screen */
{
int	j;

		 for (j = 0; j < columns; j++)
		 {
				  if (cells[j] == 1)
				  putchar('*')  ;          /* cell in space */

				  else
						putchar(' ')	;          /* no cell in space */
		}
};

/*----------------------------------------------------------------*/

void load(void)
/* load initial cell file into array of cells */
{
	int j ;

	clrscr();                                 /* clear screen         */
	printf("Input initial cell configuration \n");
	scanf("%[* ]",&initcell);
	init();                                  /* initialize cell space */
	for (j = 0; j <= strlen(initcell); j++)
			if (initcell[j] == '*')
					cells[j] = 1;              /* live cell in space */

};

/*-----------------------------------------------------------------*/

void rule(void)
/* apply one dimensional cellular automata rule for one iteration.
  note that the first and last cells in a row are omitted
*/
{
int	oldcells[80];             /* holds copy of old cell field */
int 			i,j;
int   am1,a0,a1;              /* left, current and right cells */


		for (j = 0; j< columns; j++)
		  oldcells[j] = cells[j];     /* remember old cell configuration */

	  init();                           /* initialize next configuraion  */

	  for (j = 1; j < columns-1; j++)       /* omit boundary cells */
			{
				am1 = oldcells[j-1];
				a0  = oldcells[j];
				a1  = oldcells[j+1];
				cells[j] = (am1 && !a0 && !a1) || (! am1 && a1) || (a0 && a1);
			}
};

/* ------------------------  begin program ------------------------- */

void main(void)
{

	int i;
	int iter;       /* number of iterations for simulation*/


	load();
	display();
	printf("Enter number of iterations for simulation ");
	scanf("%d",&iter);
	printf("Press Enter to begin Simulation ");
	getch();
	clrscr();                  /* clear screen */
	display();                 /* display starting configuration*/
	  for (i = 0; i < iter; i++)
	  {
		  rule();                 /* apply rule to cell field */
		  display();               /* display updated universe */
	  }
	  getch();
}

