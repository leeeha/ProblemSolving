#include <string>
#include <vector>
#include <queue> 
#include <iostream>
#include <algorithm> 
using namespace std;

// 요청 시간 기준 오름차순 정렬 
bool cmp1(vector<int> a, vector<int> b){
    return a[0] < b[0]; 
}

// 소요 시간 기준 오름차순 정렬 
struct cmp2 {
    bool operator() (vector<int> a, vector<int> b){
        return a[1] > b[1]; 
    }
}; 

int solution(vector<vector<int>> jobs) {
    // answer는 각 작업의 요청부터 종료까지 걸린 시간의 합
    int answer = 0, i = 0, time = 0;
    
    // 요청 시간 기준 오름차순 정렬 
    sort(jobs.begin(), jobs.end(), cmp1);
    
    // 소요 시간 기준 오름차순 정렬 (최소 힙)
    priority_queue<vector<int>, vector<vector<int>>, cmp2> pq; 
    
    // 모든 작업을 처리하고 큐가 빌 때까지 반복 
    while(i < jobs.size() || !pq.empty()){ 
        // 작업의 요청 시간이 time과 같거나 작은 경우 
        // 큐에 삽입 후 인덱스 증가 
        if(i < jobs.size() && jobs[i][0] <= time){
            pq.push(jobs[i]); 
            i++; 
            continue; 
        }
        
        // 소요 시간이 작은 것부터 처리 
        if(!pq.empty()){
            int req = pq.top().at(0); 
            int taken = pq.top().at(1); 
            time += taken; 
            answer += time - req; 
            pq.pop(); 
        }else{
            // 큐가 비어있다면 다음 작업의 요청 시간으로 time 갱신 
            time = jobs[i][0]; 
        }
    }
    
    return answer / jobs.size(); 
}