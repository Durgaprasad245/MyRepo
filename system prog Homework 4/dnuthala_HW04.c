#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define MAX_JOBS 5 

typedef struct {
    pid_t pid;
    char *program;
    char **arguments;
    char *out_file;
    char *err_file;
    time_t start_time;
    time_t end_time;
} Job;

Job running_jobs[MAX_JOBS];
int num_running_jobs = 0;
int job_counter = 0;

void submit_job(char *program, char *arguments[]);
void check_jobs();
void show_jobs();
void submit_history();

int main() {
    char input[100];
    char *token;
    char *args[20];

    while (1) {
        printf("Enter a command (submit/showjobs/submithistory/exit): ");
        fgets(input, sizeof(input), stdin);
        strtok(input, "\n"); 

        token = strtok(input, " ");
        if (strcmp(token, "submit") == 0) {
            char *program = strtok(NULL, " ");
            int i = 0;
            while ((token = strtok(NULL, " ")) != NULL) {
                args[i++] = token;
            }
            args[i] = NULL;
            submit_job(program, args);
        } else if (strcmp(token, "showjobs") == 0) {
            show_jobs();
        } else if (strcmp(token, "submithistory") == 0) {
            submit_history();
        } else if (strcmp(token, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
        
        check_jobs();
    }

    return 0;
}

void submit_job(char *program, char *arguments[]) {
    if (num_running_jobs < MAX_JOBS) {
        char out_file[20], err_file[20];
        snprintf(out_file, sizeof(out_file), "%d.out", job_counter);
        snprintf(err_file, sizeof(err_file), "%d.err", job_counter);
        pid_t pid = fork();
        if (pid == 0) {
            int out_fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
            int err_fd = open(err_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
            if (out_fd == -1 || err_fd == -1) {
                perror("Error opening output files");
                exit(EXIT_FAILURE);
            }
            if (dup2(out_fd, STDOUT_FILENO) == -1 || dup2(err_fd, STDERR_FILENO) == -1) {
                perror("Error redirecting output");
                exit(EXIT_FAILURE);
            }
            close(out_fd);
            close(err_fd);

            execvp(program, arguments);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            running_jobs[num_running_jobs].pid = pid;
            running_jobs[num_running_jobs].program = strdup(program);
            running_jobs[num_running_jobs].arguments = arguments;
            running_jobs[num_running_jobs].out_file = strdup(out_file);
            running_jobs[num_running_jobs].err_file = strdup(err_file);
            running_jobs[num_running_jobs].start_time = time(NULL);
            num_running_jobs++;
            printf("Job %d submitted.\n", job_counter++);
        } else {
            printf("Failed to fork process.\n");
        }
    } else {
        printf("Too many jobs running.\n");
    }
}

void check_jobs() {
    int i;
    for (i = 0; i < num_running_jobs; i++) {
        int status;
        pid_t result = waitpid(running_jobs[i].pid, &status, WNOHANG);
        if (result == -1) {
            printf("Error waiting for child process.\n");
        } else if (result > 0) {
            running_jobs[i].end_time = time(NULL);
            printf("Job %d completed.\n", i);
            free(running_jobs[i].program);
            free(running_jobs[i].out_file);
            free(running_jobs[i].err_file);
            free(running_jobs[i].arguments);
            memmove(&running_jobs[i], &running_jobs[i+1], (num_running_jobs - i - 1) * sizeof(Job));
            num_running_jobs--;
            i--;
        }
    }
}

void show_jobs() {
    int i;
    printf("Job ID\tStatus\n");
    for (i = 0; i < num_running_jobs; i++) {
        printf("%d\tRunning\n", i);
    }
}

void submit_history() {
    int i;
    printf("Submitted Jobs History:\n");
    printf("-------------------------------------------------------------------\n");
    printf("| Job ID | Program Name | Start Time       | End Time         | Status |\n");
    printf("-------------------------------------------------------------------\n");
    for (i = 0; i < num_running_jobs; i++) {
        char status_str[20];
        if (running_jobs[i].end_time == 0)
            strcpy(status_str, "Running");
        else
            strcpy(status_str, "Completed");
        printf("| %-6d | %-12s | %-16ld | %-16ld | %-6s |\n", i, running_jobs[i].program, running_jobs[i].start_time, running_jobs[i].end_time, status_str);
    }
    printf("-------------------------------------------------------------------\n");
}
