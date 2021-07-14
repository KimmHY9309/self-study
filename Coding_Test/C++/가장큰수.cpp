#include <string>
#include <vector>
#include <algorithm> // sort
#include <sstream>   // int -> string
using namespace std;

struct num{
    int num2; // numbers
    int cmp;  // 가치
};

// 구조체 비교를 위한 비교함수
// 가치가 높은 순으로 내림차순
bool cmpa(const num &p1, const num &p2){
    if(p1.cmp > p2.cmp){
        return true;
    }
    else{
        return false;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // numbers의 값(num2) + 값의 가치(cmp) 구조체 생성
    int n = numbers.size();
    num a[n];
    
    // 접근방법
    // 자릿수가 같으면 크기가 큰 수를 가장 앞쪽에 붙일 것이다
    // 9와 99, 999는 각각 같은 가치를 지닌다고 추측
    // 마찬가지로 30과 3030, 786과 786786은 같은 가치를 지닐 것이다
    // 따라서 모든 정수를 같은 자리수로 만든 후(6자리) 정렬한다
    for(int i = 0; i < n; i++)
    {
        a[i].num2 = numbers[i];
        if ( numbers[i] < 10 ) a[i].cmp =  numbers[i]*111111;
        else if ( numbers[i] < 100 ) a[i].cmp = numbers[i]*10101;
        else if ( numbers[i] < 1000 ) a[i].cmp = numbers[i]*1001;
        else a[i].cmp = 1000;     // 4자리수는 1000뿐이고 1000은 가장 낮은 가치를 지닌다
    }
    sort(a, a+n, cmpa); // 가치로 정렬
    
    //  순서대로 int -> string 변환 후 이어 붙인다.
    for (int i = 0; i < n ; i++)
    {
      stringstream ssInt; 
      ssInt << a[i].num2;              
      answer += ssInt.str();
    }
    
    // 모든 numbers가 0이면 answer가 '000...00'이 되는데 '0'으로 나와야 정답인 듯(test11)
    if ( a[0].num2 == 0 ) answer = "0";
    return answer;
}
