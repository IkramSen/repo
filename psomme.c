#include "psomme.h"
#include "ptime.h"
//#include "ptask.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


#define TIMER_D 1000000 // 1000000: 1ms deadine => will be replaced by 0 for exemple to testing the deadline
#define BILLION 1E9

void* sum(void *args)
{
      struct timespec timeStart, timeEnd;

    int i;
    int n=100;
    int s=0;// sum
    int p=1;
    unsigned int delay = 100;

        printf("We are in the thread.\n");

    while(1){

        /* start date */
        timeStart = ptask_gettime();

        /* treatment  */
        for (i=1; i<n; i++){
        s=s+i;
        p=s/i; p=s/i;// I added it just to increase execution time
        }
        /* End of treatment  */
        timeEnd = ptask_gettime();

        double RespTime = tspec_soustr(&timeStart, &timeEnd);

        double Realdeadline= timeStart.tv_nsec + TIMER_D;
        printf( "realDeadline!!!!%f\n",Realdeadline);

        if( RespTime >Realdeadline) {
            printf( "The execution time has exceeded the deadline!!!!");
            pthread_exit(NULL);
        }
        else{
            printf("The sum is : %d\n",s);
            printf("The beginning of execution: (%lld)s et (%.9ld)ns\n", (long long)timeStart.tv_sec, timeStart.tv_nsec);
            printf("The end of execution: (%lld)s et (%.9ld)ns\n", (long long)timeEnd.tv_sec, timeEnd.tv_nsec);
            printf("The execution time: %f\n",RespTime);
        }

        //wait for the next period
	printf("wait for the next period plz\n");
        sleep_until(&timeEnd, delay);
        }

}
