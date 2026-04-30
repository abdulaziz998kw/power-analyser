#include <stdio.h>

#include "io.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    int n=0;
    WaveformSample *data = load_csv(argv[1], &n);
    printf("data read number : %d\n",n);
    return 0;
}
