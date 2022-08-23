#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define SIZE 100

struct tree {
	char value[SIZE];
	struct tree* left;
	struct tree* right;
};

void destroy_tree(struct tree* node) {
	
	if(node != NULL) {
		destroy_tree(node->left);
		destroy_tree(node->right);
		free(node);
	}
}

//i=0 ->neni konec riadka, i=1 ->je konec riadka
struct tree* read_tree() {
	char buffer[SIZE];
	memset(buffer,0,SIZE);
	char* r = fgets(buffer, SIZE, stdin);
	if(r == NULL) {
		printf("Chybna databaza\n");
		return NULL;
	}
	struct tree* node = calloc(1,sizeof(struct tree));
	memcpy(node->value, buffer,SIZE);
	if(buffer[0] != '*'){
		node->left = read_tree();	
		node->right = read_tree();
	}
	return node;
}

void print_tree(struct tree* tree, int offset){

	for(int i=0; i<offset; i++) {
		printf(" ");
		}
	printf("%s", tree->value);
	if(tree->left){
		print_tree(tree->left, offset + 3);
		print_tree(tree->right, offset +3);
		
		}
}

int getLeafCount(struct tree* node) {

	if(node == NULL) {
		return 0;
	}
	if(node->left == NULL && node->right == NULL){
		return 1;
	}
	else
		return getLeafCount(node->left)+getLeafCount(node->right);

}

int main(){
	printf("Expert z bufetu to vie.\n");
	struct tree* root = read_tree();
	if(root == NULL) return 0;
	char empty[SIZE];
	memset(empty,0,SIZE);
	char *r = fgets(empty,SIZE,stdin);
	if(root == NULL) return 0;
	if(empty[0] != '\n') {
			printf("Chybna databaza\n");
			return 0;
	}
	//print_tree(root,0);
	int count = getLeafCount(root);
	int m =0; //ak ine pismenko ako n/a -> m=1
	int i = 0;
	printf("Pozna %d druhov ovocia a zeleniny.\n", count);
	printf("Odpovedajte 'a' pre prvu moznost alebo 'n' pre druhu moznost.\n");
	struct tree* node = root;
	while(1){
		printf("%s", node->value);
		if(node->left == NULL && node->right == NULL){
			break;
			}
		else {
			
			r = fgets(empty,SIZE,stdin);
			if(r == NULL && i == 0){
				printf("Koniec vstupu\n");
				return 0;
			}
			i++;
			if(empty[0]=='a') {
				node = node->left;
				}
			else if(empty[0]=='n') {
				node = node->right;
				}
			else {
				m =1;
				printf("Nerozumiem\n");
				break;
				}	
			}	
		
		}
	
	if(m!=1){
		printf("Koniec\n");
	}
	destroy_tree(root);

	return 0;
}

