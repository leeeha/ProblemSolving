#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int n, m;
int graph[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int cnt = 0;

int bfs(int x, int y){
    queue<pair<int, int>> q; 
    q.push({x, y}); 
    visited[x][y] = true; 
    
    while(!q.empty()){
        int r = q.front().first; 
        int c = q.front().second; 
        q.pop(); 
        
        if(r == n - 1 && c == m - 1){  
            return graph[r][c]; 
        }
        
        // 큐에서 꺼낸 원소의 상하좌우 위치 탐색 
        for(int i = 0; i < 4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

            // 벽이 없으면서 방문하지 않은 칸인 경우 
            if(graph[nx][ny] == 1 && !visited[nx][ny]){ 
                graph[nx][ny] = graph[r][c] + 1; 
                visited[nx][ny] = true; 
                q.push({nx, ny});
            }
        }
    }
    
    return -1; 
}

int solution(vector<vector<int>> maps)
{
    n = maps.size(); 
    m = maps[0].size(); 
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            graph[i][j] = maps[i][j];
        }
    }
    
    return bfs(0, 0); 
}