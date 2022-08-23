#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_SIZE  100

struct pizza {
	float price;
	char name[LINE_SIZE];
	};

void delPizza(struct pizza **pizzaMenu, int *j) {

	/* zavola free na kazdu struct pizza a potom na zoznam pizzaMenu */

	for(int i=0; i< (*j); i++) {
		free(pizzaMenu[i]);
		}

	free(*pizzaMenu);
}	

void printPizza(struct pizza *pizzaMenu, int *j){

	/* vypise zoznam pizz */

	for(int i=0; i< (*j); i++) {
		printf("%s%f\n",pizzaMenu[i].name, pizzaMenu[i].price);
		
	}
}

int compare(const void *a, const void *b){

	/* funkcia pre qsort */

	struct pizza *orderA = (struct pizza*) a;
	struct pizza *orderB = (struct pizza*) b;

	if((orderA->price - orderB->price) == 0) return strcmp(orderA->name,orderB->name);
	return((orderA->price > orderB->price) - (orderA->price < orderB-> price));
}


int addPizza(float *priceTemp, char *nameTemp, struct pizza **pizzaMenu, int *j){

	/* prida celu struct pizza do array pizzaMenu */

	struct pizza pizzaNode; //pizza, ktora ma byt pridana
	
	memset(pizzaNode.name,0,LINE_SIZE);
	strcpy(pizzaNode.name, nameTemp);
	pizzaNode.price = *priceTemp;

	*pizzaMenu = realloc(*pizzaMenu, sizeof(struct pizza) * (*j));

	if(pizzaMenu == NULL) return 0;
	memcpy((*pizzaMenu)+ (*j)-1, &pizzaNode, sizeof(struct pizza));
	
	return 1;
}

int main() {

	struct pizza *pizzaMenu = NULL; //array na ulozenie struct pizza
	
       	char line[LINE_SIZE]; //premenna do ktorej sa ulozi nacitany riadok
	int i = 0; // line pocitadlo
	int j = 0; // pizza pocitadlo 

	while(1){
		
		char nameTemp[LINE_SIZE];
	
		memset(line,0,LINE_SIZE);
		char*r = fgets(line, LINE_SIZE, stdin);
		if(r!= NULL && line[1] !=0){

			if(i%2 == 0){
				strcpy(nameTemp,line);
			}
			else if(i%2 == 1){
				float priceTemp = strtof(line, NULL);
				if(priceTemp == 0.0F) break;
				j++;
				int er = addPizza(&priceTemp,nameTemp, &pizzaMenu, &j);
				if(er == 0) return 1;
				memset(nameTemp,0,LINE_SIZE);
			}	
		}
		else break;
	i++;	
	}
	qsort(pizzaMenu,j, sizeof(struct pizza), compare);
	printPizza(pizzaMenu,&j);

	return 0;
}

