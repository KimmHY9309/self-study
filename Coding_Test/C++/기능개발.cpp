#include <string>
#include <vector>
#include <queue>  // First In First Out 이므로 queue를 사용한다

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
   
    queue<int> needay; // 작업별로 개발에 필요한 날짜 수
    for(int i = 0, n = progresses.size(); i < n; i++){
       if((100-progresses[i])%speeds[i] == 0) needay.push((100-progresses[i]) / speeds[i]);
       else needay.push(1 + (100-progresses[i])/speeds[i]);
    }
    
    // 배포가 되려면 가장 앞에 있는 기능이 개발이 완료되어야 하므로 front를 기준으로 날짜를 정한다
    int day = needay.front();
    int baepo = 0;
    while(!needay.empty()){
        if(day >= needay.front())
        {
            baepo++;
            needay.pop();
        }
        else{
            answer.push_back(baepo);
            baepo = 0;
            day = needay.front();
        }
    }
    answer.push_back(baepo);
    
    return answer;
}
