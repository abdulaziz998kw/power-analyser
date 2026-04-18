#include "io.h"
#include <stdio.h>
#include <stdlib.h>
WaveformSample* load_csv(const char *filename, int *count) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "Error: Cannot open file\n");
        return NULL;
    }

    char line[256];
    fgets(line, sizeof(line), file); // skip header

    int capacity = 1000;
    WaveformSample *data = malloc(capacity * sizeof(WaveformSample));

    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
               &data[i].timestamp,
               &data[i].phase_A_voltage,
               &data[i].phase_B_voltage,
               &data[i].phase_C_voltage,
               &data[i].line_current,
               &data[i].frequency,
               &data[i].power_factor,
               &data[i].thd_percent);
        i++;
    }

    fclose(file);
    *count = i;
    return data;
}