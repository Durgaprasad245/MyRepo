#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(char* strings[], int numStrings) {
    int i, j;
    char* key;

    for (i = 1; i < numStrings; i++) {
        key = strings[i];
        j = i - 1;

        while (j >= 0 && strcmp(strings[j], key) > 0) {
            strings[j + 1] = strings[j];
            j = j - 1;
        }

        strings[j + 1] = key;
    }
}

int main() {
    int numStrings;

    printf("Pls enter the number of strings: ");
    scanf("%d", &numStrings);

    char** stringArray = (char**)malloc(numStrings * sizeof(char*));

    for (int i = 0; i < numStrings; i++) {
        printf("Pls enter string %d: ", i + 1);

        char temp[100]; 
        scanf("%s", temp);

        stringArray[i] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(stringArray[i], temp);
    }

    printf("Given array of strings is: [");
    for (int i = 0; i < numStrings - 1; i++) {
        printf("\"%s\", ", stringArray[i]);
    }
    printf("\"%s\"]\n", stringArray[numStrings - 1]);

    insertionSort(stringArray, numStrings);

    printf("Sorted array of strings is: [");
    for (int i = 0; i < numStrings - 1; i++) {
        printf("\"%s\", ", stringArray[i]);
    }
    printf("\"%s\"]\n", stringArray[numStrings - 1]);

    for (int i = 0; i < numStrings; i++) {
        free(stringArray[i]);
    }
    free(stringArray);

    return 0;
}
