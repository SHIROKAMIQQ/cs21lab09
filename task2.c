#include <stdio.h>
#include <immintrin.h>

int main(){
    __m256d ones = _mm256_set_pd(1, 1, 1, 1);
    __m256d twos = _mm256_set_pd(2, 2, 2, 2);
    __m256d numerator = _mm256_set_pd(1, -1, 1, -1);
    __m256d partial_sums = _mm256_set_pd(0, 0, 0, 0);

    for (int i = 0; i <= 100000000; i += 4) {
        __m256d idx = _mm256_set_pd(i, i+1, i+2, i+3);
        __m256d mul = _mm256_mul_pd(idx, twos);
        __m256d denominator = _mm256_add_pd(mul, ones);
        __m256d term = _mm256_div_pd(numerator, denominator);
        partial_sums = _mm256_add_pd(partial_sums, term);
    }

    double approx = partial_sums[0] + partial_sums[1] + partial_sums[2] + partial_sums[3];
    approx *= 4
    printf("%.10lf\n", approx);
}
