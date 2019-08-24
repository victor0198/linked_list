#include <stdio.h>
#include <stdlib.h>


typedef struct cell{
	int value;
	struct cell * next;
}cell;

cell * new_cell(){
	return (cell*) malloc(sizeof(cell));
}

void print_list(cell ** first){
	cell * current = *first;
	printf("List: ");
	
//	printf("%d\n", current);
	if(current == NULL){
		printf("%s", "Empty list! Nothing to print!");
	}else{
		while(current != NULL){
			printf("%d ",current->value);
			current = current->next;
		}	
	}
	
	printf("\n");
}

void push(cell ** first, cell ** last, int val){
	printf("Pushing: %d\n", val);
	cell * next = new_cell();
	next->value = val;
	next->next = NULL;
	
	cell * previous = *last;
	if(previous == NULL){
		previous = next;
		*first = previous;
	}else{
		previous->next = next;
	}	
	
	*last = next;		
}

int pop(cell ** first, cell ** last){
	cell * current = *first;
	
	if(current == NULL){
		printf("Empty list! Can\'t pop!\n");
		exit(1);
	}
	
	while(current->next != *last && current->next != NULL){
		current = current->next;
	}
	
	int value;
	
	if(current->next == NULL){
		value = current->value;
		free(current);
		*last = NULL;	
		*first = NULL;
	}else{
		value = current->next->value;
		free(current->next);
		current->next = NULL;
		*last = current;
	}
	
	return value;
}

int shift(cell ** first, cell ** last){
	if(*first == NULL){
		printf("Empty list! Can\'t shift!\n");
		exit(1);
	}	

	cell * current = *first;
	int value = current->value;
	*first = current->next;
	if(*first == NULL){
		*last = NULL;
	}else{
		current->next = NULL;
		free(current);	
	}
	
	
	return value;
}

void unshift(cell ** first, cell ** last, int val){
	printf("Unshifting: %d\n", val);
	
	cell * top = new_cell();
	top->value = val;
	if(*first == NULL){
		top->next = NULL;
		*last = top;
	}else{
		top->next = *first;	
	}
	
	*first = top;
}

int main(){
			
	// Tests
	cell * first = NULL;
	cell * last = NULL;	
	print_list(&first);
	
	push(&first, &last, 10);
	push(&first, &last, 11);
	push(&first, &last, 12);
	push(&first, &last, 13);
	print_list(&first);
	
	printf("Poped: %d\n", pop(&first, &last));
	print_list(&first);
	
	printf("Poped: %d\n", pop(&first, &last));printf("%d %d\n", first, last);
	print_list(&first);
	
	printf("Shifted: %d\n", shift(&first, &last));
	print_list(&first);
	
	printf("Shifted: %d\n", shift(&first, &last));
	print_list(&first);
	
	unshift(&first, &last, 31); 
	print_list(&first);
	
	unshift(&first, &last, 32); 
	print_list(&first);
	
	// end of Tests

	exit(0);
}
