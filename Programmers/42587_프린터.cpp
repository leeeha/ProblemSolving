#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {    
    queue<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); i++){
        q.push({priorities[i], i}); // 우선순위, 인덱스 
    }
    
    priority_queue<int> pq; 
    for(auto e: priorities){ // 기본적으로 최대 힙 
        pq.push(e); // 내림차순 
    }
    
    int num = 0; 
    while(!q.empty()){
        int priority = q.front().first; 
        int index = q.front().second; 
        
        if(priority == pq.top()){ 
            pq.pop(); 
            q.pop(); 
            num++; // 출력한 인쇄물의 개수 갱신 
            
            // location 위치의 원소는 몇번째로 출력하는지 리턴 
            if(index == location) return num; 
        }else{
            q.pop(); 
            q.push({priority, index}); 
        }
    }
}