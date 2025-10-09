#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>  

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);

double trapezoid(double (*func)(double), double a, double b, double eps);
