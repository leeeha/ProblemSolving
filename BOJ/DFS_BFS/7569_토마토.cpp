    #include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
#include <cstring> 
#include <queue> 
using namespace std;
typedef pair<int, int> pii; 

const int MAX = 101; 
int m, n, h; // 열, 행, 높이 
int graph[MAX][MAX][MAX]; // 높이(z), 행(x), 열(y)
queue<pair<int, pii>> q; // 1의 좌표 {z, {x, y}}

int dx[] = {-1, 1, 0, 0, 0, 0}; 
int dy[] = {0, 0, -1, 1, 0, 0};  
int dz[] = {0, 0, 0, 0, -1, 1};

void bfs() {
	while(!q.empty()){
		// 1을 하나씩 꺼내서 
		int z = q.front().first; 
		int x = q.front().second.first; 
		int y = q.front().second.second; 
		q.pop(); 

		// 상하좌우, 위아래에 0이 있는지 탐색한다.  
		for(int i = 0; i < 6; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue; 

			// 0을 발견할 때까지 걸린 시간을 해당 위치에 저장 
			if(graph[nz][nx][ny] == 0){ 
				graph[nz][nx][ny] = graph[z][x][y] + 1; 

				// 0에서 1로 물든 토마토의 위치를 큐에 저장 
				q.push({nz, {nx, ny}}); 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> m >> n >> h;

	for(int i = 0; i < h; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				cin >> graph[i][j][k];
				
				if(graph[i][j][k] == 1){
					q.push({i, {j, k}});
				}
			}
		}
	}

	bfs(); 

	int ans = 0; 

	for(int i = 0; i < h; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(graph[i][j][k] == 0){
					cout << "-1\n"; 
					return 0; 
				}

				if(ans < graph[i][j][k]){
					ans = graph[i][j][k]; 
				}
			}
		}
	}
			
	cout << ans - 1; 
	
	return 0;
}
