#include <unistd.h>
#include <iostream>
#include "mic.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>

int is_running = 0;
uint16_t buffer [128];
upm::Microphone *sensor = NULL;

void
sig_handler(int signo)
{
    printf("got signal\n");
    if (signo == SIGINT) {
        is_running = 1;
    }
}

//! [Interesting]
int
main(int argc, char **argv)
{
    // Attach microphone to analog port A0
    sensor = new upm::Microphone(0);
    signal(SIGINT, sig_handler);

    thresholdContext ctx;
    ctx.averageReading = 0;
    ctx.runningAverage = 0;
    ctx.averagedOver   = 2;

    // Infinite loop, ends when script is cancelled
    // Repeatedly, take a sample every 2 microseconds;
    // find the average of 128 samples; and
    // print a running graph of the averages
    while (!is_running) {
        int len = sensor->getSampledWindow (2, 128, buffer);
        if (len) {
            int thresh = sensor->findThreshold (&ctx, 30, buffer, len);
            sensor->printGraph(&ctx);
            if (thresh) {
                // do something ....
            }
        }
    }

    std::cout << "exiting application" << std::endl;

    delete sensor;

    return 0;
}
//! [Interesting]