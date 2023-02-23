#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue> 
#define MAX 101 
using namespace std;

int n; 
int graph[MAX][MAX]; 
bool visited[MAX][MAX]; 
vector<int> result; 

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y, int h){
	// 방문 처리 
	visited[x][y] = true; 

	// 인접한 상하좌우 탐색 
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 범위 체크 
		if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 

		// 높이가 h보다 크면서 방문하지 않은 경우 
		if(graph[nx][ny] > h && !visited[nx][ny]){ 
			dfs(nx, ny, h); 
		} 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 

	// 각 지역의 높이 입력 받기 (1 이상 100 이하)
	int maxHeight = -1; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j]; 
			maxHeight = max(maxHeight, graph[i][j]);
		} 
	} 
	
	for(int h = 1; h < maxHeight; h++){ 
		// DFS/BFS 탐색으로 안전 영역의 개수 구하기 
		int cnt = 0; 
		for(int i = 0; i < n; i++){ 
			for(int j = 0; j < n; j++){ 
				// 높이가 h보다 크면서 방문하지 않은 경우 
				if(graph[i][j] > h && !visited[i][j]){ 
					cnt++; 
					dfs(i, j, h); 
				}
			}
		}
		result.push_back(cnt); 

		// 데이터 초기화 
		memset(visited, 0, sizeof(visited)); 
	}

	int maxCount = *max_element(result.begin(), result.end()); 
	cout << maxCount; 
	
    return 0;
}
