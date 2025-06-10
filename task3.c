#include <stdio.h>
#include <omp.h>

int main() {
    double partial_sum, total_sum;
    double n = 100000000;

    #pragma omp parallel private(partial_sum) shared(total_sum) {
        partial_sum = 0;
        total_sum = 0;

        #pragma omp for
        for (int i = 0; i <= n; i++) {
            double numerator = 1;
            if (i%2 == 1) {
                numerator *= -1;
            }
            double denominator = 2*i + 1;
            double term = numerator / denominator;
        }

        #pragma omp critical {
            total_sum += partial_sum;
        }
    }

    double approx = 4 * total_sum;
    printf("%.10f\n", approx);
}