#include "a_station.h"
#include <stdlib.h>
#include <string.h>

struct station* create_station(){
   struct station* station = (struct station*)calloc(1,sizeof(struct station));
   station->tracks = (struct car**)calloc(STATION_SIZE, sizeof(struct car*));
   station->track_count = STATION_SIZE;
   return station;
}

void destroy_station(struct station* station){
	
	for(int i=0; i < STATION_SIZE; i++){
		
		struct car* tmp;
		struct car* head = station->tracks[i];

		while(head != NULL) {
			tmp = head;
			head = head->next;
			free(tmp);
			}
		
		}
	free(station->tracks);
	free(station);

}

int select_track(struct station* station, const char* target){
	int hash = 0;
	for(int counter = 0; target[counter]!='\0'; counter ++){
		
		hash = target[counter] + (hash << 6) + (hash << 16)-hash;
		
		}
	hash = hash%STATION_SIZE;
	if(hash<0){ //ak je hash zaporny, premeni ho na kladne cislo
		hash = hash*(-1);
		}
	return hash;
}
struct car* createCar(const char* string, int capacity){
	
	struct car* tmpCar = calloc(1,sizeof(struct car));
	
	tmpCar->capacity = capacity;
	tmpCar->next = NULL;
	strcpy(tmpCar->value, string);
	return tmpCar;
}


void add_target_capacity(struct station* station,const char* target, int capacity){

	int slot = select_track(station,target); //pozicia v array
	if(station->tracks[slot] == NULL){ //ak na pozicii nic nie je, vytvori novy zaznam
		struct car* tmpCar = createCar(target, capacity);
		station->tracks[slot] = tmpCar;
		}
	else {
	struct car* current = station->tracks[slot];
	struct car* prev = station->tracks[slot]; 
	
		// ak na pozicii uz nieco je, prehlada list   
		while(current !=NULL) {

			if(!strcmp(current->value,target)) {
				current->capacity = current->capacity + capacity;
				return;
				}
			prev = current;
			current = current->next;
			}
		struct car* tmpCar = createCar(target, capacity);
		prev->next = tmpCar;
		}

}

int get_target_capacity(struct station* station,const char* target){
   
	for(int i=0; i < STATION_SIZE; i++){

		struct car* tmp = station->tracks[i];
 		
		while(tmp != NULL) {
			if(!strcmp(tmp->value, target)){
				return tmp->capacity;
				}
			tmp = tmp->next;
			}	
	}
	return 0;

}

int count_targets(struct station* station){
    	
	int j = 0;

	for(int i=0; i<STATION_SIZE; i++) {
		struct car*tmp = station->tracks[i];

		while(tmp != NULL) {
			j++;
			tmp = tmp->next;
			}
	}
	return j;
	
}

int count_capacity(struct station* station){
	int j = 0;
	
	for(int i=0; i<STATION_SIZE; i++) {

		struct car*tmp = station->tracks[i];

		while(tmp != NULL) {
		
			j = j+tmp->capacity;
			tmp = tmp->next;
		}
	}
	return j;
}
