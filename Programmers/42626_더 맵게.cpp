#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int cnt = 0; 
    
    priority_queue<int> pq; 
    for(auto e: scoville){
        pq.push(-e); // 최소 힙 
    }
    
    while(-pq.top() < K){
        if(pq.size() == 1) return -1; 
        
        int first = -pq.top();
        pq.pop();
        int second = -pq.top();
        pq.pop();

        int newScoville = first + second * 2;
        cnt++; 
        pq.push(-newScoville);  
    }
    
    return cnt; 
}