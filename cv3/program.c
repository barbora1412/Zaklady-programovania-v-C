#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define STACK_SIZE 10
#define LINE_SIZE 100 

struct stack {

	float values[STACK_SIZE];
	int size;
	};

float pop(struct stack *myStack){

	assert(myStack->size > 0);
	float value = myStack->values[myStack->size -1];
	myStack->size -= 1;
	return value;
}

void  push(struct stack *myStack, float *value){
	
	assert(myStack->size < STACK_SIZE);
	myStack->values[myStack->size] = *value;
	myStack->size +=1;
}

void printStack(struct stack *myStack){

	for(int i = 0; i < myStack->size; i++) {
		 printf("%0.2f ",myStack->values[i]);
		
	}
	printf("\n");
}

int isANumber(char* number){
	/** Zisti, ci sa medzi cislami nachadza viac bodiek ako 1 **/
	int dots = 0;

	for(int i =0;i<strlen(number);i++){

		if(number[i] == '.') dots++; 
		if(dots>1) return -1; //Ak je viac ako jedna bodka skonci program
	}
	return 1;
}


int main(){
	
	struct stack myStack;
	
	memset(&myStack,0,sizeof(struct stack));
	myStack.size = 0;	
	
	char line[LINE_SIZE]; //na nacitanie riadka
	memset(line,0,sizeof(char)*LINE_SIZE);
	
	while (1) {
		
		char *r = fgets(line, sizeof(line), stdin);

		if(r!= NULL && line[1] !=0){
			float value = strtof(line, NULL); //skusi premenit riadok na cislo
			if(value != 0.0F || line[0] == '0'){ //ak premenilo na cislo a nie je prazdny riadok
					if(isANumber(line) == -1) { //Ak je viac bodiek v cisle, skonci program
						printf("bad input\n");
						return 0;
					}
					if((line[0] == '0') && (strlen(line) == 2)) value = 0; //Zisti, ci je hodnota cisla 0, strlen pocita bez koncovej nuly
					if(myStack.size == STACK_SIZE) { //Ak je plny stack, nemoze pridat cislo a skonci
						printf("full stack\n");
						return 0;
						} 
					push(&myStack, &value ); //Ak nie je plny stack a cislo je validne spravi push
					printStack(&myStack);
				}

			else if ((line[0] == '+') || (line[0] == '*') || (line[0] == '/') || (line[0] == '-')) { //Ak moze byt riadok operator 
					if(strlen(line)!=2) { //Zisti ci je v riadku viac znakov za operatorom
						printf("bad input\n");
						return 0;
						}
					else if(myStack.size == 1) { //Ak je operator validny, skontroluje ci ma dost cisel
						printf("not enough operands\n");
						return 0;
						}
					// ak ma dost cisel, spravi operaciu
					float val1 = pop(&myStack);
					float val2 = pop(&myStack);
					float result;
					
					if(line[0] == '+') result = val1+val2;
					else if(line[0]=='-') result = val2-val1;
					else if(line[0]=='/') { //skontroluje ci sa nedeli nulou
						if(val1 == 0) {
							printf("division by zero\n");
							return 0;
						}
					result = val2/val1;
						
						}
					else if(line[0] == '*') result = val2*val1;
					
					push(&myStack, &result);
					printStack(&myStack);

					}
			else{
				printf("bad input\n"); //ak je hodnota nieco ine ako cislo a operator na line[0], skonci
				return 0;
				}			
			}
		else break;
		memset(line,0,sizeof(char)*LINE_SIZE); //vycisti line na dalsiu iteraciu
		}
	if(myStack.size == 1) printf("no input\n"); //Ak sa nacitalo len jedno cislo
	return 0;
	}
