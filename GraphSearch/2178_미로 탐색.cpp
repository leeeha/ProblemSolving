#include <iostream>
#include <queue>
#include <utility> // pair
using namespace std;

int n, m; // n행 m열 
int graph[101][101]; 

// 이동할 네 가지 방향 정의 (상하좌우: x는 행, y는 열)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int x, int y){
	queue<pair<int, int>> q; 
	q.push({x, y});

	// 큐가 빌 때까지 반복
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 현재 위치에서 상하좌우로 이동 가능한지 확인 
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 미로 공간을 벗어난 경우 무시
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// 갈 수 없는 길인 경우 무시
			if(graph[nx][ny] == 0) continue;

			// 방문한 적 없는 노드인 경우 
			if(graph[nx][ny] == 1){
				// 현재 노드까지 이동한 최소 칸 수 업데이트!
				graph[nx][ny] = graph[x][y] + 1;
				
                // 다음 노드 처리하도록 큐에 좌표 저장하기 
				q.push({nx, ny}); 
			}
		}
	}

	// (n, m) 지점까지의 최단 거리 반환
	return graph[n - 1][m - 1];
}

int main()
{	
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &graph[i][j]);
		}
	}

	cout << bfs(0, 0) << "\n";

	return 0;
}