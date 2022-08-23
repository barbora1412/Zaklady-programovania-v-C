// Max binárna kopa
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

// Ľubovoľné (dynamické) pole môže byť binárna kopa
struct heap {
    int* array;
    int size;
    int capacity;
};

// Výpočet rodičovského uzla
int parent(int i){
    return (i -1) / 2;
}

// Výpočeť ľavého syna
int left_child(int i){
    return (2*i) + 1;
}

// Výpočet pravého syna
int right_child(int i){
    return (2*i) + 2;
}

// Test kopovitosti
// Pozeráme, či je každý potomok menší ako jeho rodič
// Funkcia zlyhá, ak nájdeme aspoň jedného potomka, väčšieho alebo rovného ako je rodič
int check_heap_property(int* numbers, int * length){
    for (int i = 0; i < *length / 2 ; i++){
        int c = left_child(i);
        if (c >= *length){
            break;
        }
        if(numbers[c] <= numbers[i]) {
	    return 1;
	}
        c = right_child(i);
        if (c >= *length){
            break;
        }
        if(numbers[c] <= numbers[i]) {
	    return 1;
	}
    }
    return 0;
}



// Vypis
void printHeap(int* numbers, int offset, int i, int *length ) {
	if(i>=*length){
		return;
	}
        for(int j = 0; j < offset; j++){
		printf(" ");
	}
	printf("%d\n", numbers[i]);

	printHeap(numbers, offset+1, left_child(i), length);
	printHeap(numbers, offset+1, right_child(i), length);
	
}

// Oddeli jednotlive stringy, premeni ich na int a ulozi do pola
int extract_and_convert(char *line, int *numbers, int *length) {
	char *token;
	token = strtok(line, " ");
	if(token == NULL){
		return 1;
	}
	
	numbers[*length] = atoi(token);
	int i = 0;
	while(token != NULL){
		*length = (*length) + 1;
		i++;
		token = strtok(NULL, " ");
		if(token != NULL) {
			numbers[*length] = atoi(token);
		}
	}
	return 0;
}

int main(){
    char line[SIZE]; //Nacita riadok do line
    memset(line, 0, SIZE);
    fgets(line, SIZE, stdin);
   //  printf("%s", line); 
    int length = 0;
    int numbers[SIZE];
    extract_and_convert(line, numbers, &length);
    int isHeap = check_heap_property(numbers,&length);
    if(isHeap == 1) {
	printf("Nie je kopa.\n");
	}
    else {
	printf("Je to taka kopa:\n");
	printHeap(numbers,0,0,&length);
	}

    return 0;
}
