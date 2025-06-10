#include <stdio.h>
#include <omp.h>
#include <immintrin.h>

int main() {
    long long n = 100000000;
    __m256d ones = _mm256_set_pd(1, 1, 1, 1);
    __m256d twos = _mm256_set_pd(2, 2, 2, 2);
    __m256d numerator = _mm256_set_pd(1, -1, 1, -1);
    __m256d thread_sums, critical_sums;

    #pragma omp parallel private(thread_sums) shared(critical_sums)
    {
        thread_sums = _mm256_set_pd(0, 0, 0, 0);
        critical_sums = _mm256_set_pd(0, 0, 0, 0);

        #pragma omp for
        for (long long i = 0; i <= n; i += 4) {
            __m256d idx = _mm256_set_pd(i, i+1, i+2, i+3);
            __m256d mul = _mm256_mul_pd(idx, twos);
            __m256d denominator = _mm256_add_pd(mul, ones);
            __m256d term = _mm256_div_pd(numerator, denominator);
            thread_sums = _mm256_add_pd(thread_sums, term);
        }

        #pragma omp critical
        {
            critical_sums = _mm256_add_pd(critical_sums, thread_sums);
        }
    }

    double approx = critical_sums[0] + critical_sums[1] + critical_sums[2] + critical_sums[3];
    approx *= 4;
    printf("%.10f\n", approx);
}