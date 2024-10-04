#include <string>
#include <vector>
#include <queue>
#define MAX 201
using namespace std;

bool visited[MAX]; 
vector<int> graph[MAX];

void dfs(int x){
    visited[x] = true; 
    
    for(int i = 0; i < graph[x].size(); i++){
        int y = graph[x][i];
        if(!visited[y]){ 
            dfs(y); 
        }
    }
}

void bfs(int start){
    queue<int> q; 
    q.push(start);
    visited[start] = true; 
    
    while(!q.empty()){
        int x = q.front(); 
        q.pop(); 
        
        for(int i = 0; i < graph[x].size(); i++){
            int y = graph[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true; 
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[i].size(); j++){
            if(computers[i][j] == 1){ 
                graph[i].push_back(j); 
                graph[j].push_back(i); 
            }
        }
    }
    
    int cnt = 0; 
    for(int i = 0; i < computers.size(); i++){
        if(!visited[i]){ 
            cnt++; 
            bfs(i); 
        } 
    }
    
    return cnt;
}