#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
#define MAX 301
using namespace std;
typedef pair<int, int> pii; 

int n; 
bool visited[MAX][MAX]; 
int graph[MAX][MAX];

int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,-2,-1,1,2};

void bfs(pii start, pii end){
	int x = start.first;
	int y = start.second; 
	
	queue<pii> q; 
	q.push({x, y}); 
	visited[x][y] = true; 

	while(!q.empty()){
		int r = q.front().first; 
		int c = q.front().second; 
		q.pop(); 

		if(r == end.first && c == end.second){ 
			cout << graph[r][c] << "\n"; 
			break; 
		}

		for(int i = 0; i < 8; i++){
			int nx = r + dx[i]; 
			int ny = c + dy[i]; 

			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 
			
			if(!visited[nx][ny]){
				q.push({nx, ny});
				visited[nx][ny] = true; 
				graph[nx][ny] = graph[r][c] + 1; 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int t; 
	cin >> t; 

	while(t--){ 
		cin >> n; 
	
		pii start, end; 
		cin >> start.first >> start.second; 
		cin >> end.first >> end.second; 
	
		bfs(start, end); 

		memset(visited, false, sizeof(visited));
		memset(graph, 0, sizeof(graph));
	}

    return 0;
}

