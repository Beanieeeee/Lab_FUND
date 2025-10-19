#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "func.h"


int main() {
    int n;
    printf("Введите количество запросов: ");
    scanf("%d", &n);

    int* queries = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &queries[i]);
    }

    int maax = found_max(queries, n);         
    int* primes = malloc(maax * sizeof(int));  
    check_prost_or_not(primes, maax);          

    print_num(primes, queries, n);             

    free(queries);
    free(primes);
    return 0;
}
