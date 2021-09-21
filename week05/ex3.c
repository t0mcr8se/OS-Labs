#include <stdio.h>
#include <pthread.h>

#define ever (;;)
const int PRINT_INTERVAL = 5e6;

int sharedArray[1000];
int sharedCnt = 0;

int c_flag = 0;
int p_flag = 0;

void _sleep(int *flag){
    while(*flag) { }
}

void printStatus(int i){
    if(i % PRINT_INTERVAL == 0)
        printf("%d\n", sharedCnt);
}

void consumer() {
    for(int i=0 ; ; i++) {
        _sleep(&c_flag);
        printStatus(i);
        if (sharedCnt < 1000) {
            sharedCnt++;
            sharedArray[i % 1000] = i;
            p_flag = 0;
        } else {
            c_flag = 1;
        }
    }
}

void producer() {
    for(int i=0 ; ; i++) {
        _sleep(&p_flag);
        printStatus(i);
        if (sharedCnt > 0) {
            sharedCnt--;
            c_flag = 0;
            sharedArray[i % 1000] = i;
        } else {
            p_flag = 1;
        }
    }
}

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, &producer, NULL);
    pthread_create(&tid, NULL, &consumer, NULL);

    pthread_join(tid, NULL);
}
