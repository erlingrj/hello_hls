#include "matrix_multiply.h"

#include <iostream>

using namespace std;

void golden_matrix_multiply(data_t a[N*N], data_t b[N*N], data_t out[N*N]) {
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

bool expect_equal(data_t a[N*N], data_t b[N*N]) {
    for (int i = 0; i<N*N; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}


int main(void) {

    data_t test_a[N*N];
    data_t test_b[N*N];

    for (int i = 0; i<N*N; i++) {
        test_a[i] = i;
        test_b[i] = 100+i;
    }

    data_t golden_res[N*N];
    data_t dut_res[N*N];

    golden_matrix_multiply(test_a, test_b, golden_res);
    matrix_multiply(test_a, test_b, dut_res);

    cout << "Look mom, HLS!" <<endl;
    if (expect_equal(golden_res, dut_res)) {
        cout << "They are equal !!" <<endl;
        return 0;
    } else {
        cout << "ERROR: Not getting the same result!" <<endl;
        return -1;
    }

}