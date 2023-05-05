#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue> 
#define MAX 301
using namespace std; 
typedef pair<int, int> pii; 

int n, m; 
int graph[MAX][MAX]; 
bool visited[MAX][MAX];
vector<pii> iceberg; // 빙산의 위치  
vector<int> zero; // 각 빙산에 인접한 0의 개수 
int year = 0; // 2개 이상의 덩어리로 분리될 때까지 걸린 시간 

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void input() {
	cin >> n >> m; 

	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < m; j++){ 
			cin >> graph[i][j];
			
			if(graph[i][j] != 0){
				// 빙산의 위치 저장 
				iceberg.push_back({i, j}); 
			}
		}
	}
}

bool isEmpty() {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j] != 0) return false; 
		}
	}
	return true; 
}

void countAdjacentZero(){
	for(int i = 0; i < iceberg.size(); i++){
		int cnt = 0; 
		int x = iceberg[i].first; 
		int y = iceberg[i].second; 

		// 각 빙산의 상하좌우 탐색
		for(int i = 0; i < 4; i++){ 
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 

			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

			if(graph[nx][ny] == 0){ 
				cnt++; 
			}
		}
		
		zero.push_back(cnt); 
	}
}

void updateIcebergHeight(){
	for(int i = 0; i < iceberg.size(); i++){ 
		int x = iceberg[i].first; 
		int y = iceberg[i].second; 

		// 빙산의 높이 갱신 (0보다 줄어들지 않는다.)
		if(graph[x][y] < zero[i]){ 
			graph[x][y] = 0; 
		}else{
			graph[x][y] -= zero[i]; 
		}
	}
}

void dfs(int x, int y){
	visited[x][y] = true; 

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

		if(graph[nx][ny] != 0 && !visited[nx][ny]){
			dfs(nx, ny); 
		} 
	}
}

int countIcebergSet(){ 
	int num = 0; 
	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < m; j++){
			if(graph[i][j] != 0 && !visited[i][j]){ 
				num++;
				dfs(i, j);
			}
		}
	}
	return num; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	// 빙산이 다 녹을 때까지 반복해야 하는 동작은? 
	// 1. 각 빙산에 인접한 0의 개수를 저장한다. (zero 배열 -> 초기화)
	// 2. 빙산의 높이와 경과 시간을 갱신한다. (graph 배열 -> 누적) 
	// 3. 빙산 덩어리가 몇개인지 검사한다. (visited 배열 -> 초기화) 

	while(!isEmpty()){ 
		countAdjacentZero(); 

		updateIcebergHeight(); 

		year++; 

		int num = countIcebergSet(); 
		if(num >= 2) { 
			cout << year; 
			return 0; 
		}
		
		zero.clear(); 
		memset(visited, 0, sizeof(visited)); 
	}

	cout << "0"; 
	
    return 0;
}