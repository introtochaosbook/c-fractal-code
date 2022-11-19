/*
	 compute and display forest of trees
	 using Michael Barnsley's IFS algorithm

  12-5-93  Frank D'Erasmo
  2-12-94  Scott Farbman

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include "graph.h"                    /*include graphics package*/

float		x, y;       	/* pixel coordinates */
long  	i, j;      		/* loop counters*/
int		q;      			/* random number */
int  		k;      			/* row selector */
int  		MaxX;      		/* Maximum X screen coordinate*/
int   	MaxY;   		   /* Maximum Y screen coordinate*/
float   	d[8][6]; 			/* holds data of IFS attractor */
float   	scale;         /* random scale factor*/
int		xpos,ypos;    /* tree position */
int		crand;      	/* pick random color (green, blue, yellow) */
int		color;      	/* random color value */


void trees(void)
{
/* initialize IFS data array */

  d[0][0]=0;    d[0][1]=0;     d[0][2]=0;
			d[0][3]=0.5;  d[0][4]=0; d[0][5]=0;

  d[1][0]=0.42; d[1][1]=-0.42; d[1][2]=0.42;
			d[1][3]=0.42; d[1][4]=0; d[1][5]=0.2;

  d[2][0]=0.42; d[2][1]=0.42;  d[2][2]=-0.42;
			d[2][3]=0.42; d[2][4]=0; d[2][5]=0.2;

  d[3][0]=0.1;  d[3][1]=0;     d[3][2]=0;
			d[3][3]=0.1;  d[3][4]=0; d[3][5]=0.2;

  randomize();           /*initialize random number generator*/

  x = 0;              /*set starting coordinates*/
  y = 0;

	for (j = 1;j <= 200;j++)                   /* make 200 trees */
	 {
		xpos = random(MaxX);                    /* pick tree position */
		ypos = random(MaxX);
		scale = random(3) + 1;                  /* pick tree scale */
		crand = random(10) + 1;                 /* pick tree color */
		switch (crand)
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				  color = GREEN;break;            /* most trees are green */
			case 9  : color = YELLOW;break;      /* some trees are yellow */
			case 10 : color = RED;break;         /* some trees die */
		} /*case*/

		for (i = 1; i <= 800; i++)             /* 800 pixels per tree */
		{
			q = random(100) + 1;          /* pick random number from 1-100*/
			if (q <= 40)                /* assign column according to */
				k = 1;                     /* probability */
			if ((q> 40) && (q < 81))
				k = 2;
			if ((q >= 81) && (q < 95))
				k = 3;
			if (q >= 95 )
			  k = 0;

		  x = d[k][0]*x + d[k][1]*y + d[k][4];   /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];
		  if (ypos -y*MaxY/scale > MaxY-50)  /*clears area on screen*/
			  putpixel(xpos + x*MaxX/scale,ypos - y*MaxX/scale,color);
		 };
	 };
};

void redwds(void)     /*generates redwood trees*/
{
/* initialize IFS data array */

	d[0][0]=0.33; d[0][1]=0; d[0][2]=0;
	 d[0][3]=0.33; d[0][4]=1;  d[0][5]=0;

	d[1][0]=0.33; d[1][1]=0; d[1][2]=0;
	 d[1][3]=0.33; d[1][4]=MaxX; d[1][5]=0;

	d[2][0]=0.33; d[2][1]=0; d[2][2]=0;
	 d[2][3]=0.33; d[2][4]=1;  d[2][5]=MaxX;

	d[3][0]=0.33; d[3][1]=0; d[3][2]=0;
	 d[3][3]=0.33; d[3][4]=MaxX; d[3][5]=MaxX;

	d[4][0]=0.33; d[4][1]=0; d[4][2]=2;
	 d[4][3]=0.33; d[4][4]=MaxX / 2; d[4][5]=1;

	d[5][0]=0.33; d[5][1]=0; d[5][2]=2;
	 d[5][3]=0.33; d[5][4]=MaxX; d[5][5]=MaxX / 2;

	d[6][0]=0.33; d[6][1]=0; d[6][2]=2;
	 d[6][3]=0.33; d[6][4]=1;  d[6][5]=MaxX / 2;

	d[7][0]=0.33; d[7][1]=0; d[7][2]=2;
	 d[7][3]=0.33; d[7][4]=MaxX / 2; d[7][5]=MaxX;

	randomize();           /*initialize random number generator*/

	x = 0;              /*set starting coordinates*/
	y = 0;

	for (i = 1; i <= 300000; i++)                   /*300,000 pixels*/
	  {
		  k = random(8);                  /* pick random column */
		  x = d[k][0]*x + d[k][1]*y + d[k][4];   /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];
		  putpixel(2*x/3,2*y/3,RED);
		  putpixel(2*(x+1)/3,2*(y+1)/2,RED);
	  }
}

void clouds(void)     /*generates mist/clouds*/
{

/* initialize IFS data array */

	d[0][0]=0.33; d[0][1]=1; d[0][2]=0;
	 d[0][3]=0.33; d[0][4]=0;  d[0][5]=0;

	d[1][0]=0.33; d[1][1]=1; d[1][2]=0;
	 d[1][3]=0.33; d[1][4]=MaxY; d[1][5]=0;

	d[2][0]=0.33; d[2][1]=1; d[2][2]=0;
	 d[2][3]=0.33; d[2][4]=1;  d[2][5]=MaxY;

	d[3][0]=0.33; d[3][1]=1; d[3][2]=0;
	 d[3][3]=0.33; d[3][4]=MaxY; d[3][5]=MaxY;

	d[4][0]=0.33; d[4][1]=0; d[4][2]=0;
	 d[4][3]=0.33; d[4][4]=MaxY / 2; d[4][5]=1;

	d[5][0]=0.33; d[5][1]=0; d[5][2]=0;
	 d[5][3]=0.33; d[5][4]=MaxY; d[5][5]=MaxY / 2;

	d[6][0]=0.33; d[6][1]=0; d[6][2]=0;
	 d[6][3]=0.33; d[6][4]=1;  d[6][5]=MaxY / 2;

	d[7][0]=0.33; d[7][1]=0; d[7][2]=0;
	 d[7][3]=0.33; d[7][4]=MaxY / 2; d[7][5]=MaxY;

	randomize();           /*initialize random number generator*/

	x = 1;              /*set starting coordinates*/
	y = 50;

	for (i = 1; i <= 30000; i++)                    /* 30,000 pixels */
	  {
		  k = random(8);                  /* pick random column */
		  x = d[k][0]*x + d[k][1]*y + d[k][4];   /* transform coordinates */
		  y = d[k][2]*x + d[k][3]*y + d[k][5];
		  if (y < 200)
			  putpixel(2*x/3,2*y/3,LIGHTGRAY);
	  }
}

void main (void)
{
	startgraph();
	MaxY=getmaxy();
	MaxX=getmaxx();
	trees();
	redwds();
	clouds();
	getch();
	closegraph();
}