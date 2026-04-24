#include <stdio.h>

#include "io.h"

int main(void) {

    int n=0;
    WaveformSample *data=load_csv("power_quality_log.csv",&n);
    printf("data read number : %d\n",n);
    return 0;
}
