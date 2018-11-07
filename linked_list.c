#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_fct();  // The declaration is need so that it can be used in add function

/* Definition of the head Node */
Node* head = NULL;

/*Function used to add an item to the list.
The item will be added at the end of the list*/

void add(int val){
	Node* current = malloc(sizeof(Node));
	if(head == NULL){                  //If this is the first node set it as head
		current->next = NULL;
		current->val = val;
		current->print_list = print_fct;
		head = current;
	}
	else{
		current = head;
		while(current->next!=NULL){
			current = current->next;   //Iterate over the list till the last item
		}
		current->next = malloc(sizeof(Node));
		current->next->val = val;
		current->next->next = NULL;
		current->next->print_list = print_fct;
	}
}

/*Function used to print the list*/
void print_fct(){
	Node* current = head;
	if(current == NULL){
		printf("The list has no items.");
	}
	else{
		while(current!=NULL){
			printf("%d\n",current->val);
			current = current->next;
		}
	}
}

