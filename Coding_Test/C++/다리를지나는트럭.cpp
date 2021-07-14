#include <string>
#include <vector>
#include <queue> // FIFO

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; // time
    
    queue<pair<int,int>> on_bri; // first -> truck number , second -> time on the bridge
    int sum_w = 0;
    int truck_number = 0;
    
    while(1){
        answer++; // 시간 증가
        
        // (현재 시간 - 트럭이 다리에 올라간 시간) == 다리의 길이 -> 다리를 다 건넘
        // 다리 위의 총 무게에서 트럭의 무게롤 빼고 트럭을 pop
        if(answer - on_bri.front().second == bridge_length){
            sum_w -= truck_weights[on_bri.front().first];
            on_bri.pop();
        } 
        
        // 현재 총 무게에서 다음 트럭의 무게를 더했을 때 하중보다 작은 경우
        // 다음 트럭을 push하고 그 때의 시간을 기억한다(second)
        if(sum_w + truck_weights[truck_number] <= weight && truck_number < truck_weights.size() ){
            on_bri.push(make_pair(truck_number,answer));
            sum_w += truck_weights[truck_number];
            truck_number++;
        }
        if(on_bri.empty()) break;
    }
    return answer;
}
