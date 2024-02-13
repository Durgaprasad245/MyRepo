#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_PATH_SIZE 2000

typedef struct Flags {

    // "v" Argument
    int is1;

    // "s" Argument
    int is2;
    int arg2;

    // "s" Argument
    int is3;
    char *arg3;
    int depth;

    // "t" Argument
    int is4;
    char *arg4;

} Flags;

Flags* init_Flags(Flags *flags) {
    flags->is1 = FALSE;
    flags->is2 = FALSE;
    flags->arg2 = 0;
    flags->is3 = FALSE;
    flags->arg3 = NULL;
    flags->depth = 0;
    flags->is4 = FALSE;
    flags->arg4 = NULL;
    return flags;
}

typedef struct {
    char **files;
    size_t used;
    size_t size;
} Files;

void initArray(Files *a, size_t initialSize) {
    a->files = malloc(initialSize * sizeof(char *));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Files a, char element) {
    if (a.used == a.size) {
        a.size *= 2;
        a.files = realloc(a.files, a.size * sizeof(char *));
    }
    if (element != '\0'){
        a.files[a.used] = (char *) malloc( strlen(&element) + 1 );
        strcpy(a.files[a.used++], &element);
    }else {
        a.files[a.used] = (char *) malloc( strlen("NULL") + 1 );
        a.files[a.used++] = &element;
    }
}

void freeArray(Files *a) {
    free(a->files);
    a->files = NULL;
    a->used = a->size = 0;
}

Files files;
Flags flags;



int check_File(char *fileName, struct stat *stats, int tabSpaces) {
    // "L" Argument
    if (flags.is2 && !(stats->st_size >= flags.arg2)) {
        return FALSE;
    }
    // "s" Argument
    if (flags.is3 && (strstr(fileName, flags.arg3) == NULL || !(tabSpaces <= flags.depth))) {
        return FALSE;
    }
    // "t" Argument
    if (flags.is4 && (strcmp(flags.arg4, "f") == 0) && ((stats->st_mode & S_IFMT) != S_IFREG)) {
        return FALSE;
    }
    if (flags.is4 && (strcmp(flags.arg4, "d") == 0) && ((stats->st_mode & S_IFMT) != S_IFDIR)) {
        return FALSE;
    }

    return TRUE;
}


typedef void MyFunc_1 (char *fileName, struct stat *stats, int *count, int tabSpaces);


char** parse(char *command,char *fileName ){
    char **array =  malloc(1 * sizeof(char *));
    char* dupCommand = malloc(strlen(command) * sizeof(char *));
    strcpy(dupCommand, command);
    char *p=strtok(dupCommand," ");

    while (p != NULL)
    {
        if(files.used > 0){
            array=realloc(array, (files.size) * sizeof(char *));
        }
        array[files.used] = (char *) malloc( strlen(p) + 1 );
        strcpy(array[files.used++], p);
        files.size*=2;
        p = strtok (NULL, " ");
    }

    if (fileName){
        files.size*=2;
        array= realloc(array, (files.size) * sizeof(char *));
        array[files.used] = (char *) malloc( strlen(fileName) + 1 );
        strcpy(array[files.used++], fileName);
        files.size*=2;
        array= realloc(array, (files.size) * sizeof(char *));
        array[files.used] = (char *) malloc( strlen("NULL") + 1 );
        array[files.used++]= NULL;
    }

    return array;
}

void print_File(char *fileName, struct stat *stats, int *count, int tabSpaces) {

    // The print statement changes only with the v flag.
    if (!flags.is1) {
        printf("%*s[%d] %s\n", 4 * tabSpaces, "", *count, fileName);
    }
    else {

        // Print 0 for file size if directory.
        if ((stats->st_mode & S_IFMT) == S_IFDIR) {
            printf("%*s[%d] %s %d Bytes, %o, %s\n", 4 * tabSpaces, "", *count, fileName, 0, stats->st_mode & 0777, ctime(&stats->st_mtime));
        }
            // Print actual size for everything else.
        else {
            printf("%*s[%d] %s %lld Bytes, %o, %s\n", 4 * tabSpaces, "", *count, fileName, stats->st_size, stats->st_mode & 0777, ctime(&stats->st_mtime));
        }
    }
    *(count) += 1;
}

// Notice: funcPtr in traverse_Directory is a function pointer.

void traverse_Directory(char *path, int tabSpaces, MyFunc_1 funcPtr) {

    struct dirent *dirent;
    struct stat stats;
    DIR *parentDir;

    if (tabSpaces == 0) {
        printf("Starting Directory: %s\n", path);
    }

    parentDir = opendir(path);

    if (parentDir == NULL) {
        printf ("Error opening directory '%s'\n", path);
        exit(-1);
    }

    int count = 1;
    while((dirent = readdir(parentDir)) != NULL) {

        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }


        // Create path to file
        char *filePath = (char *) malloc(MAX_PATH_SIZE);
        strcpy(filePath, path);
        strcat(filePath, "/");
        strcat(filePath, dirent->d_name);

        // Use stat function to gather info about file (stored in stats variable)
        if (stat(filePath, &stats) == -1) {
            printf("Error with stat '%s\n", filePath);
            exit(-1);
        }

        // Check if the file meets all flag criteria
        if (check_File(dirent->d_name, &stats, tabSpaces)) {
            // Perform action on file
            funcPtr(filePath, &stats, &count, tabSpaces);
        }

        if (dirent->d_type == DT_DIR) {
            // Traverse subdirectory
            traverse_Directory(filePath, tabSpaces + 1, funcPtr);
        }

        free(filePath);

    }
    closedir(parentDir);
}

int main(int argc, char **argv) {

    int opt;
    init_Flags(&flags);
    initArray(&files,1);
    int opc = 0;
    for(int i=1; i<argc; i++){
        if(!flags.is1 && (strcmp(argv[i],"-v") == 0)){
            opc = opc + 1;
            flags.is1 = TRUE;
        }
        else if(!flags.is2 && (strcmp(argv[i],"-L") == 0)){
            opc = opc + 2;
            flags.is2 = TRUE;
            flags.arg2 = atoi(argv[i+1]);
        }
        else if(!flags.is3 && (strcmp(argv[i],"-s") == 0)){
            opc = opc + 3;
            flags.is3 = TRUE;
            flags.arg3 = argv[i+1];
            flags.depth = atoi(argv[i+2]);
        }
        else if(!flags.is4 && (strcmp(argv[i],"-t") == 0)){
            opc = opc + 2;
            flags.is4 = TRUE;
            flags.arg4 = argv[i+1];
        }
    }

    if (opc == argc - 1) {
        // No directory was specified.
        traverse_Directory(".", 0, &print_File);
    }
    else {
        // A directory was specified.
        traverse_Directory(argv[argc - 1], 0, &print_File);
    }

    return 0;
}