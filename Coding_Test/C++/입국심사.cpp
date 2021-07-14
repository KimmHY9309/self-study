#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0;
    long long right = 1000000000000000000;
    // 걸리는 시간은 0과 1,000,000,000*1,000,000,000 사이에 있을 것이다
    // binary search로 최솟값을 찾아보자
    
    while(left <= right)
    {
        long long mid = (left + right)/2;
        long long n2 = 0;
        
        // 어떤 시간값을(mid) 넣었을 때 모든 사람이 심사를 받을 수 있는지 확인
        // -> 각 심사관마다 심사할 수 있는 사람의 수를 합쳤을 때 전체 사람보다 많으면 됨
        for(int i = 0, n = times.size(); i < n; i++)
        {
           n2 += (mid/times[i]);
        }
        if(n2 >= n)
        {
            answer = mid;    // 이 시간은 합격
            right = mid - 1; // 하지만 최솟값을 찾아야 하므로 더 작은 시간을 알아보자
        }
        else left = mid + 1; // 이 시간은 불합격, 더 큰 시간을 알아보자
    
    }
    return answer;
}
