#include "linked_list.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_THREADS 5      // The number of threads that are created
#define MAX_CALLS 10 	   // The maximum number of calls to a function of linked_list performed by each thread


void* thread_routine(void* data){
	srand(time(NULL) * pthread_self());
	int no_of_operations = rand() % MAX_CALLS + 1;

	while(no_of_operations){
		int type_of_call = rand() % 6 + 1;   // The call to add() has more chances to appear
		int parameter = rand() % 100 + 1;

		if (type_of_call == 1){
			sort();
			printf("Thread %lu executes sort()\n", pthread_self());
		}
		else if(type_of_call == 2){
			delete(parameter);
			printf("Thread %lu executes delete(%d)\n", pthread_self(),parameter);
		}
		else if(type_of_call == 3){
			print();
			printf("Thread %lu executes print()\n", pthread_self());
		}
		else{
			add(parameter);
			printf("Thread %lu executes add(%d)\n", pthread_self(),parameter);
		}

		no_of_operations--;
	}
}

int main(){
	int i;
	pthread_t tids[NUM_THREADS];

	for(i = 0;i < NUM_THREADS;i++){
		pthread_create(&tids[i],NULL,thread_routine,(void *)i);
	}

	for(i = 0;i < NUM_THREADS; i++){
		pthread_join(tids[i],NULL);
	}

	return 0;
}