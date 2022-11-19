/* cplex.h

Originally coded in Pascal as Complex.pas.
Cannot be named Complex.h because there exists a Complex.h for use in C++.
Converted to Cplex.h for use as a header file in C.
01-15-94	Scott Farbman


*/

#include <math.h>

void add (float x1, float y1, float x2, float y2, float *x3, float *y3  )
/*calculates z3 = z1 + z2 where:
  z1 = x1 + iy1;
  z2 = x2 + iy2;
  z3 = x3 + iy3;
*/
{
  *x3 = x1+x2;
  *y3 = y1+y2;
};

void sub (float x1, float y1, float x2, float y2, float *x3, float *y3  )
/* calculates z3 = z1 - z2 where:
  z1 = x1 + iy1
  z2 = x2 + iy2
  z3 = x3 + iy3
*/
{
  *x3 = x1-x2;
  *y3 = y1-y2;
};


void mult (float x1, float y1, float x2, float y2, float *x3, float *y3  )
/* calculates z3 = z1 * z2 where:
  z1 = x1 + iy1
  z2 = x2 + iy2
  z3 = x3 + iy3
*/
{
  *x3 = x1*x2-y1*y2;
  *y3 = y1*x2 + x1*y2;
};

void cdiv (float x1, float y1, float x2, float y2, float *x3, float *y3  )
/* calculates z3 = z1 / z2 where:
  z1 = x1 + iy1
  z2 = x2 + iy2
  z3 = x3 + iy3
*/
{
  float  denom;                    /* denominator */

  denom = x2*x2 + y2*y2;
  *x3 = (x1*x2 + y1*y2)/ denom;   /* real part */
  *y3 = (x2*y1 - x1*y2)/ denom;    /* imaginary part */
};


double cosh(double x)     /* calculates cosh(x) */
{
	 return (exp(x) + exp(-x))/2.0;
};

double sinh(double x )     /* calculates sinh(x) */
{
	 return (exp(x) - exp(-x))/2.0;
};

void ccos(float x, float y ,float *x1, float *y1)
/* calculates z = cos(x + iy) where:
  x1 is real part of z
  y1 is imaginary part of z */
{
	 *x1 = cos(x)*cosh(y);
	 *y1 = -sin(x)*sinh(y);
};

void csin(float x, float y ,float *x1, float *y1)
/* calculates z = sin(x + iy) where:
  x1 is real part of z
  y1 is imaginary part of z */
	{
	 *x1 = sin(x)*cosh(y);
	 *y1 = cos(x)*sinh(y);
};

void cexp(float x, float y ,float *x1, float *y1)
/* calculates z = e^(x + iy) where
  x1 is real part of z
  y1 is imaginary part of z
*/
{
  *x1 = exp(x)*cos(y);
  *y1 = exp(x)*sin(y);
};
  /*cplex*/

