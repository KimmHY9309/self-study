#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a1[5] = {1,2,3,4,5},           aa1 = 0;
    int a2[8] = {2,1,2,3,2,4,2,5},     aa2 = 0;
    int a3[10]= {3,3,1,1,2,2,4,4,5,5}, aa3 = 0;
    
    for(int i = 0, n = answers.size(); i < n ; i++)
    {
        if( a1[i%5]  == answers[i] ) aa1++;
        if( a2[i%8]  == answers[i] ) aa2++;
        if( a3[i%10] == answers[i] ) aa3++;
    }
    
    int max = 0;
    if ( max < aa1 ) max = aa1;
    if ( max < aa2 ) max = aa2;
    if ( max < aa3 ) max = aa3;
    
    if ( max == aa1 ) answer.push_back(1);
    if ( max == aa2 ) answer.push_back(2);
    if ( max == aa3 ) answer.push_back(3);
    
    return answer;
}
