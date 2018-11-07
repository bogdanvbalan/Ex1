#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*Definition of the node struct*/
typedef struct node{
  struct node * next;
  int val;
  print_ptr print_list;
} node;

void print_item(node* current); // The declaration is need so that it can be used in add function

/* Initialization of the head node */
node* head = NULL;

/*Function used to add an item to the list.
The item will be added at the end of the list*/
void add(int val){
	node* current = malloc(sizeof(node));
	if(head == NULL){                  //If this is the first node set it as head
		current->next = NULL;
		current->val = val;
		current->print_list = print_item;
		head = current;
	}
	else{
		current = head;
		while(current->next!=NULL){
			current = current->next;   //Iterate over the list till the last item
		}
		current->next = malloc(sizeof(node));
		current->next->val = val;
		current->next->next = NULL;
		current->next->print_list = print_item;
	}
}

/*Function used to print the list*/
void print(){
	node* current = head;
	if(current == NULL){
		printf("The list has no items.\n");
	}
	else{
		while(current!=NULL){
			current->print_list(current);
			current = current->next;
		}
	}
}

/* Function used to print individual items*/
void print_item(node* current){
	if(current!=NULL){
		printf("%d\n",current->val);
	}
	else{
		printf("The current item is NULL.");
	}
}

/* Function used to delete a specific item*/
void delete(int val){
	node* current = NULL;
	node* temp = NULL;

	if(head->val==val){
		temp = head;
		head = head->next;
		free(temp);
	}
	else{
		current = head;
		while((current->next->next!=NULL)&&(current->next->val!=val)){
			current = current->next;
		}
		if((current->next->next==NULL)&&(current->next->val!=val)){
			printf("The value was not found in the list.\n");
		}
		else{
			temp = current->next;
			current->next = temp->next;
			free(temp);
		}
	}
}

/*Functions used to sort the list.*/

/* The function merges the two lists that are sorted.*/
node* merge_lists(node* list_a,node* list_b){
	node* result = NULL;
	if(list_a == NULL){  // the cases when one of the list is empty
		return list_b;
	}
	if(list_b == NULL){
		return list_a;
	}

	if(list_a->val <= list_b->val){
		result = list_a;
		result->next = merge_lists(list_a->next,list_b);
	}
	else{
		result = list_b;
		result->next = merge_lists(list_a,list_b->next);
	}
	return result;

}

/*Function used to split the nodes of a given list in two different lists*/
void split(node* source,node** left,node** right){
	if((source == NULL) || (source->next == NULL) ){
		printf("Reached this.");
		*left = source;
		*right = NULL;
		return;
	}
	node* first_pass = source;
	node* second_pass = source->next;

	while(first_pass != NULL){
		first_pass = first_pass->next;
		if(first_pass != NULL){
			second_pass = second_pass->next;
			first_pass = first_pass->next;
		}
	}

	*left = source;
	*right = second_pass;
	second_pass->next = NULL;
}

/*Sort the given list*/
void merge_sort(node** head){
	if(*head == NULL || (*head)->next == NULL){
		return;
	}

	node* a = NULL;
	node* b = NULL;

	split(*head,&a,&b);
	printf("%d\n",a->val);
	printf("%d\n",b->val);
	//merge_sort(&a);
	//merge_sort(&b);

	//*head = merge_lists(a,b);
}

void sort(){
	merge_sort(&head);
}

/*Function used to delete the last entry in the list*/
void pop(){
	node* current = head;
	node* temp = NULL;

	if(head == NULL){
		return;
	}
	if(current->next == NULL){
		temp = head;
		head = NULL;
		free(temp);
	}
	while(current->next->next != NULL){
		current = current->next;
	}
	temp = current->next;
	current->next = NULL;
	free(temp);

}
/*Function used to flush the list*/
void flush(){
	while(head != NULL){
		pop();
	}
}