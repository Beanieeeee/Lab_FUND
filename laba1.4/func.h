#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>  

float e_sum(float eps);
float e_pred(float eps);
float e_yr(float eps);

float pi_sum(float eps);
float pi_pred(float eps);
float pi_yr(float eps);

float ln_sum(float eps);
float ln_pred(float eps);
float ln_yr(float eps);

float sq_sum(float eps);
float sq_pred(float eps);
float sq_yr(float eps);

float y_sum(float eps);
float y_pred(float eps);
float y_yr(float eps);