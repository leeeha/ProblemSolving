#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1000001;
vector<int> graph[MAX];
int indegree[MAX];
int outdegree[MAX];
int t0, t1, t8; // 도넛, 막대, 8자형

void classifyGraph(int start){
    queue<int> q;
    q.push(start);
    bool cycle = false; 
    
    while(!q.empty()){
        int now = q.front(); 
        q.pop(); 
        
        // 시작 정점으로 다시 돌아오면 도넛 모양 
        if(now == start && cycle){
            t0++; 
            return; 
        }
        
        // 진출 차수가 2이면 8자형 
        if(graph[now].size() == 2){
            t8++; 
            return; 
        }
        
        for(auto adjNum: graph[now]){
            q.push(adjNum);
        }
        
        cycle = true; 
    }
    
    t1++; // 더 이상 탐색 불가능하면 막대 모양 
    return; 
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
     for(auto edge: edges){
         int a = edge[0];
         int b = edge[1];
         graph[a].push_back(b);
         
         // a에서 b로 들어가는 간선
         outdegree[a]++;
         indegree[b]++;
    }
    
    vector<int> tmp; 
    for(auto edge: edges){
        for(auto num: edge){
            tmp.push_back(num);
        }
    }
    
    int N = *max_element(tmp.begin(), tmp.end());
    
    // 탐색 시작 노드: 진입 0, 진출 >= 2
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0 && outdegree[i] >= 2){
            answer.push_back(i);
        }
    }
    
    // start 정점과 연결된 노드 탐색 
    int start = answer[0];
    for(auto node: graph[start]){
        classifyGraph(node);
    }
    
    answer.push_back(t0);
    answer.push_back(t1);
    answer.push_back(t8);
    
    return answer;
}