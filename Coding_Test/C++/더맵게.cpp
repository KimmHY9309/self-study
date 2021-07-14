#include <string>
#include <vector>

using namespace std;

template<typename T>
class Heap{
private:
    int sz;
    T *arr;
    
    void push_swap(int cld){
        if (cld == 1) return; // 첫 원소일 경우 그냥 넣음
        
        int par = cld / 2;    // 이진트리에서 부모와 자식 노드는 K 와 (2K, 2K+1)의 관계가 있다
        
        // 작은 값을 위로 올려줌(최소힙)
        if(arr[par] > arr[cld]){
            T tmp = arr[cld];
            arr[cld] = arr[par];
            arr[par] = tmp;
        
            // 위 노드에서도 반복. 재귀함수
            push_swap(par);
        }
    }
    
    void pop_swap(int par){
        // 자식 노드가 없는 경우를 -1로 표현
        int left,right,child;
        left = (par * 2 <= sz ? par * 2 : -1);
        right = (par * 2 + 1<= sz ? par * 2 + 1 : -1);
        
        
        if(left == -1 && right == -1) child = -1;         // 자식이 둘 다 X
        else if(left != -1 && right == -1) child = left;  // 하나만 있는 경우(left)
        else if(left != -1 && right != -1) child = (arr[left] < arr[right] ? left : right); // 둘 다 있다면 그 중 작은값(최소힙)
        
        if(child == -1) return;
        
        // 큰 값을 밑으로 내려줌(최소힙)
        if(arr[child] < arr[par]) {
            T temp = arr[child];
            arr[child] = arr[par];
            arr[par] = temp;
            
            // 밑 노드에서도 반복
            pop_swap(child);
        }
    }
public:
    // 생성자
    Heap(int n){
        sz = 0;
        arr = new int[n+1];
    }
    // new가 그룹이므로 delete 할 때 [] 해줘야함
    ~Heap(){
        delete[] arr;
    }
    bool empty(){
        return !sz ? true : false;
    }
    int size(){
        return sz;
    }
    // root값 반환
    T top(){
        return !sz ? -1 : arr[1];
    }
    
    void push(int val){
        arr[++sz] = val; // 전위증감. sz 증가시키고 사용
        push_swap(sz);   // 배열의 마지막에 값을 넣고 정렬
    }
    void pop(){
        if(sz == 0) return; // 비어있음
        
        arr[1] = arr[sz--]; // 후위증감. 사용한 후 sz 감소
        pop_swap(1);        // 마지막 원소로 root를 덮고 정렬
    }
};
int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // 이진트리 구성
    int n = scoville.size();
    Heap<int> sco(n);
    for(int i = 0; i < n; i++){
        sco.push(scoville[i]);
    }
    
    while(1){
        int temp = sco.top();
        if(temp < K){
            if(sco.size() == 1) return -1; // 모든 음식을 섞어도 스코빌 지수가 K보다 작은 경우
            
            // 두 음식을 섞고 새로운 음식을 만들어 넣음
            sco.pop();
            temp += sco.top()*2;
            sco.pop();
            sco.push(temp);
            answer++; // 섞은 횟수
        }
        else break; // 모든 음식이 K이상인 경우 종료
    }
    return answer;
}
