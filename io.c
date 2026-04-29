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

void write_results(const char *filename,
                   double rmsA, double rmsB, double rmsC,
                   double p2pA, double p2pB, double p2pC,
                   double dcA, double dcB, double dcC,
                   int clipA, int clipB, int clipC,
                   double freq, double pf, double thd,
                   double stdA, double stdB, double stdC,
                   unsigned char statusA,
                   unsigned char statusB,
                   unsigned char statusC) {

    FILE *file = fopen(filename, "w");

    if (!file) {
        printf("Error writing results file\n");
        return;
    }

    fprintf(file, "=== Power Quality Analysis ===\n\n");

    fprintf(file, "RMS Voltage:\n");
    fprintf(file, "A: %.2f (%s)\n", rmsA, check_compliance(rmsA) ? "OK" : "OUT");
    fprintf(file, "B: %.2f (%s)\n", rmsB, check_compliance(rmsB) ? "OK" : "OUT");
    fprintf(file, "C: %.2f (%s)\n\n", rmsC, check_compliance(rmsC) ? "OK" : "OUT");

    fprintf(file, "Peak-to-Peak:\nA: %.2f\nB: %.2f\nC: %.2f\n\n",
            p2pA, p2pB, p2pC);

    fprintf(file, "DC Offset:\nA: %.5f\nB: %.5f\nC: %.5f\n\n",
            dcA, dcB, dcC);

    fprintf(file, "Clipping Count:\nA: %d\nB: %d\nC: %d\n\n",
            clipA, clipB, clipC);

    fprintf(file, "Average Frequency: %.3f Hz\n", freq);
    fprintf(file, "Average Power Factor: %.3f\n", pf);
    fprintf(file, "Average THD: %.3f %%\n\n", thd);

    fprintf(file, "Standard Deviation:\nA: %.2f\nB: %.2f\nC: %.2f\n\n",
            stdA, stdB, stdC);

    fprintf(file, "Status Flags (bitmask):\nA: %u\nB: %u\nC: %u\n",
            statusA, statusB, statusC);

    fclose(file);
}