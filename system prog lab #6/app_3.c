/* Sample program to read a comma separated file into a structure and
   display the array of structures */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024

typedef struct listing {
	int id, host_id, minimum_nights, number_of_reviews, calculated_host_listings_count,availability_365, price;
	char *host_name, *neighbourhood_group, *neighbourhood, *room_type;
	double latitude, longitude;
} listing;

struct listing getfields(char* line){
	struct listing item;

	/* Note: you have to pass the string to strtok on the first 
	   invocation and then pass NULL on subsequent invocations */
	item.id = atoi(strtok(line, ","));
	item.host_id = atoi(strtok(NULL, ","));
	item.host_name = strdup(strtok(NULL, ","));
	item.neighbourhood_group = strdup(strtok(NULL, ","));
	item.neighbourhood = strdup(strtok(NULL, ","));
	item.latitude = atof(strtok(NULL, ","));
	item.longitude = atof(strtok(NULL, ","));
	item.room_type = strdup(strtok(NULL, ","));
	item.price = atoi(strtok(NULL, ","));
	item.minimum_nights = atoi(strtok(NULL, ","));
	item.number_of_reviews = atoi(strtok(NULL, ","));
	item.calculated_host_listings_count = atoi(strtok(NULL, ","));
	item.availability_365 = atoi(strtok(NULL, ","));
	
	return item;
}

void displayStruct(struct listing item) {
	printf("ID : %d\n", item.id);
	printf("Host ID : %d\n", item.host_id);
	printf("Host Name : %s\n", item.host_name);
	printf("Neighbourhood Group : %s\n", item.neighbourhood_group);
	printf("Neighbourhood : %s\n", item.neighbourhood);
	printf("Latitude : %lf\n", item.latitude);
	printf("Longitude : %lf\n", item.longitude);
	printf("Room Type : %s\n", item.room_type);
	printf("Price : %d\n", item.price);
	printf("Minimum Nights : %d\n", item.minimum_nights);
	printf("Number of Reviews : %d\n", item.number_of_reviews);
	printf("Calculated Host Listings Count : %d\n", item.calculated_host_listings_count);
	printf("Availability_365 : %d\n\n", item.availability_365);
}

int _host_name_sorter(const void* a, const void* b) {
    return strcmp(((listing*)a)->host_name, ((listing*)b)->host_name);
}

int _price_sorter(const void* a, const void* b) {
    return (((listing*)a)->price > ((listing*)b)->price) - (((listing*)a)->price < ((listing*)b)->price);
}

void _to_csv(char* file_name, listing *list_items, int count, char *labels){
	FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        perror("Error opening output file by host_name");
    }
    fprintf(file, "%s", labels);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%d,%s,%s,%s,%lf,%lf,%s,%d,%d,%d,%d,%d\n", 
            list_items[i].id,list_items[i].host_id,list_items[i].host_name,list_items[i].neighbourhood_group,
            list_items[i].neighbourhood,list_items[i].latitude,list_items[i].longitude,list_items[i].room_type,
            list_items[i].price,list_items[i].minimum_nights,list_items[i].number_of_reviews,list_items[i].calculated_host_listings_count,
            list_items[i].availability_365
        );
    }
    fclose(file);
}

void sort_by_hostname_(listing *list_items, int count, char *labels) {
    qsort(list_items, count, sizeof(listing), _host_name_sorter);
    _to_csv("listings_sorted_hostname.csv", list_items, count, labels);
}

void sort_by_price_(listing *list_items, int count, char *labels) {
    qsort(list_items, count, sizeof(listing), _price_sorter);
    _to_csv("listings_sorted_price.csv", list_items, count, labels);
}

void display_items(listing *list_items, int count) {
	for (int i=0; i<count; i++) displayStruct(list_items[i]);
}

int main(int argc, char* args[]) {
	struct listing list_items[22555];
	char line[LINESIZE];
    char *labels = (char*)malloc(LINESIZE);
	int count;

	FILE *fptr = fopen("listings.csv", "r");
	if(fptr == NULL){
		printf("Error reading input file listings.csv\n");
		exit (-1);
	}

	count = 0;
    int labels_flag = 1;
	while (fgets(line, LINESIZE, fptr) != NULL) {
        if(labels_flag) {
            strcpy(labels, line);
            labels_flag = 0;
        }
		else list_items[count++] = getfields(line);
	}
	fclose(fptr);
	
	display_items(list_items, count);

    sort_by_hostname_(list_items, count, labels);

    sort_by_price_(list_items, count, labels);
	
	return 0;
}
