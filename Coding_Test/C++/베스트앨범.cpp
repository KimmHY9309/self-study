#include <string>
#include <vector>
#include <map>       // map
#include <algorithm> // sort
using namespace std;

// 장르와 총 재생수
struct gepl{
  int i;
  string str;
};

// 구조체 비교인자
bool comp(gepl A, gepl B){
    return A.i > B.i;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // key : 장르 , value 재생수의 합
    map<string,int> hash_map;
    for(int i = 0, n = genres.size(); i < n; i++){
        hash_map[genres[i]] += plays[i];
     }
    
    // 정렬하기 위해서 map을 vector로 옮김
    vector<gepl> v;
    gepl Gepl;
    for(auto itr = hash_map.begin(); itr != hash_map.end(); ++itr)
    {
        Gepl.i = itr->second;
        Gepl.str = itr->first;
        v.push_back(Gepl);
    }
    sort(v.begin(),v.end(),comp);
   
    // 1번기준 -> 정렬된 vector의 장르 순서대로 수록
    // 2번기준 -> 같은 장르(genres)의 재생수 높은 두 곡(plays)을 찾는다       
    for(int j = 0, m = v.size(); j < m; j++){
       int max1 = 0;
       int itr1 = -1;
       int max2 = 0;
       int itr2 = -1;
       for(int i = 0, n = genres.size(); i < n; i++){
            if(genres[i] == v[j].str) {
                if(plays[i] > max1) {
                    max2 = max1;
                    itr2 = itr1;
                    max1 = plays[i];
                    itr1 = i;
                }
                else if(plays[i] > max2) 
                {
                    max2 = plays[i];
                    itr2 = i;
                }
            }
        }
        answer.push_back(itr1);
        if(itr2 != -1) answer.push_back(itr2); // 장르의 곡이 한 곡일경우
    }
    return answer;
}
