#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define ASSIGNMISSION 0
#define START         1
#define TAKEOFF       2
#define NAVIGATE      3
#define LANDING       4
#define COMPLETE      5
#define EXIT 6
#define NUM_THREADS 10

void* createDrone(void* param);

int main() {

	int check;

	pthread_t thread[NUM_THREADS];
	int j;
	int f;
	int myArray[NUM_THREADS] = {0};

	for (j = 0; j < NUM_THREADS; j++){

		sleep(1);
		int check= pthread_create(&thread[j], NULL, createDrone, NULL);

		if (check){
			printf("error");
			exit(0);
		}
	}

	for (j = 0; j < NUM_THREADS; j++) {	
		pthread_join(thread[j], NULL);
	}

	//collision
	for (f = 0; f <= NUM_THREADS; f++){//create array of #s to NUM_THREADS
	int HIGH = NUM_THREADS;
	int LOW = 1;
	
	myArray[f] = LOW + (rand() % (HIGH-LOW));
}

	printf("Checking for collision routes! IGNORE DUPILCATED COLLISION REPORTS! IE: DRONE 6 and 0, and DRONE 0 and 6.\n");
	for (f=0; f<= NUM_THREADS; f++){
	
		for (j = 0; j<=NUM_THREADS; j++){
		
		if (myArray[j] == myArray[f] && (f != j)){
	printf("Drone %d and %d had the same route coordinate! They dodged!\n", j, f);
		}		

		}

	}


	return 0;
}


void* createDrone(void* param){

	int state = 0;
	char c[1];

	while (state != EXIT) {

		switch (state) {
			case 0: {
					printf("Drone Ready.\n"); 
					state = 1;
					sleep(1);
				}
				break;
			case 1: {
					printf("Flying. Loading Mission\n");
					state = 2;
					sleep(1);  
				}
				break;
			case 2: {

					printf("Navigating to target.\n");

					state = 3;
					 sleep(1);

				}
				break;


			case 3: {
					printf("Arrived at target. Delivering package\n");
					state = 4;
					 sleep(1);

				}
				break; // case 3: { ...logic... } break;

			case 4: {

					printf("Navigating Home.\n");

					state = 5;
					 sleep(1);

				}

				break; // case 4: { ...logic... } break;

			case 5: {

					printf("Landed. Mission Complete.\n");

					state = EXIT;
					 sleep(1);


				}

				break; // case 5: { ...logic... } break;

		}
	}
	pthread_exit(0);
}







