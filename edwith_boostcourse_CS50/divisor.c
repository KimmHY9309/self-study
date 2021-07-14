#include <stdio.h>
#include <stdlib.h>

int *divisor;

int
compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
} // qsort를 위한 비교

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
    //http://www.cplusplus.com/reference/cstdlib/qsort/
    //정렬 할 배열의 첫 번째 개체에 대한 포인터로 void*.
    //base가 가리키는 배열의 요소 수 . size_t 부호없는 정수 유형입니다.
    //배열에있는 각 요소의 크기 (바이트)입니다. size_t 부호없는 정수 유형입니다.
    //두 요소를 비교하는 함수를 가리키는 포인터. 이 함수는 다음에 의해 반복적으로 호출됩니다.qsort두 요소를 비교합니다. 다음 프로토 타입을 따릅니다.
    //<0	가리키는 요소 (P1)는 요소가가 가리키는 전에 간다 (P2)
    // 0	가리키는 소자 (P1)는 요소가 가리키는 동등 P2
    //>0	가리키는 요소 (P1)는 요소가가 가리키는 후 간다 (P2)

    int answer = divisor[0]*divisor[N-1];;
    printf("%d\n", answer);

    return 0;
}
