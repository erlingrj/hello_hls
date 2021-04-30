#ifndef _MATRIX_MULTIPLY_H_
#define _MATRIX_MULTIPLY_H_

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>

typedef int data_t;

#define N 8

void matrix_multiply(data_t a[N*N], data_t b[N*N], data_t out[N*N]);

#endif
