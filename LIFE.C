/*	Simulate Conway's Game of Life
	01/29/93	Phil Laplante
	01/21/94 Scott Farbman
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>

#define cell '*'
#define TRUE 1
#define FALSE 0

typedef int cell_field[24][80]; /* Playing field */

int columns = 79;						/* number of columns on screen */
int rows = 23;							/* number of rows on screen */
FILE *stream;							/* file containing initial universe */
cell_field cells;						/* playing field for experiment */
cell_field oldcells;					/* holds copy of old cell field */
char filename[80];						/* name of initial universe */
char cellrow[80];                /* row of cells */

void init(void);
void display(void);
void load(void);
int count(int i,int j);
void rule(void);


void main(void)
{
	int i;
	int iter;			/* number of iterations for simulation */

	load();
	printf("File Loaded");
	display();
	printf("Enter number of iterations for sumulation ");
	scanf("%d",&iter);
	printf("\nPress Enter to Begin Simulation ");
	getch();

	for (i=1;i<=iter;i++)
	{
		rule();
		display();
	}
	getch();
};



void init(void)
/* initializes the cell configuration space ( the "playing field" ) */
{
	int i,j;

	for (i=0;i<=rows;i++)
		for (j=0;j<=columns;j++)
			cells[i][j] = FALSE;
	return;
};

void display(void)
/* displays array of cells to screen */
{
	int i,j;

	clrscr();
	for (i=0;i<=rows;i++)
		for (j=0;j<=columns;j++)
		{
			if (cells[i][j] == TRUE)
				putch(cell);
			else
				putch(' ');
		};
};

void load(void)
/* load initial cell file into array of cells */
{
	int i,j;
	char ch;

	printf("Input life file name ");
	scanf("%s",&filename);

	/* open the file read only */
	stream = fopen(filename, "r");
	/* initialize cell space */
	init();

	i = 0;
	j = 0;

	while (i<=rows)
	{
		ch = fgetc(stream);
		while (ch != '\n')
		{
			if (ch == cell)
				cells[i][j] = TRUE;			/* live cell in space */
			j++;
			ch = fgetc(stream);
		}
		i++;
		j = 0;
	}
	fclose(stream);
}

int count(int i, int j)
/* count number of cells in neighborhood */
{
	int l,m;				/* loop counters */
	int sum;				/* running sum */
	int srow,erow;		/* starting and ending row locations */
	int scol,ecol;		/* starting and ending column locatons */

	sum = 0;				/* initialize running sums */

	if (i ==0)			/* find starting row */
		srow = 0;
	else
		srow = i -1;

	if (i == rows)		/* find ending row */
		erow = rows;
	else
		erow = i + 1;

	if (j == 0 )		/* find starting column */
		scol = 0;
	else
		scol = j -1;

	if (j == columns)	/* find ending columns */
		ecol = columns;
	else
		ecol = j+1;

	for (l=srow; l<=erow; l++)       /* count nearby cells */
		for (m=scol; m<=ecol; m++)
			if ((i!=l) || (j!=m))			/*  don't count self */
				if (oldcells[l][m] == TRUE)
					sum++;
	return sum;
};

void rule(void)
/* apply Game of Life rule
	note that the first and last cells in a row are treated specially */
{
	int i,j;		/* local counters */

	for (i=0;i<=rows;i++)
		for (j=0;j<=columns;j++)
			oldcells[i][j] = cells[i][j];

	init();

	for (i=0;i<=rows;i++)
		for (j=0;j<=columns;j++)
		switch (count(i,j))
		{
			case 0 :
			case 1 : cells[i][j] = FALSE; break;
			case 2 : cells[i][j] = oldcells[i][j]; break;
			case 3 : cells[i][j] = TRUE; break;
			case 4 :
			case 5 :
			case 6 :
			case 7 :
			case 8 : cells[i][j] = FALSE; break;  /* overcrowding */
		}
}











