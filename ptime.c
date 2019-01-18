#include "psomme.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define BILLION 1E9

typedef struct timespec tspec;

/* I used CLOCK_MONOTONIC because i don't actually care what time it is, I just want the clock to be consistent */
tspec ptask_gettime() {

  tspec b;
  clock_gettime(CLOCK_MONOTONIC, &b);
  return b;
}


inline double tspec_soustr(const tspec *ts, const tspec *te) {
double tu;

printf("The beginning of execution in function is: (%lld)s et (%.9ld)ns\n", (long long) ts->tv_sec, ts->tv_nsec);
tu = (te->tv_sec - ts->tv_sec) + (te->tv_nsec - ts->tv_nsec) / BILLION;

printf("The execution time in function is: %f\n",tu);
return tu;
}


void sleep_until(struct timespec *ts, int delay)
{

	ts->tv_sec += delay;
	if(ts->tv_sec >= 100*100*100){
		ts->tv_sec -= 100*100*100;
		ts->tv_sec++;
	}
	clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, ts,  NULL);
}

