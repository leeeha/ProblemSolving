// Sol1. set으로 숫자의 종류를 구해서 개수 세기 
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int n = progresses.size(); 
    vector<int> v; 
    
    // 각 기능별 필요한 개발 기간 구하기 
    for(int i = 0; i < n; i++){
        int quotient = (100 - progresses[i]) / speeds[i]; 
        if((100 - progresses[i]) % speeds[i] == 0){
            v.push_back(quotient);
        }else if((100 - progresses[i]) < speeds[i]){
            v.push_back(1);
        }else{
            v.push_back(quotient + 1); 
        }
    }
    
    // 자신의 뒤쪽에 더 작은 수를 발견하면 큰 수로 대체 
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i] > v[j]) v[j] = v[i]; 
        }
    }
    
    // ex) 5 10 10 10 20 20 -> 5 10 20 
    set<int> s(v.begin(), v.end());
    
    // 각 숫자의 개수 구하기 
    // 5  - 1
    // 10 - 3 
    // 20 - 2 
    for(auto first: s){
        int cnt = 0; 
        for(auto second: v){
            if(first == second) cnt++; 
        }
        answer.push_back(cnt); 
    }
    
    return answer;
}

// Sol2. 큐에서 꺼내면서 개수 세기 
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int n = progresses.size(); 
    queue<int> q; 
    
    for(int i = 0; i < n; i++){
        int temp = (100 - progresses[i]) % speeds[i]; 
        if(temp == 0){
            q.push((100 - progresses[i]) / speeds[i]);
        }else if((100 - progresses[i]) < speeds[i]){
            q.push(1);
        }else{
            q.push((100 - progresses[i]) / speeds[i] + 1); 
        }
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int cnt = 1;  

        // 자신과 같거나 작은 수를 발견하면 큐에서 꺼낸다.
        while(cur >= q.front() && !q.empty()) {
            q.pop();
            cnt++; // 큐에서 꺼낸 원소의 개수 카운트 (배포한 기능의 개수)
        }

        answer.push_back(cnt);
    }
    
    return answer;
}