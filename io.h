#ifndef POWER_ANALYSER_IO_H
#define POWER_ANALYSER_IO_H
#include "waveform.h"

WaveformSample* load_csv(const char *filename, int *count);

#endif //POWER_ANALYSER_IO_H
