#ifndef POWER_ANALYSER_WAVEFORM_H
#define POWER_ANALYSER_WAVEFORM_H

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformSample;

double compute_rms(double *values, int n);
double compute_peak_to_peak(double *values, int n);
int count_clipping(double *values, int n, double limit);
int check_compliance(double rms);
double compute_dc_offset(double *values, int n);
unsigned char get_status(int clipping, int compliant);
double compute_mean(double *values, int n);
double compute_std_dev(double *values, int n);
#endif //POWER_ANALYSER_WAVEFORM_H
