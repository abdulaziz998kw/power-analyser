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