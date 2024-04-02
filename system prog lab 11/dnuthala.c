#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    double *a;
    double sum;
    int N;
    int size;
    long tid;
} ThreadArgs;

void *runner(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    int start = args->tid * args->size;
    int end = start + args->size;
    if (args->tid == args->N - 1) 
        end = args->N;

    args->sum = 0.0;
    for (int k = start; k < end; k++) {
        args->sum += args->a[k];
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <array size> <num of thrds>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]); 
    int n_thrds = atoi(argv[2]); 

    if (n_thrds > MAX_THREADS || n_thrds <= 0) {
        fprintf(stderr, "Invalid num of thrds (1 to %d allowed)\n", MAX_THREADS);
        exit(EXIT_FAILURE);
    }

    pthread_t threads[n_thrds];
    ThreadArgs thread_args[n_thrds];

    double *a = (double *)malloc(N * sizeof(double));
    for (int k = 0; k < N; k++) {
        a[k] = k + 1; 
    }

    int size = N / n_thrds;

    for (long k = 0; k < n_thrds; k++) {
        thread_args[k].a = a;
        thread_args[k].N = N;
        thread_args[k].size = size;
        thread_args[k].tid = k;

        pthread_create(&threads[k], NULL, runner, (void *)&thread_args[k]);
    }

    for (int k = 0; k < n_thrds; k++) {
        pthread_join(threads[k], NULL);
    }

    double total_sum = 0.0;
    for (int k = 0; k < n_thrds; k++) {
        total_sum += thread_args[k].sum;
    }

    printf("Total sum: %.2f\n", total_sum);

    free(a);
    pthread_exit(NULL);
}
