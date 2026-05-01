#include "waveform.h"
#include <math.h>

double compute_rms(double *values, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += values[i] * values[i];
    }
    return sqrt(sum / n);
}

double compute_peak_to_peak(double *values, int n) {
    double min = values[0], max = values[0];

    for (int i = 1; i < n; i++) {
        if (values[i] < min) min = values[i];
        if (values[i] > max) max = values[i];
    }

    return max - min;
}
int count_clipping(double *values, int n, double limit) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(values[i]) >= limit) {
            count++;
        }
    }
    return count;
}
int check_compliance(double rms) {
    return (rms >= 207 && rms <= 253);
}
double compute_dc_offset(double *values, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += values[i];
    }
    return sum / n;
}
unsigned char get_status(int clipping, int compliant) {
    unsigned char status = 0;

    if (clipping > 0)
        status |= 1 << 0; // bit 0 = clipping

    if (!compliant)
        status |= 1 << 1; // bit 1 = out of tolerance

    return status;
}

double compute_mean(double *values, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += values[i];
    }
    return sum / n;
}

/* Merit feature */
double compute_std_dev(double *values, int n) {
    double mean = compute_mean(values, n);
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += pow(values[i] - mean, 2);
    }

    return sqrt(sum / (n - 1));  // sample standard deviation
}