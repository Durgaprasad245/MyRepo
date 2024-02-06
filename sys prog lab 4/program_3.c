#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_args(int arg_count, char *arg){
    if (arg_count != 3) {
        fprintf(stderr, "Usage: %s <first_file> <second_file>\n", arg);
        exit(-1);
    }
}

void check_files(char *a, char *b){
    if (strcmp(a, b) == 0) {
        fprintf(stderr, "Error: The two filenames are the same.\n");
        exit(-1);
    }
}

int main(int argc, char *argv[]) {
    check_args(argc, argv[0]);
    check_files(argv[1], argv[2]);
    FILE *f_1, *f_2;
    f_1 = fopen(argv[1], "a");
    if (f_1 == NULL) {
        perror("Error opening first file");
        exit(-1);
    }
    f_2 = fopen(argv[2], "r");
    if (f_2 == NULL) {
        perror("Error opening second file");
        fclose(f_1);
        exit(-1);
    }
    int item, start = 0;
    while ((item = fgetc(f_2)) != EOF) {
        if(start == 0) fputs("\n", f_1);
        fputc(item, f_1);
        start++;
    }
    fclose(f_1);
    fclose(f_2);
    printf("Contents of %s successfully concatenated to %s\n", argv[2], argv[1]);
    return 0;
}
