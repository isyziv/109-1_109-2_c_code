#include <stdio.h>
#include <math.h>
#include "rational.h"

// GCD: greatest common divisor
int gcd(int m, int n) {
  m = abs(m);
  n = abs(n);
  if (m % n == 0) return n;
  else return gcd(n, m % n);
}

// Simplify rational number
void simplify(rational *r) {
  int g;

  if (r->deno==0) {r->nume = 0; r->deno = 1;}
  else if (r->deno<0) {r->nume = -r->nume; r->deno = -r->deno;}
  g = gcd(r->nume, r->deno);
  r->nume = r->nume / g;
  r->deno = r->deno / g;  
}

// Rational number addition (Τ瞶计猭)
rational plus(rational x , rational y) {
  rational sum;
  int g;
  
  sum.nume = x.nume * y.deno + y.nume * x.deno;
  sum.deno = x.deno * y.deno;
  simplify(&sum);
  return sum;
}

// Rational number subtraction (Τ瞶计搭猭)
rational minus(rational x , rational y) {
  rational diff;
  int g;
  
  diff.nume = x.nume * y.deno - y.nume * x.deno;
  diff.deno = x.deno * y.deno;
  simplify(&diff);
  return diff;
}

// Rational number multiplication (Τ瞶计猭)
rational time(rational x, rational y) {
  rational prod;
  int g;
  
  prod.nume = x.nume * y.nume ;
  prod.deno = x.deno * y.deno;
  simplify(&prod);
  return prod;
}

// Rational number division (Τ瞶计埃猭)
rational divide(rational x, rational y) {
  rational quot;
  int g;
  
  if (y.nume!=0) { 
    quot.nume = x.nume * y.deno ;
    quot.deno = x.deno * y.nume; }
  else {
    quot.nume = 0;
    quot.deno = 1; } 
  simplify(&quot);
  return quot;
}

// Convert a pair of integers to a rational number (盢癸俱计锣传ΘΤ瞶计)
rational ii2r(int n, int d) {
  rational r;
  
  r.nume = n;
  r.deno = d;
  simplify(&r);
  return r;
}

// Convert an integer to a rational number (盢俱计锣传ΘΤ瞶计)
rational i2r(int n) {
  rational r;
  
  r.nume = n;
  r.deno = 1;
  return r;
}

// Print a rational number (Τ瞶计)
void printr(rational r) {

  printf("%d/%d", r.nume, r.deno);
}
