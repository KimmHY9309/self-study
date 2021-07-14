#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // <의상의종류, 의상의개수> map 생성
    map<string,int> clothes2;
    
    // 종류에 따른 개수 구하기
    for(int i = 0, n = clothes.size(); i < n; i++){
        auto itr = clothes2.find(clothes[i][1]);                                // 의상 종류를 찾고
        if(itr == clothes2.end()) clothes2.insert(make_pair(clothes[i][1],1));  // 없으면 새로 만들고
        else itr->second++;                                                     // 있으면 개수 증가
    }
    
    // 전체 경우의 수 = (의상1 개수 + 안 입는 경우) X (의상2 + 안 입) X ... X (...) - 1(전부 안 입는 경우 제외)
    for(auto itr = clothes2.begin(); itr != clothes2.end(); ++itr)
    {
        answer = answer * ((itr->second)+1);
    }
    return answer-1;
}
