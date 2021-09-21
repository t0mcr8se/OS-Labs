// Compile: gcc -pthread -o ex1.out ex1.c
#include <stdio.h>
#include <pthread.h>

#define N 20

void print(int x) {
    printf("Hello from thread #%d\n", x);
    pthread_exit(0);
}

int main(int argc, char* argv[]) {
    pthread_t _thread;

    for (int i = 0; i < N; i++) {
        pthread_create(&_thread, NULL, &print, i);
        pthread_join(_thread, NULL);
    }
    return 0;
}
