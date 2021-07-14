//#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
    char yoil[9]; 
    //입력받은 문자를 저장
    
    while(1){//여러번 확인하려고 반복했습니다.
       
        printf("요일을 입력하세요 : ");
        scanf("%s",yoil); // 입력받은 문자를 저장

        if (strcmp(yoil,"월요일") == 0) printf("월요일 : 청국장\n");  // strcmp는 문자열을 비교하는 함수입니다.
                                                                     // 두 문자열이 같으면 0을 return합니다.
        else if(strcmp(yoil,"화요일")==0) printf("화요일 : 비빔밥\n");
        else if(strcmp(yoil,"수요일")==0) printf("수요일 : 된장찌개\n");
        else if(strcmp(yoil,"목요일")==0) printf("목요일 : 칼국수\n");
        else if(strcmp(yoil,"금요일")==0) printf("금요일 : 냉면\n");
        else if(strcmp(yoil,"토요일")==0) printf("토요일 : 소불고기\n");
        else if(strcmp(yoil,"일요일")==0) printf("일요일 : 오삼불고기\n");
        else 
        {
            printf("'O요일'로 입력해주세요\n");
            break; // 다른 입력이 오면 종료
        }
    }
}
