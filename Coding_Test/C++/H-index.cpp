#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.rbegin(),citations.rend()); // re로 하면 내림차순으로 정렬이 된다.
    int n = citations.size();
    for(int i = 0; i <n; i++)
    {
        if (citations[i] >= i+1) answer = i+1; 
    }
    // 처음엔 인용횟수(citations[i])가 인용편수(i+1)보다 작거나 같을 때 citations를 return했는데
    // [6,5,5,5,3] 이라고 치면 3이 return 됨
    // 5번 이상 인용 된게 4개고 3편이상 인용 된게 5니까 h-index가 3이라고 생각했는데
    // 4번 이상 인용 된게 4편이기 때문에 실제 h-index는 4인거임
    
    return answer;

}
