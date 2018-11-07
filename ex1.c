#include "linked_list.h"



int main(){
	add(2);
	add(5);
	add(7);
	print();
	add(11);
	add(12);
	print();
	delete(2);
	print();
	delete(11);
	print();
	delete(12);
	print();
	delete(25);
	print();
	delete(0);
	delete(-1);
	add(10);
	delete(7);
	add(12);
	add(15);
	print();
	return 0;
}