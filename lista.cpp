#include <stdio.h>
#include <stdlib.h>


struct cell{
	int value;
	cell * next;
};

cell * new_cell(){
	return (cell*) malloc(sizeof(cell));
}

void print_list(cell * current){
	printf("List: "); 
	do{
		printf("%d ",current->value);
		current = current->next;
	}while(current != NULL);
	printf("\n");
}

void push(cell ** last, int val){
	printf("Pushing: %d\n", val);
	cell * next = new_cell();
	next->value = val;
	next->next = NULL;
	
	cell * previous = *last;
	previous->next = next;	
	
	*last = next;		
}

int pop(cell * current, cell ** last){
	
	do{
		current = current->next;
	}while(current->next->next != NULL);
	
	int value = current->next->value;
	free(current->next);
	current->next = NULL;
	*last = current;
	
	return value;
}

int shift(cell ** first){
	cell * current = *first;
	int value = current->value;
	*first = current->next;
	current->next = NULL;
	free(current);
	
	return value;
}

void unshift(cell ** first, int val){
	printf("Unshifting: %d\n", val);
	
	cell * current = *first;
	
	cell * top = new_cell();
	top->value = val;
	top->next = current;
	
	*first = top;
}

int main(){
			
	// Tests
	cell * first = new_cell();
	first->value = 0;
	first->next = NULL;
	cell * last;
	
	cell * current = first;
	for(int i = 1; i < 10; i++){
		current->next = new_cell();
		current = current->next;
		current->value = i;
		current->next = NULL;
		
		if(i==9)
			last = current;
	}
	
	
	print_list(first);
	printf("First: %d, Last: %d\n", first->value, last->value);
	
	push(&last, 10); 
	push(&last, 11); 
	push(&last, 12); 	
		
	print_list(first);
	printf("First: %d, Last: %d\n", first->value, last->value);
	
	printf("Poped: %d\n", pop(first, &last));
	printf("Poped: %d\n", pop(first, &last));
	
	print_list(first);
	printf("First: %d, Last: %d\n", first->value, last->value);
	
	printf("Shifted: %d\n", shift(&first));
	printf("Shifted: %d\n", shift(&first));
	printf("Shifted: %d\n", shift(&first));
	
	print_list(first);
	printf("First: %d, Last: %d\n", first->value, last->value);
	
	unshift(&first, -1); 
	unshift(&first, -2); 	
		
	print_list(first);
	printf("First: %d, Last: %d\n", first->value, last->value);
	// end of Tests

	exit(0);
}
