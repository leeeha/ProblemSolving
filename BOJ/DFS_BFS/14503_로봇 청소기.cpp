#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue> 
#define MAX 51 
using namespace std; 

int n, m; 
int graph[MAX][MAX]; // 빈칸은 0, 벽은 1 
bool cleaned[MAX][MAX]; // 청소되면 true, 아니면 false 
int cnt = 0; 

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 북 0 동 1 남 2 서 3  
// (d + 2) % 4 -> 후진 방향 체크 

void dfs(int x, int y, int d){ 
	if(!cleaned[x][y]){ 
		cleaned[x][y] = true; 
		cnt++; 
	}
	
	// 바라보는 방향 d를 기준으로 반시계 방향으로 탐색 진행 
	for(int i = 0; i < 4; i++){ 
		int nd = (d + 3 - i) % 4; 
		int nx = x + dx[nd]; 
		int ny = y + dy[nd]; 

		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

		// 청소되지 않은 빈칸을 발견한 경우 
		if(graph[nx][ny] == 0 && !cleaned[nx][ny]){ 
			// 방향을 회전하여 한칸 전진한다. 
			dfs(nx, ny, nd); 
		} 
	}

	// 주변 4칸 중에 청소되지 않은 빈칸이 없는 경우, 후진 가능 여부 탐색 
	int back = (d + 2) % 4; 
	int bx = x + dx[back]; 
	int by = y + dy[back]; 

	// 범위를 벗어나거나 벽을 마주치면 작동을 멈춘다. 
	if(bx < 0 || bx >= n || by < 0 || by >= m || graph[bx][by] == 1) {
		cout << cnt; 
		exit(0); 
	}
	
	// 방향 유지한 채로 한칸 후진하고 다시 탐색을 진행한다. 
	dfs(bx, by, d);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 

	int r, c, d; 
	cin >> r >> c >> d;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> graph[i][j]; 
		}
	}

	// 작동을 멈추지 않고 한번에 청소할 수 있는 칸의 최대 개수를 구하자. 
	dfs(r, c, d);
	
    return 0;
}