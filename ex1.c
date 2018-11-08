#include "linked_list.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_THREADS 5    // The number of threads that are created
#define MAX_CALLS 10 	   // The maximum number of calls to a function of linked_list performed by each thread

pthread_barrier_t barrier; // The barrier used to sync all threads

void* thread_routine(void* data){
	int thd_id = (int) data;
	int rc;

	rc = pthread_barrier_wait(&barrier);

	if(rc == PTHREAD_BARRIER_SERIAL_THREAD){
		printf("All threads are ready.\n");
	}

	srand(time(NULL) * pthread_self());
	int no_of_operations = rand() % MAX_CALLS + 1;

	while(no_of_operations){
		int type_of_call = rand() % 6 + 1;   // The call to add() has more chances to appear
		int parameter = rand() % 100 + 1;

		if (type_of_call == 1){
			printf("Thread %d executes sort()\n", thd_id);
			sort();
		}
		else if(type_of_call == 2){
			printf("Thread %d executes delete(%d)\n", thd_id,parameter);
			delete(parameter);
		}
		else if(type_of_call == 3){
			printf("Thread %d executes print()\n", thd_id);
			print();
		}
		else{
			printf("Thread %d executes add(%d)\n", thd_id,parameter);
			add(parameter);
		}

		no_of_operations--;
	}
}

int main(){
	int i;
	pthread_t tids[NUM_THREADS];

	pthread_barrier_init(&barrier, NULL, NUM_THREADS);

	for(i = 0;i < NUM_THREADS;i++){
		pthread_create(&tids[i],NULL,thread_routine,(void *)i);
	}

	for(i = 0;i < NUM_THREADS; i++){
		pthread_join(tids[i],NULL);
	}

	pthread_barrier_destroy(&barrier);

	return 0;
}