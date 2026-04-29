#ifndef POWER_ANALYSER_IO_H
#define POWER_ANALYSER_IO_H
#include "waveform.h"

WaveformSample* load_csv(const char *filename, int *count);
void write_results(const char *filename,
                   double rmsA, double rmsB, double rmsC,
                   double p2pA, double p2pB, double p2pC,
                   double dcA, double dcB, double dcC,
                   int clipA, int clipB, int clipC,
                   double freq, double pf, double thd,
                   double stdA, double stdB, double stdC,
                   unsigned char statusA,
                   unsigned char statusB,
                   unsigned char statusC);
#endif //POWER_ANALYSER_IO_H
