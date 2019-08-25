#include <stdio.h>
#include <stdlib.h>


typedef struct cell{
	int value;
	struct cell * next;
}cell;

typedef struct list{
	cell * first;
	cell * last;
	int len;
}list;

cell * new_cell(){
	return (cell*) malloc(sizeof(cell));
}

void print_l(list obj){
	cell * current = obj.first;
	printf("List: ");
	
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

void push_l(list * obj, int val){
	
	printf("Pushing: %d\n", val);
	cell * next = new_cell();
	next->value = val;
	next->next = NULL;
	
	cell * previous = obj->last;
	if(previous == NULL){
		previous = next;
		obj->first = previous;
	}else{
		previous->next = next;
	}
	
	obj->last = next;		
}

int pop_l(list * obj){
	cell * current = obj->first;
	
	if(current == NULL){
		printf("Empty list! Can\'t pop!\n");
		exit(1);
	}
	
	while(current->next != obj->last && current->next != NULL){
		current = current->next;
	}
	
	int value;
	
	if(current->next == NULL){
		value = current->value;
		free(current);
		obj->first = NULL;
		obj->last = NULL;	
	}else{
		value = current->next->value;
		free(current->next);
		current->next = NULL;
		obj->last = current;
	}
	
	return value;
}

int shift_l(list * obj){
	if(obj->first == NULL){
		printf("Empty list! Can\'t shift!\n");
		exit(1);
	}	

	cell * current = obj->first;
	int value = current->value;
	obj->first = current->next;
	if(obj->first == NULL){
		obj->last = NULL;
	}else{
		current->next = NULL;
		free(current);	
	}
		
	return value;
}

void unshift_l(list * obj, int val){
	printf("Unshifting: %d\n", val);
	
	cell * top = new_cell();
	top->value = val;
	if(obj->first == NULL){
		top->next = NULL;
		obj->last = top;
	}else{
		top->next = obj->first;	
	}
	
	obj->first = top;
}

int main(){
			
	// Tests
	
	list obj;
	obj.first = NULL;
	obj.last = NULL;
	obj.len = 0;
	
	print_l(obj);
	
		push_l(&obj, 6);
		push_l(&obj, 7);
		push_l(&obj, 8);
	
	print_l(obj);
	
		printf("Poped: %d\n", pop_l(&obj));
	
	print_l(obj);
	
		printf("Shifted: %d\n", shift_l(&obj));

	print_l(obj);
	
		unshift_l(&obj, 4);
	
	print_l(obj);
	
	// end of Tests
	
	exit(0);
}
