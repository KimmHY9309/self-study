#include <string>
#include <vector>
#include <sstream> // int -> stirng을 위한 헤더파일

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    for(int i = 0, n = seoul.size(); i < n; i++)
    {
        if (seoul[i].compare("Kim") == 0) // seoul 벡터에서 Kim을 찾는다(compare는 같으면 0반환)
        {
           answer = "김서방은 ";
           std::stringstream ssInt; //
           ssInt << i;              // 
           answer += ssInt.str();   // int형 i를 string으로 변환하고 answer에 추가
           answer += "에 있다";
        }
    }
    return answer;
}
