#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_SIZE  100

struct pizza {
	float price;
	char name[LINE_SIZE];
	struct pizza *next;
	};

struct pizzaList{
	struct pizza *top;
	struct pizza *bottom;
};

void initialize(struct pizzaList *pizzaMenu) {
	pizzaMenu->top = NULL;
	pizzaMenu->bottom = NULL;
}

void delList(struct pizzaList *pizzaMenu) {
	struct pizza *tempPizza;
	while(pizzaMenu->bottom != NULL){
		tempPizza = pizzaMenu->bottom;
		pizzaMenu->bottom = tempPizza->next;
		free(tempPizza);
	
		
	}
	free(pizzaMenu);
}


int addPizza(float *priceTemp, char *nameTemp, struct pizzaList *pizzaMenu) {
	struct pizza *pizzaNode = (struct pizza*)malloc(sizeof(struct pizza));
	if(pizzaNode == NULL) return 0;
	
	strcpy(pizzaNode->name, nameTemp);
	pizzaNode->price = *priceTemp;
	//printf("%s\n%f\n", pizzaNode->name , pizzaNode->price);
	if(pizzaMenu->bottom == NULL){
		pizzaMenu->bottom = pizzaNode;
	}
	else {
		pizzaMenu->top->next = pizzaNode;

	}
	pizzaMenu->top = pizzaNode;
	pizzaNode->next = NULL; 
	return 1;
	
}

void changeString(char*tempStringComp, char *stringComp){
	strcpy(tempStringComp, stringComp);
	//printf("%s",tempStringComp);
	int i =0;
	while(tempStringComp[i] != '\0') {
		tempStringComp[i] = tolower(tempStringComp[i]);
		if(tempStringComp[i] == '0') tempStringComp[i] = 'o';
		if(tempStringComp[i] == '1') tempStringComp[i] = 'i'; 
		if(tempStringComp[i] == '2') tempStringComp[i] = 'z';
		if(tempStringComp[i] == '3') tempStringComp[i] = 'e';
		if(tempStringComp[i] == '4') tempStringComp[i] = 'a';
		if(tempStringComp[i] == '5') tempStringComp[i] = 's';
		if(tempStringComp[i] == '6') tempStringComp[i] = 'b';
		if(tempStringComp[i] == '7') tempStringComp[i] = 't';
		if(tempStringComp[i] == '8') tempStringComp[i] = 'b';
		if(tempStringComp[i] == '9') tempStringComp[i] = 'q';

		i++;
	}
	//printf("%s", tempStringComp);
}


int stringCompare(char *name, char *stringComp){
	char tempName[LINE_SIZE];
	char tempStringComp[LINE_SIZE];

	int n = strlen(name)-1;
	int s = strlen(stringComp)-1;
	
	//printf("%i\n%i\n",n,s);	
	changeString(tempName, name);
	changeString(tempStringComp, stringComp);

        //printf("%s\n", tempStringComp);
	//printf("%s\n", tempName);

	if(s>n) return -1;

	for(int i=0; i <= n-s; i++) {
		int j;
		for(j=0; j< s; j++ ) {
			//printf("%s",tempName[i+j]);
			if(tempName[i+j] != tempStringComp[j]) break;
	
		}	
	
		if(j == s) {
			//printf("%s", name);
			return 1;
			
			}
	}
	//printf("%s", tempName);
	return 0;
}


void searchList(struct pizzaList *pizzaMenu, char *stringComp){
	struct pizza *pizzaTemp = pizzaMenu->bottom;
	int i = 0;
	while(pizzaTemp != NULL){
		int comp = stringCompare(pizzaTemp->name, stringComp);
		if(comp == 1){
			i++;
			printf("%s%.2f\n",pizzaTemp->name, pizzaTemp->price);
			}
		pizzaTemp = pizzaTemp->next;	
	}
printf("Nacitanych %i poloziek.", i);
}

void printList(struct pizzaList *pizzaMenu) {
	struct pizza *pizzaTemp = pizzaMenu->bottom;
	while(pizzaTemp != NULL) {
		printf("%s", pizzaTemp->name);
		pizzaTemp = pizzaTemp->next;
	}
}
int main() {
	struct pizzaList *pizzaMenu;
	pizzaMenu = (struct pizzaList*)malloc(sizeof(struct pizzaList));

	if(pizzaMenu == NULL) return 1;
	initialize(pizzaMenu);	
	
	char stringCompare[LINE_SIZE];
       	char line[LINE_SIZE];
	int i = 0;
	printf("Zadaj hladanu surovinu:\n");
	while(1){
		char nameTemp[LINE_SIZE];
	
		memset(line,0,LINE_SIZE);
		char*r = fgets(line, LINE_SIZE, stdin);
		if(r!= NULL && line[1] !=0){
			if(i==0) {
				strcpy(stringCompare,line);
				printf("Zadaj jedalny listok:\n");
			}
			else if(i%2 == 1){
				strcpy(nameTemp,line);
			
			}
			else if(i%2 == 0){
				float priceTemp = strtof(line, NULL);
				if(priceTemp == 0.0F) return 1;
				int er = addPizza(&priceTemp,nameTemp, pizzaMenu);
				if(er == 0) return 1;
				memset(nameTemp,0,LINE_SIZE);
			}
		
		}
		else break;
	i++;	
	}
	//printf("%s", stringCompare);
	//printList(pizzaMenu);
	searchList(pizzaMenu, stringCompare);
	delList(pizzaMenu);
	return 0;
}
