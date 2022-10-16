#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
#include <utility> 
#define MAX 1001 
using namespace std;
typedef pair<int, int> pii; 

int m, n; 
int graph[MAX][MAX]; // 0으로 초기화 
queue<pii> q; // 1의 위치 저장 

int dy[] = {-1, 1, 0, 0}; // 행 
int dx[] = {0, 0, -1, 1}; // 열 
int result = 0; 

void bfs(){
	while(!q.empty()){
		int y = q.front().first;  // 행 
		int x = q.front().second; // 열 
		q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny >= 0 && ny < n && nx >= 0 && nx < m){
				if(graph[ny][nx] == 0){
					// 해당 칸에 도달할 때까지 걸린 시간 저장 
					graph[ny][nx] = graph[y][x] + 1; 
					
					// 0을 1로 물들이기 (큐에 저장)
					q.push({ny, nx});
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n; // m x n 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> graph[i][j]; 

			// 1의 위치를 큐에 저장 
			if(graph[i][j] == 1){ 
				q.push({i, j}); 
			}
		}
	}

	bfs(); 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j] == 0){
				printf("-1\n");
				return 0; 
			}

			if(result < graph[i][j]){
				result = graph[i][j]; // 최댓값 저장 
			}
		}
	}

	// 첫째날에 익게 된 0의 위치에 
	// 1+1이 저장되니까 출력할 때는 -1을 해줘야 한다. 
	cout << result - 1; 
	
	return 0; 
}