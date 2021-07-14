#include <string>
#include <vector>
#include <math.h>    // sqrt
#include <algorithm> // sort
#include <set>       // set
#include <iostream>  // printf
using namespace std;

int solution(string numbers) {
    int answer = 0;
    bool isPrime(int number);
 
    sort(numbers.begin(), numbers.end());
    int length = numbers.size();
    
    string subnum = ""; // 123이 있다 치면 1,12,123 다 확인해야 하므로 짜른다
    set<int> prime;     // 중복 제거

    do{
        for(int i = 1; i <= length; i++)
        {
            subnum = numbers.substr(0,i); 
            if (isPrime(stoi(subnum)))  prime.insert(stoi(subnum));
            
            // 0(처음)부터 i(1,2,...,7)글자만큼 짜르겠다는 의미
            // 짜른 글자를 숫자로 바꿔서(stoi) 소수인지 판별하고(ipPrime)
            // 맞으면 prime set에 추가
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    // 순열에 따라 반복하여 모든 경우의 수를 확인
    
    answer = prime.size();
    return answer;
}

// 소수인지 판별하는 함수
bool isPrime(int number){
    if(number == 2 || number == 3) return true;
    else if(number == 0 || number == 1 || number % 2 == 0 || number % 3 == 0 ) return false;
    else {
        // 루트n 까지만 나눠보면 됨
        for (int i = 2, n = sqrt(number); i <= n; i++ )
        {
            if ( number % i == 0 ) return false;
        }
        return true;
    }
}
