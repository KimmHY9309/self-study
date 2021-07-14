#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sortarr;  // 배열을 i부터 j까지 자른걸 넣기 위한 변수

    // k번 진행
    for(int k = 0, m = commands.size(); k < m; k++){ 
      for(int i = commands[k][0]-1; i < commands[k][1]; i++)
      {
          int b = 0; // for문 시간절약을 위해 추가
          
          // array의 i번째 숫자부터 sortarr에 집어넣기 시작
          // 그러면서 앞의 숫자와 비교해서 작으면 더 안 쪽으로 집어 넣는다(정렬)
          sortarr.push_back(array[i]); 
          for (int j = sortarr.size()-1; j > 0 && b==0;j--){
             if ( sortarr[j] < sortarr[j-1])
             {
               int tmp = sortarr[j];
               sortarr[j] = sortarr[j-1];
               sortarr[j-1] = tmp;   
             }
             else b = 1; // 작은 수를 왼쪽으로 보내고 있기 때문에 교환이 일어나지 않으면 정렬 완료
          }
      }
        
      // k번째 있는 수를 answer에 집어 넣는다.
      // sortarr는 재활용 할거라 clear
      answer.push_back(sortarr[commands[k][2]-1]);
      sortarr.clear();
    }
    return answer;
}
