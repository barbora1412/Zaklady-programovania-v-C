#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define LINE_SIZE 100

struct stack {

	int size;
	char stack_array[LINE_SIZE];

	};

char  pop(struct stack* tmpStack) {
	
	assert(tmpStack->size > 0);
	char c = tmpStack->stack_array[tmpStack->size -1];
	tmpStack->size -=1;
	return c;
}

void push(struct stack* tmpStack, char *c) {
	
	assert(tmpStack->size <LINE_SIZE);
	tmpStack->stack_array[tmpStack->size] = *c;
	tmpStack->size +=1; 


}

char findCompatibleBracket(char c){
/**
 *Najde pravu zatvorku k lavej
 *@return prava zatvorka
*/
	switch(c){

		case '(':
			return ')';
		case '{':
			return '}';
		case '[':
			return ']';
		case '<':
			return '>';
		
		}
	return c;
}

char findLeft(char c) {
/**
 *Najde lavu zatvorku k pravej
 *@return lava zatvorka
*/
	switch(c){

		case ')':
			return '(';
		case '}':
			return '{';
		case ']':
			return '[';
		case '>':
			return '<';
		}
	return c;

}

char* findMissingRights(struct stack* tmpStack) {
/**
 *Ku vsetkym lavym zatvorkam v stack najde pravu zatvorku
 *@return list najdenych zatvoriek
*/
	char* array = malloc(sizeof(char)*LINE_SIZE);
	memset(array,0,sizeof(char)*LINE_SIZE);
	int size = tmpStack->size;
	for(int i=0; i<size; i++) {
		char a = pop(tmpStack);
		array[i] = findCompatibleBracket(a);		
		}
	return array;

}
int checkBrackets(struct stack* tmpStack,char* line){
/**
 *Prehlada string a najde zatvorky
 *@return vrati 1 ak chybaju/krizuju sa zatvorky, 0 ak su v poriadku
*/

	int i = 0;
	while(line[i]) {
		//aktualne pismenko
		char c = line[i];
		//ak lava zatvorka-vlozi do stack
		if(c == '{' || c == '[' || c == '(' || c == '<'){
			push(tmpStack, &c);
		}
		//ak najde pravu zatvorku
		if(c == '}' || c == ']' || c == ')' || c == '>'){
			//ked sa v stack nic nenachadza chyba lava
			if(tmpStack->size ==0){
				printf("Unexpected closing bracket %c in %d\n", c,i);
				return 1;
				}
			//ak v stack nieco je spravi pop 
			char b = pop(tmpStack);
			//na porovnanie najde k aktualnej zatvorke jej lavu dvojicu
			char d = findLeft(c);	
			//porovna ci sa zatvorka zo zasobnika a lava z aktualnej nezhoduju	
			if (b != d) {
				
				//najde pravu zatvorku k lavej
				char a = findCompatibleBracket(b);
				printf("Crossed bracket %c in %d, expected %c \n",c,i,a);
				return 1; 
				}
		}
		
		i++;
	}
	//ak po prejdeni stringu je v stacku nieco ->chybaju prave zatvorky
	if(tmpStack->size != 0) {
		char array[LINE_SIZE];
		memset(array,0,sizeof(char)*LINE_SIZE);
		//najde k nim dvojicu
		char * rights = findMissingRights(tmpStack);
		//nemoze priradit char* do char[100] tak musi skopirovat
		strcpy(array,rights);
		printf("Missing closing brackets: %s\n",array);
		free(rights);
		
		return 1;
		}
	printf("All brackets OK\n");
	return 0;

}
int main() {
	
	struct stack tmpStack; //stack na ukladanie zatvoriek
	memset(&tmpStack,0,sizeof(struct stack));
	tmpStack.size = 0;
	char line[LINE_SIZE]; //string zo vstupu
	memset(line,0,sizeof(char)*LINE_SIZE);

	char* r= fgets(line, LINE_SIZE, stdin);
	
	if(r != NULL && line[1] !=0) {
		printf("Read: %s",line);
		checkBrackets(&tmpStack,line);

		}
	return 0;
}
