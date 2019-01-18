#include <stdlib.h>
#include <stdio.h>
#include "psomme.h"
#include <pthread.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void)
{
  pthread_t task1;
  //struct sched_param param;

  struct sched_param param;
  int SCHEDU,SCHEDU1;
  int pid;

	printf("Before creating the thread.\n");

		if(pthread_create(&task1, NULL, sum, NULL) == -1) {
		perror("pthread_create");
		return EXIT_FAILURE;
		}
	printf("After creating the thread.\n");

        param.sched_priority = 5;

	if( sched_setscheduler( 0, SCHED_RR, &param ) == -1 ) {
		fprintf(stderr,"error setting scheduler ... are you root?\n");
		exit(1);
	}

	/*
	 * Set the priority of the process
	 */

	if( sched_setparam( 0, &param ) == -1 ) {
		fprintf(stderr,"Error setting priority!\n");
		exit(1);
	}

	pid =getpid();
    printf("pid: %d\n", pid);

	 /*pthread_t this_thread = pthread_self(); retourn -1*/

        SCHEDU=sched_getscheduler(pid);
	sched_setscheduler( pid, SCHED_FIFO, &param);
	SCHEDU1=sched_getscheduler(pid);


	printf("SCHEDU : %d\n", SCHEDU); //2
	printf("SCHEDU1 : %d\n", SCHEDU1);


	int proSCHEDFIFO=sched_get_priority_min(SCHED_FIFO);
	int proSCHEDFIFOmax=sched_get_priority_max(SCHED_FIFO);

	int proSCHEDRR=sched_get_priority_min(SCHED_RR);
	int proSCHEDRRmax=sched_get_priority_max(SCHED_RR);

	 /*printf("proSCHEDFIFO : %d\n", proSCHEDFIFO);
	   printf("proSCHEDFIFOmax : %d\n", proSCHEDFIFOmax);

	   printf("proSCHEDRR : %d\n", proSCHEDRR);
	   printf("proSCHEDRRmax : %d\n", proSCHEDRRmax);
	   printf("After editing the priority thread.\n");

	   param.sched_priority = 99;

	   if (sched_setscheduler(0, SCHED_RR, & param) != 0) {
	 	perror("sched_setscheduler");
		exit(EXIT_FAILURE);
		}
           int schedPRAM= sched_getparam(getpid(), param);

	   int sched=sched_getscheduler(0);
           setpriority(PRIO_PROCESS, getpid(),7);

           int prio=getpriority(PRIO_PROCESS, getpid());

	   printf("schedu : %d\n", sched);
	   printf("schedPRAM : %d\n", schedPRAM);
	   printf("priority : %d\n", prio);*/


		if(pthread_join(task1, NULL))
		{
		printf("Error joining thread");
		return 3;
	} else
		return EXIT_SUCCESS;
}
