#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 한 변의 길이(x)는 3과 1251 사이에서 임의로 정한다
    // 다른 변의 길이(y)는 x, brown 값으로 구할 수 있다.
    // 구한 x, y가 yellow의 조건도 만족 하는지 확인한다.
    for(int x = 3; x <= 1251; x++)
    {
        int y = 2 + (brown - 2*x)/2;
        if ( yellow == (x-2)*(y-2) ){
            answer.push_back(y);
            answer.push_back(x);
            break;
        }
    }
    return answer;
}
