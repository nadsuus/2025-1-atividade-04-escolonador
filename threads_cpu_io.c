#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <math.h>

// Thread CPU-bound (cálculos intensivos)
void* cpu_thread(void* arg) {
    long id = (long)arg;
    printf("Thread CPU-bound %ld iniciada (PID: %d)\n", id, getpid());

    // Cálculo de π: π/4 = 1 - 1/3 + 1/5 - 1/7 + ...
    long iterations = 100000000;  // ajuste conforme seu container aguenta
    double sum = 0.0;
    for (long i = 0; i < iterations; i++) {
        double term = (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
        sum += term;
    }
    double pi = sum * 4.0;

    printf("Thread CPU-bound %ld terminou (π ≈ %.6f)\n", id, pi);
    return NULL;
}

// Thread I/O-bound (simula espera)
void* io_thread(void* arg) {
    long id = (long)arg;
    printf("Thread I/O-bound %ld iniciada (PID: %d)\n", id, getpid());
    sleep(2);  // Simula operação I/O
    printf("Thread I/O-bound %ld terminou\n", id);
    return NULL;
}

int main() {
    pid_t pid;
    // Declarações de threads CPU-bound (3)
    pthread_t thread_cpu1, thread_cpu2, thread_cpu3;
    // Declarações de threads I/O-bound (3)
    pthread_t thread_io1, thread_io2, thread_io3;

    // Cria processo filho
    pid = fork();

    if (pid == 0) { // Processo filho
        printf("\nProcesso filho (PID: %d)\n", getpid());
        
        // Cria threads CPU-bound
        pthread_create(&thread_cpu1, NULL, cpu_thread, (void*)1);
        pthread_create(&thread_cpu2, NULL, cpu_thread, (void*)2);
        pthread_create(&thread_cpu3, NULL, cpu_thread, (void*)3);
        
        // Cria threads I/O-bound
        pthread_create(&thread_io1, NULL, io_thread, (void*)1);
        pthread_create(&thread_io2, NULL, io_thread, (void*)2);
        pthread_create(&thread_io3, NULL, io_thread, (void*)3);
        
        // Espera todas as threads terminarem
        // Aguarda CPU-bound
        pthread_join(thread_cpu1, NULL);
        pthread_join(thread_cpu2, NULL);
        pthread_join(thread_cpu3, NULL);

        // Aguarda I/O-bound
        pthread_join(thread_io1, NULL);
        pthread_join(thread_io2, NULL);
        pthread_join(thread_io3, NULL);

    } else if (pid > 0) { // Processo pai
        printf("Processo pai (PID: %d)\n", getpid());
        wait(NULL); // Espera filho terminar
    }

    return 0;
}
