#include <stdio.h>
#include <stdlib.h>

#include "io.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    int n=0;
    WaveformSample *data = load_csv(argv[1], &n);
if (!data || n == 0) {
        fprintf(stderr, "Error loading data\n");
        return 1;
    }

    double *A = malloc(n * sizeof(double));
    double *B = malloc(n * sizeof(double));
    double *C = malloc(n * sizeof(double));
    double *freq = malloc(n * sizeof(double));
    double *pf = malloc(n * sizeof(double));
    double *thd = malloc(n * sizeof(double));

    if (!A || !B || !C || !freq || !pf || !thd) {
        fprintf(stderr, "Memory allocation failed\n");
        free(data);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        A[i] = data[i].phase_A_voltage;
        B[i] = data[i].phase_B_voltage;
        C[i] = data[i].phase_C_voltage;
        freq[i] = data[i].frequency;
        pf[i] = data[i].power_factor;
        thd[i] = data[i].thd_percent;
    }

    double rmsA = compute_rms(A, n);
    double rmsB = compute_rms(B, n);
    double rmsC = compute_rms(C, n);

    double p2pA = compute_peak_to_peak(A, n);
    double p2pB = compute_peak_to_peak(B, n);
    double p2pC = compute_peak_to_peak(C, n);

    double dcA = compute_dc_offset(A, n);
    double dcB = compute_dc_offset(B, n);
    double dcC = compute_dc_offset(C, n);

    int clipA = count_clipping(A, n, 324.9);
    int clipB = count_clipping(B, n, 324.9);
    int clipC = count_clipping(C, n, 324.9);

    double avgFreq = compute_mean(freq, n);
    double avgPF = compute_mean(pf, n);
    double avgTHD = compute_mean(thd, n);

    double stdA = compute_std_dev(A, n);
    double stdB = compute_std_dev(B, n);
    double stdC = compute_std_dev(C, n);

    unsigned char statusA = get_status(clipA, check_compliance(rmsA));
    unsigned char statusB = get_status(clipB, check_compliance(rmsB));
    unsigned char statusC = get_status(clipC, check_compliance(rmsC));

    write_results("results.txt",
                  rmsA, rmsB, rmsC,
                  p2pA, p2pB, p2pC,
                  dcA, dcB, dcC,
                  clipA, clipB, clipC,
                  avgFreq, avgPF, avgTHD,
                  stdA, stdB, stdC,
                  statusA, statusB, statusC);

    printf("Analysis complete. Results saved to results.txt\n");

    free(A); free(B); free(C);
    free(freq); free(pf); free(thd);
    free(data);


    return 0;
}
