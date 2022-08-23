#include "a_train.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct car* add_car(struct car* first,const char* target) {
	
	struct car* newcar = calloc(1,sizeof(struct car));
	if(newcar == NULL) return NULL;

	strcpy(newcar->value, target);
	newcar->next = NULL;
	
	if(first == NULL) {
		first = newcar;		
		}
	else{
		struct car *node = first; 
		while(node->next != NULL) {
			node = node->next;
			}
		node->next = newcar;
	}
	
	return first;
	
	
}

void print_train(struct car* first) {

	if(first == NULL) {
		return;
		}
 	else{
		struct car *node = first;
		while(node->next != NULL) {
			printf("%s\n",node->value);
 			node = node->next;
 			}
 		}
}

void cancel_train(struct car* first) {
	if(first == NULL) return;
	struct car *next;
	while(first != NULL){
		next = first;
		first = first->next;
		free(next);	
		} 	
}


struct car* clear_train(struct car* first, const char* target) {
	
	struct car *temp = first; 
	struct car *prev = first;

	if(first==NULL) return NULL;
	
	//ked je prvy vozen target
	//strcmp vrati 0 ak su stringy rovne cize potrebujem !
	while(temp != NULL && !strcmp(temp->value, target)) {  

		first = temp->next;
		free(temp);
		temp = first;
		}
	//temp je teraz first
	while(temp != NULL) {
		
		//hladam car ktory je target 
		while(temp != NULL && strcmp(temp->value, target)) { //
			
			prev = temp;
			temp = temp->next;
			}
		//ak dojde na koniec tak uz tam target nie je a vrati first		
		if(temp == NULL) return first;
		
		//ak nie je null, je target. 
		//spravim link prvy node-treti
		prev->next = temp->next;
		free(temp);
		//ulozim si do temp treti node
		temp = prev -> next;

	}
	return first;

}

