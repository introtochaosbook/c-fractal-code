/* finds the nth fibonacci number
  11-24-92  Phil Laplante          */


#include <stdio.h>
#include <conio.h>

int fibo(int i)
/* a recursive function */
{
	if (i == 0)
	  return 0;
	else if (i == 1)
	  return 1;
	else return (fibo(i-1) + fibo(i-2));

};


int  n;           /* nth number in sequence */

void main (void)
{
  printf("Enter n > 0 and less than 24 --> ");
  scanf("%d",&n);
  printf("\nf(%d)=%d",n,fibo(n));
  getch();
}
