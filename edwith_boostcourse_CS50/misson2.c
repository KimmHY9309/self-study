#include <stdio.h>
#include <stdlib.h>

int *divisor;

int
compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int
main()
{
    int N;
    scanf("%d", &N);
    
    divisor = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        int tmp;
        scanf("%d", &tmp);
        divisor[i] = tmp;
    }

    qsort(divisor, N, sizeof(int), compare);

    int answer = divisor[0]*divisor[N-1];;
    printf("%d\n", answer);

    return 0;
}
