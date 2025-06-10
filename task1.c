#include <stdio.h>

int main() {
    double approx = 0;
    long long n = 100000000;

    for (long long i = 0; i <= n; i++) {
        double numerator = 1;
        if (i%2 == 1) {
            numerator *= -1;
        }
        double denominator = 2*i + 1;

        double term = numerator / denominator;
        approx += term;
    }
    approx *= 4;
    printf("%.10lf\n", approx);
}