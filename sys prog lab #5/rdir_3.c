/* Sample C program to illustrate the use of opendir, readdir, and closedir
 * system calls. 
 * This version prints the file type next to the file name.
 */
#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

char *filetype(unsigned char type) {
  char *str;
  switch(type) {
  case DT_BLK: str = "block device"; break;
  case DT_CHR: str = "character device"; break;
  case DT_DIR: str = "directory"; break;
  case DT_FIFO: str = "named pipe (FIFO)"; break;
  case DT_LNK: str = "symbolic link"; break;
  case DT_REG: str = "regular file"; break;
  case DT_SOCK: str = "UNIX domain socket"; break;
  case DT_UNKNOWN: str = "unknown file type"; break;
  default: str = "UNKNOWN";
  }
  return str;
}

void read_all_dirs(char *path, int depth) {
    struct dirent *dirent; 
    DIR *dir; 
    dir = opendir (path); 
    if (dir == NULL) { 
        printf ("Error opening directory '%s'\n", path); 
        exit (-1);
    } 
    int count = 1; 
    while((dirent = readdir(dir)) != NULL) {
      if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) continue;
      for (int i = 0; i < depth; i++) printf(" ");
      printf("[%d] %s (%s)\n", count, dirent->d_name, filetype(dirent->d_type));
      count++;
      if(strcmp(filetype(dirent->d_type), filetype(DT_DIR)) == 0) {
        char *sub_path = (char*)malloc(sizeof(path) + sizeof(dirent->d_name) + 3 + depth);
        strcpy(sub_path, path);
        strcat(sub_path, "/");
        strcat(sub_path, dirent->d_name);
        read_all_dirs(sub_path, depth + 2);
        free(sub_path);
      }
    } 
    closedir (dir);
}

int main (int argc, char **argv) { 
  if (argc < 2) { 
    printf ("Usage: %s <dirname>\n", argv[0]); 
    exit(-1);
  } 
  read_all_dirs(argv[1], 0);
  return 0; 
} 

