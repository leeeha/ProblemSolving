#include <iostream>
#include <queue>
#include <utility> // pair

#define MAX 1000
using namespace std;

int n, m; // n행 m열 

// 입력으로 들어오는 맵 정보 저장  
int graph[MAX][MAX];

// 벽 파괴 여부에 따라 달라지는 최단 거리를 따로 저장
int count[MAX][MAX][2]; // 0은 unbroken, 1은 broken 

// 상하좌우 탐색 (행은 x축 방향, 열은 y축 방향)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// 가까운 노드부터 먼저 탐색하는 BFS 
int bfs(int x, int y){
	// { {x,y}, broken }
	queue<pair<pair<int, int>, bool>> q;
	q.push({{x, y}, false});
	count[x][y][0] = 1; // 벽을 부수지 않은 상태(0)의 최단 거리를 1로 초기화
	
	// 큐가 빌 때까지 반복! 
	while(!q.empty()){ 
		auto Q = q.front();
		int x = Q.first.first;
		int y = Q.first.second;
		bool broken = Q.second;
		q.pop();

		// (n, m) 지점까지 도달하면, 현재 broken 상태에 따른 최단 거리 리턴!
		if(x == n - 1 && y == m - 1){
			return count[x][y][broken];
		}

		// BFS: 상하좌우로 이동할 수 있는지 탐색 
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 맵의 범위를 벗어난 경우 무시
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// 벽을 만났는데, 아직 벽을 한번도 부수지 않은 경우 
			if(graph[nx][ny] == 1 && broken == false){
            	// 벽을 부순 상태(1)의 최단 거리 업데이트
				count[nx][ny][1] = count[x][y][0] + 1;
                
				// 다음 원소의 broken 상태를 true로 변경!
				q.push({{nx, ny}, true});
			}
			// 벽이 없고, 한번도 방문하지 않은 곳이라면  
			else if(graph[nx][ny] == 0 && count[nx][ny][broken] == 0){
            	// 최단 거리 업데이트 
				count[nx][ny][broken] = count[x][y][broken] + 1;
                
            	// 다음 위치로 이동 (broken 상태는 그대로)
				q.push({{nx,ny}, broken}); 
			}
		}
	}
	
	return -1;
}

int main()
{	
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &graph[i][j]);
		}
	}

	/** 문자열로 입력 받는 방식 
	for (int i = 0; i < n; i++){
        string s;
        cin >> s;

		// char to int 
        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j] - '0';
        }
    }
	*/

	cout << bfs(0, 0) << "\n";

	return 0;
}