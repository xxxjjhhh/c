#include <stdio.h>
#include <stdlib.h>

typedef struct List{

	int data;
	struct List *ptr;

}List;


void deleteList(List *head){

	List *curr = head->ptr;
    
	while(curr != 0){
		
		List *temp = curr->ptr; //다음값 저장용 임시 리스트 생성  
		free(curr);
		curr = temp;
	}
	head->ptr = 0;
}


void addList(List *head, int data){

	List *new = malloc(sizeof(List));
	new->data = data;
	new->ptr = head->ptr;
	head->ptr = new;
	
}


void printList(List *head){
	
	List *curr = head->ptr;
	while(curr != 0){

		printf("%d", curr->data);
		curr = curr->ptr;
	}
}


int main(){

  	List *head = malloc(sizeof(List));
   	head->ptr = 0;
	int data = 0;
	
	while(1){

		int choose = 0;
		scanf("%d", &choose);

		switch(choose){
	
   			case 1 : addList(head, data); break;
	
			case 2 : deleteList(head); break;

			case 3 : printList(head); break;

			default : break;

		}
	}	
	free(head);
}
