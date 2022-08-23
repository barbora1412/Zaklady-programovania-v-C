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
	
	/* Inicializuje strukturu pizzaMenu */

	pizzaMenu->top = NULL;
	pizzaMenu->bottom = NULL;
}

void delList(struct pizzaList *pizzaMenu) {
 	/*free kazdu pizzu a nakoniec pizzaMenu */

	struct pizza *tempPizza;
	while(pizzaMenu->bottom != NULL){
		tempPizza = pizzaMenu->bottom;
		pizzaMenu->bottom = tempPizza->next;
		free(tempPizza);
	
		
	}
	free(pizzaMenu);
}


int addPizza(float *priceTemp, char *nameTemp, struct pizzaList *pizzaMenu) {

	 /* Prida struct pizza do linked List struktury pizzaList */

	struct pizza *pizzaNode = (struct pizza*)malloc(sizeof(struct pizza));
	if(pizzaNode == NULL) return 0;
	
	strcpy(pizzaNode->name, nameTemp);
	pizzaNode->price = *priceTemp;
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

	/* Premeni Hacker script na lowecase pismena */

	strcpy(tempStringComp, stringComp);

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
	
}


int stringCompare(char *name, char *stringComp){

	/* Najde zhodu v mene pizze */

	char tempName[LINE_SIZE];
	char tempStringComp[LINE_SIZE];

	int n = strlen(name)-1; //dlzka mena
	int s = strlen(stringComp)-1; //dlzka porovnavacieho stringu
	
		
	changeString(tempName, name);
	changeString(tempStringComp, stringComp);


	if(s>n) return -1; //ak je dlzka stringu na porovnanie dlhsia ako
			   // meno tak nemoze byt zhoda

	for(int i=0; i <= n-s; i++) {
		int j;
		for(j=0; j< s; j++ ) {
			
			if(tempName[i+j] != tempStringComp[j]) break;
	
		}	
	
		if(j == s) {
			
			return 1;
			
			}
	}
	
	return 0;
}


void searchList(struct pizzaList *pizzaMenu, char *stringComp){

	/*prejde linked list pizzaMenu a zisti ci je zhoda, ak ano vypise pizzu */

	struct pizza *pizzaTemp = pizzaMenu->bottom;
	int i = 0;
	while(pizzaTemp != NULL){
		int comp = stringCompare(pizzaTemp->name, stringComp);
		if(comp == 1){ //ak je zhoda tak vypis pizzu
			printf("%s%.2f\n",pizzaTemp->name, pizzaTemp->price);
			}
		i++;
		pizzaTemp = pizzaTemp->next;	
	}
printf("Nacitanych %i poloziek.\n", i);
}

void printList(struct pizzaList *pizzaMenu) {
	/* Pracovna funkcia na vypisanie pizzaList, nepouzivana */

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
	
	char stringCompare[LINE_SIZE]; //string na porovnavanie
       	char line[LINE_SIZE]; //string kde sa nacita riadok
	int i = 0; //pocitadlo riadku
	printf("Zadaj hladanu surovinu:\n");
	while(1){
		char nameTemp[LINE_SIZE]; //meno, ktore sa ponecha kym sa nenacita cena pizze
	
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
	searchList(pizzaMenu, stringCompare);
	delList(pizzaMenu); // free struktury
	return 0;
}
