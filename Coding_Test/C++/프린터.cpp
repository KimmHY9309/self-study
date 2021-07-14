#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    int n2 = priorities.size();
    while(!priorities.empty()){
        
        // 가장 앞에 있는 문서를 대기목록에서 꺼낸다
        int temp = priorities.front();
        priorities.erase(priorities.begin());
        
        // 나머지 대기목록과 비교
        for(int i = 0, n = priorities.size(); i < n; i++){
            // 중요도가 더 높은 문서가 남아있다면
            if(temp < priorities[i]) 
            {
                // 제일 뒤로 보낸다
                priorities.push_back(temp);
                if (location == 0) location = n+1;
                break;
            }
        }
        if(location == 0) return n2-priorities.size();
        location--;
    }
}
