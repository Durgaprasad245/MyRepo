#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handle_interrupt(int sig) {
    printf("Child process interrupted (Ctrl+C)\n");
}

void handle_suspend(int sig) {
    printf("Child process suspended (Ctrl+Z)\n");
}

int main(int argc, char *argv[]) {
    pid_t child_ppid;

    signal(SIGINT, handle_interrupt);  
    signal(SIGTSTP, handle_suspend); 

    child_ppid = fork();

    if (child_ppid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (child_ppid == 0) { 
        if (execvp(argv[1], &argv[1]) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } 
    else { 
        printf("Child processs id: %d\n", child_ppid);
        printf("Parent processs is waiting...\n");
        wait(NULL); 
        printf("Child process finished.\n");

        
        signal(SIGQUIT, SIG_IGN); 
        printf("press ctrl+\\ to quit.\n");
        while (getchar() != '\\'); 
        printf("Quit signal received. Parent process exiting.\n");
    }

    return 0;
}
