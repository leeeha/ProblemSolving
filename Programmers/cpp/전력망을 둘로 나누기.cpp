#include <string>
#include <vector>
#include <cstring>
#include <iostream> 
#include <cmath> 
using namespace std;

const int MAX = 101; 
bool visited[MAX]; 
vector<int> graph[MAX]; 
int nodeNum = 0; // 한 전력망에 있는 노드 개수 

void dfs(int x){
    visited[x] = true;
    nodeNum++;
    
    for(int i = 0; i < graph[x].size(); i++){ 
        int y = graph[x][i]; 
        if(!visited[y]) dfs(y); 
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9; 
    
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            // i번째 간선 제외하고 
            if(j == i) continue; 

            // 노드 양방향 연결 
            int a = wires[j][0]; 
            int b = wires[j][1]; 
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // 2개의 전력망 사이의 노드 개수 차이 구하기 
        dfs(1);
        int diff = abs((n - nodeNum) - nodeNum);
        nodeNum = 0;
        
        if(answer > diff){ 
            answer = diff; 
        }
        
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= n; i++){ 
            graph[i].clear(); 
        }
    }

    return answer;
}