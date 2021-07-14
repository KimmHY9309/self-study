#include <string>
#include <vector>
#include <math.h> // pow 함수를 쓰기 위한 헤더파일(지수 계산)

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    // 접근 방법
    // 정수 n을 자리수에 따라 분리한 후
    // 새로운 벡터에 집어 넣는 동시에 정렬을 하고
    // 벡터내 정렬된 숫자들에 다시 자리수를 곱해 정수형태로 리턴한다.
 
    vector<int> ans; // 분리하는 정수를 저장할 공간
    while( n != 0 ) // n을 10으로 계속 나눈다
    {
        int b = 0; // for문 시간절약을 위해 생성한 변수(실제 효과가 있는지 확실하지 않음)
        if(ans.size() == 0) ans.push_back( n%10 ); // 비교대상x. 
        else
        {
            ans.push_back( n%10 ); // n을 10으로 나눈 나머지는 1의자리 숫자일 것이다
            for (int i = ans.size()-1; i > 0 && b == 0; i--) 
            {
                if (ans[i] < ans[i-1]) 
                {
                    int tmp = ans[i];
                    ans[i] = ans[i-1];
                    ans[i-1]= tmp;
                } 
                // 방금 들어온 숫자와 바로 앞 숫자를 비교해 더 작다면 안쪽으로 들어가는 것을 반복한다.
                
                else b = 1;
                // 만약 앞의 숫자가 나보다 작다면(교환이 일어나지 않는다면) for문 중단(이미 정렬 완)
            }
        }
        n = n/10; // n을 10으로 나눈 몫으로 다음 n이 만들어지므로 1의자리 숫자만 분리하는 효과가 있다.
    }
    for (int i = 0; i < ans.size();i++)
    {
       answer += ans[i]*pow(10,i);
    }
    // 벡터를 정수형태로 표현한다
    
    return answer;
}
