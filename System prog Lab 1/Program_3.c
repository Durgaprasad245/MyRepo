#include<stdio.h>

void main(){
    int given_number;
    scanf("%d", &given_number);
    if(given_number%2 == 0) {
        printf("The number is an even number");
    }
    if(given_number%2 != 0) {
        printf("The number is a odd number");
    }
}