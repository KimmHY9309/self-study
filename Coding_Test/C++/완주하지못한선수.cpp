#include <string>
#include <cstring>  // strcmp
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 참여자와 완주자를 이름순으로 정렬한다
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    // 하나씩 서로 비교해보고 다른 이름이 나오면 미완주자
    // 완주자 수만큼 비교하고 모두 같으면 마지막 참여자가 미완주자
    for(int i = 0, n = completion.size(); i < n; i++){
        if(strcmp(participant[i].c_str(),completion[i].c_str()) != 0){
            answer = participant[i];
            break;
        }
    }
    if (answer.empty()) answer = participant.back();
    
    return answer;
}
