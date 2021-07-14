#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    void bubble_sort(int list[],int n); // 정렬하는 함수. 아래에 정의

    int input1[] = {1,2,3,4,5} , input2[] = {5,4,3,2,1}; // 비교할 문자열 (예1)
    bubble_sort(input1, 5);  bubble_sort(input2, 5);     // 두 문자열을 각각 크기에 따라 정렬한다
    if (input1[0] == input2[0] && input1[1] == input2[1] && input1[2] == input2[2] && input1[3] == input2[3] && input1[4] == input2[4]) printf("True\n");
    else printf("False\n");
    // 정렬한 두 문자열이 같을 경우 anagram
    // 배열을 비교할 때 하나하나 비교하는 것이 비효율적인 것 같은데 더 나은 방법이 떠오르지 않네요 ㅜㅜ

    int input3[] = {1,4,2,5,8} , input4[] = {2,5,4,3,1}; // 비교할 문자열 (예2)
    bubble_sort(input3, 5);  bubble_sort(input4, 5); 
    if (input3[0] == input4[0] && input3[1] == input4[1] && input3[2] == input4[2] && input3[3] == input4[3] && input3[4] == input4[4]) printf("True\n");
    else printf("False\n");
    // 정렬한 두 문자열이 다를 경우 anagram X

    int input5[] = {1,1,1,3,2} , input6[] = {2,1,1,3,1}; // 비교할 문자열 (예1)
    bubble_sort(input5, 5);  bubble_sort(input6, 5);     // 두 문자열을 각각 크기에 따라 정렬한다
    if (input5[0] == input6[0] && input5[1] == input6[1] && input5[2] == input6[2] && input5[3] == input6[3] && input5[4] == input6[4]) printf("True\n");
    else printf("False\n");
    // 정렬한 두 문자열이 같을 경우 anagram
}

void bubble_sort(int list[], int n){
  int i, j, temp;

  for(i=n-1; i>0; i--){
    // 0 ~ (i-1)까지 반복
    for(j=0; j<i; j++){
      // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
      if(list[j]<list[j+1]){
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}
