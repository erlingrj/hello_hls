#include "matrix_multiply.h"
using namespace std;

void matrix_multiply(data_t a[N*N], data_t b[N*N], data_t out[N*N]) {
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            data_t acc = 0;
            for (int k = 0; k<N; k++) {
                acc += a[i*N + k] * b[k*N + j];
            }
            out[i*N + j] = acc;
        }
    }
}
