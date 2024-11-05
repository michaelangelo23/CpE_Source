#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    unsigned long long start;
    unsigned long long end;
} Range;

void* collatz(void* arg) {
    Range* range = (Range*) arg;
    for (unsigned long long i = range->start; i <= range->end; i++) {
        unsigned long long current = i;
        while (current != 1) {
            if (current % 2 == 0) {
                current /= 2;
            } else {
                current = (3 * current) + 1;
            }
        }
        printf("Number %llu reached 1\n", i);
    }
    return NULL;
}

int main() {
    unsigned long long min, max;
    int num_threads = 4; // Number of threads to use

    printf("Enter minimum number: ");
    scanf("%llu", &min);
    printf("Enter maximum number: ");
    scanf("%llu", &max);

    if (min > max) {
        printf("Minimum should be less than maximum\n");
        return 1;
    }

    pthread_t threads[num_threads];
    Range ranges[num_threads];
    unsigned long long range_size = (max - min + 1) / num_threads;

    for (int i = 0; i < num_threads; i++) {
        ranges[i].start = min + i * range_size;
        ranges[i].end = (i == num_threads - 1) ? max : (ranges[i].start + range_size - 1);
        pthread_create(&threads[i], NULL, collatz, &ranges[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}