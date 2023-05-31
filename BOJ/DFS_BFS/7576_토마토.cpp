#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
#include <cstring> 
#include <queue> 
using namespace std;

const int MAX = 1001; 
int m, n; 
int graph[MAX][MAX];
queue<pair<int, int>> q; // 1의 좌표  

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs() {
	while(!q.empty()){
		// 1의 위치를 하나씩 꺼내서 
		int x = q.front().first;
		int y = q.front().second;
		q.pop(); 

		// 상하좌우에 0이 있는지 탐색한다. 
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

			// 0을 발견할 때까지 걸린 시간을 해당 위치에 저장 
			if(graph[nx][ny] == 0){ 
				graph[nx][ny] = graph[x][y] + 1; 

				// 0에서 1로 물든 토마토의 위치를 큐에 저장 
				q.push({nx, ny}); 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> m >> n; // n x m 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){ 
			cin >> graph[i][j]; 

			// 1의 위치 저장 
			if(graph[i][j] == 1){
				q.push({i, j}); 
			}
		}
	}

	bfs(); 

	int ans = 0; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j] == 0){
				cout << "-1\n";
				return 0; 
			}

			if(ans < graph[i][j]){
				ans = graph[i][j]; 
			}
		}
	}

	// 최댓값에서 1을 빼면 정답 
	cout << ans - 1; 
	
	return 0;
}