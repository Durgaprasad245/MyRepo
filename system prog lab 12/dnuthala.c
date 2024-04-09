#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_OUTPUT_LENGTH 4096

int main() {
    char command[MAX_COMMAND_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    while (1) {
        printf("Enter command: ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            fprintf(stderr, "Error reading command.\n");
            continue;
        }

        // Removing newline
        command[strcspn(command, "\n")] = '\0';

        // Checking for "quit" cmd to exit the code
        if (strcmp(command, "quit") == 0) {
            printf("Exiting program...bye!\n");
            break;
        }

        // Open pipe to execute the cmd
        FILE *fp = popen(command, "r");
        if (fp == NULL) {
            fprintf(stderr, "Error executing command.\n");
            continue;
        }

        // Reading o/p from the command
        if (fgets(output, sizeof(output), fp) == NULL) {
            fprintf(stderr, "Error reading command output.\n");
            pclose(fp);
            continue;
        }

        // Printing o/p to terminal
        printf("%s", output);

        // Closing pipe
        pclose(fp);
    }

    return 0;
}
