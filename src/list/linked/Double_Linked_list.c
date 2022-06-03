#include <stdio.h>
#include <stdlib.h>

typedef struct List{
	
	int data;
	struct List *prev;
	struct List *next;
}List;



void deleteList(List *head){
	
	List *curr = head->next;
	
	while(curr != 0){
		
		List *temp = curr->next;
		free(curr);
		curr = temp;
	}
	head->ptr = 0;
}


void printList(List *head){
	
	List *curr = head->next;
	while(curr != 0){
		
		printf(" %d ", curr->data);
		curr = curr->next;
	}
}


void addList(List *head, int data){
	
	List *new = malloc(sizeof(List));
	new->data = data;
	new->prev = head;
	new->next = head->next;
	head->next = new;
	
}


int main(){
	
	List *head = malloc(sizeof(List));
	head->prev = 0;
	head->next = 0;
	
	while(1){

		int data = 0;
		int c = 0;
		scanf("%d", &c);
		
		switch(c){
			
			case 1 : addList(head, data);
					 break;
						
			case 2 : printList(head);
					 break;
			
			case 3 : deleteList(head);
					 break;
			
			default : break;
			
		}
	}	
	free(head);
}
