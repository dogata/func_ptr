#include <stdio.h>
#include <math.h>
// passing function pointers

double aFunc(double a, double b);
double bFunc(double a, double b);
double cFunc(double (*fptr)(double,double), double a, double b);

void main(int argc, char *argv){

  double a = 2.0,b = 5.0;
  double c;

  c = cFunc(&aFunc,a,b);
  printf("c = %4.2f\n",c);

  c = cFunc(&bFunc,a,b);
  printf("c = %4.2f\n",c);
}

// a sample function
double aFunc(double a, double b){
  double c;
  c = a * b;
  return c;
}

// a different sample function
double bFunc(double a, double b){
  double c;
  c = a / b;
  return c;
}

// accepts a function pointer
double cFunc(double (*fptr)(double,double), double a, double b){
  printf("cFunc called!\n");
  return (*fptr)(a,b);
}
