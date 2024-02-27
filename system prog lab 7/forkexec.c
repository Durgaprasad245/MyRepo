#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    FILE *output_log = fopen("output.log", "w");
    if (output_log == NULL) {
        perror("Error opening log file");
        fclose(input_file);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    while (fgets(command, sizeof(command), input_file)) {
        // Remove trailing newline character
        command[strcspn(command, "\n")] = 0;

        time_t start_time;
        time(&start_time);

        pid_t pid = fork();
        if (pid == -1) {
            perror("Error forking process");
            fclose(input_file);
            fclose(output_log);
            return 1;
        } else if (pid == 0) { // Child process
            execlp(command, command, NULL);
            perror("Error executing command");
            fclose(input_file);
            fclose(output_log);
            exit(1);
        } else { // Parent process
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                time_t end_time;
                time(&end_time);

                fprintf(output_log, "%s\t%s\t%s\n", command, ctime(&start_time), ctime(&end_time));
            } else {
                fprintf(output_log, "%s\tCommand failed\n", command);
            }
        }
    }

    fclose(input_file);
    fclose(output_log);

    return 0;
}
