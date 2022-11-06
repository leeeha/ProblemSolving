#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm> 
#include <utility>
#include <cstring> // memset 
#define MAX 50 
using namespace std;

int w, h;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int numberOfLand = 0; 

// 상 하 좌 우 , 우상 우하 좌상 좌하 
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 }; 
int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 }; 

void bfs(int y, int x){
	queue<pair<int,int>> q; 
	q.push({y, x}); // 행, 열 
	visited[y][x] = true;

	while(!q.empty()){
		y = q.front().first; 
		x = q.front().second; 
		q.pop();

		// 해당 위치의 8방면을 확인 
		for(int i = 0; i < 8; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 현재 지도 크기를 벗어나지 않고 
			if(0 <= ny && ny < h && 0 <= nx && nx < w){
				// 아직 방문하지 않은 땅이라면 
				if(graph[ny][nx] == 1 && !visited[ny][nx]){ 
					// 방문 처리 
					visited[ny][nx] = true;  
					q.push({ny, nx}); 
				}
			}
		}
	}
}

void dfs(int y, int x){
	visited[y][x] = true;

	for(int i = 0; i < 8; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(0 <= ny && ny < h && 0 <= nx && nx < w){
			if(graph[ny][nx] == 1 && !visited[ny][nx]){
				visited[ny][nx] = true;
				dfs(ny, nx); 
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(true){
		cin >> w >> h; 
		if(w == 0 && h == 0) 
			break; 

		for(int i = 0; i < h; i++){ // 높이가 행 
			for(int j = 0; j < w; j++){ // 너비가 열  
				cin >> graph[i][j]; 
			}
		}

		// 그래프 탐색 
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(graph[i][j] == 1 && !visited[i][j]){
					// 연결 요소의 개수 카운팅 
					numberOfLand++; 

					// 이 함수가 다시 호출되면 서로 끊어진 섬이 있다는 것 
					bfs(i, j); 
					//dfs(i, j); 
				}
			}
		}
		
		// 섬의 개수 출력
		cout << numberOfLand << "\n"; 

		// 그 다음 테스트 케이스를 위해 데이터 초기화 
		memset(graph, 0, sizeof(graph));
		memset(visited, false, sizeof(visited));
		numberOfLand = 0;
	}
	
	return 0;
}


