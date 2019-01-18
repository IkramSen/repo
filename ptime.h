#ifndef TIME_H
#define TIME_H

#include <time.h>


typedef struct timespec tspec;

tspec ptask_gettime();

void ptask_wait_for_next_period();

double tspec_soustr(const tspec *a, const tspec *b); // a is  timestart  an b is timeend

void sleep_until(struct timespec *ts, int delay);

#endif
